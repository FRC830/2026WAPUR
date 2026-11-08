#include "HAL/ElevatorHAL.h"
#include <units/angle.h>
#include <units/angular_velocity.h>

using namespace units::literals; 

Elevator::Elevator() {
    // in init function
    ctre::phoenix6::configs::TalonFXConfiguration talonFXConfigs{};

    // set slot 0 gains
    auto& slot0Configs = talonFXConfigs.Slot0;

    slot0Configs.kP = 4.8; // A position error of 2.5 rotations results in 12 V output
    slot0Configs.kI = 0; // no output for integrated error
    slot0Configs.kD = 0.1; // A velocity error of 1 rps results in 0.1 V outputs
    slot0Configs.kG = 6.7;
    slot0Configs.GravityType = ctre::phoenix6::signals::GravityTypeValue::Elevator_Static;


    // set Motion Magic settings
    auto& motionMagicConfigs = talonFXConfigs.MotionMagic;
    units::angular_velocity::turns_per_second_t temprps{80.0};
    motionMagicConfigs.MotionMagicCruiseVelocity = temprps;// Target cruise velocity of 80 rps
    units::angular_acceleration::turns_per_second_squared_t tempacc{160.0};
    motionMagicConfigs.MotionMagicAcceleration = tempacc; // Target acceleration of 160 rps/s (0.5 seconds)
    units::angular_acceleration::turns_per_second_squared_t tempjerk{1600};
    motionMagicConfigs.MotionMagicJerk = tempjerk; // Target jerk of 1600 rps/s/s (0.1 seconds)

    m_elevatorA.GetConfigurator().Apply(talonFXConfigs);

    m_elevatorB.SetControl(m_followerRequest);
}

void Elevator::MoveElevatorToPos(int level){
    double convert = (level/kSpoolCircumference)*kGearRatio;
    units::angle::turn_t convertrot{convert};
    m_elevatorA.SetControl(m_request.WithPosition(convertrot));
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

bool Elevator::IsElevatorAtLevel(){
    double current = (m_elevatorA.GetPosition().GetValue().value() / kGearRatio) * kSpoolCircumference;
    return level == current;
}