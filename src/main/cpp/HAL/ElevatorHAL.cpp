#include "HAL/ElevatorHAL.h"
#include <units/angle.h>
#include <units/angular_velocity.h>

using namespace units::literals; 

Elevator::Elevator() {
    // in init function
    ctre::phoenix6::configs::TalonFXConfiguration talonFXConfigs{};

    // set slot 0 gains
    auto& slot0Configs = talonFXConfigs.Slot0;

    slot0Configs.kP = 0.03; // A position error of 2.5 rotations results in 12 V output
    slot0Configs.kI = 0; // no output for integrated error
    slot0Configs.kD = 0.0; // A velocity error of 1 rps results in 0.1 V outputs
    slot0Configs.kG = 0.0;
    slot0Configs.GravityType = ctre::phoenix6::signals::GravityTypeValue::Elevator_Static;


    // set Motion Magic settings
    auto& motionMagicConfigs = talonFXConfigs.MotionMagic;
    units::angular_velocity::turns_per_second_t temprps{80.0};
    motionMagicConfigs.MotionMagicCruiseVelocity = temprps;// Target cruise velocity of 80 rps
    units::angular_acceleration::turns_per_second_squared_t tempacc{160.0};
    motionMagicConfigs.MotionMagicAcceleration = tempacc; // Target acceleration of 160 rps/s (0.5 seconds)
    units::angular_jerk::turns_per_second_cubed_t tempjerk{1600.0};
    motionMagicConfigs.MotionMagicJerk = tempjerk; // Target jerk of 1600 rps/s/s (0.1 seconds)

    m_elevatorA.GetConfigurator().Apply(motionMagicConfigs);

    m_elevatorB.SetControl(m_followerRequest);
}

#include <iostream>

void Elevator::MoveElevatorToPos(int level){
    units::angle::turn_t convertrot{level0};
    if (level == 1)
    { 
        convertrot = units::angle::turn_t(level1);
    }
    else if (level == 2)
    {
        convertrot = units::angle::turn_t(level2);
    }
    else if (level == 3)
    {
        convertrot = units::angle::turn_t(level3);
    }
    else if (level == 4)
    {
        convertrot = units::angle::turn_t(level4);
    }
    else
    {
        convertrot = units::angle::turn_t(level0);
    }
    
    m_elevatorA.SetControl(m_request.WithPosition(convertrot));
    std::cout << "convertrot " << convertrot.value() << std::endl;
    m_elevatorB.SetControl(ctre::phoenix6::controls::Follower{ELEVATOR_MOTOR_A_ID, ctre::phoenix6::signals::MotorAlignmentValue::Opposed});
    // m_elevatorB.SetControl(ctre::phoenix6::controls::Follower{ELEVATOR_MOTOR_A_ID, ctre::phoenix6::signals::MotorAlignmentValue::Aligned});
}

void Elevator::ToLevel1(){
    MoveElevatorToPos(1); //Placeholder
    level = 1;
}

void Elevator::ToLevel2(){
    MoveElevatorToPos(2); //Placeholder
    level = 2;
}

void Elevator::ToLevel3(){
    MoveElevatorToPos(3); //Placeholder
    level = 3;
}

void Elevator::ToLevel4(){
    MoveElevatorToPos(4); //Placeholder
    level = 4;
}

double Elevator::GetElevatorRot(){
    return m_elevatorA.GetPosition().GetValue().value();
}
double Elevator::GetBElevatorRot(){
    return m_elevatorB.GetPosition().GetValue().value();
}
bool Elevator::IsElevatorAtLevel(int wanted){
    double current = (m_elevatorA.GetPosition().GetValue().value() / kGearRatio) * kSpoolCircumference;
    return wanted == current;
}
