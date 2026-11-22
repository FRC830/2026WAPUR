#include "HAL/ElevatorHAL.h"

using namespace ctre::phoenix6; // this basically says 'everything after this, assume it has 'ctre::phoenix6::' in front of it, so we don't have to type it out every time'

ElevatorHAL::ElevatorHAL() {

    // 1 configure leader

    configs::TalonFXConfiguration configs;

    // proportional integral derivative PID
    configs.Slot0.kP = 5.0;
    configs.Slot0.kI = 0.0;
    configs.Slot0.kD = 0.1;

    // gravity feedforward
    configs.Slot0.kG = 1.0; // example 1 volt to counteract gravity (g is for gravity :brain: )

    configs.Slot0.GravityType = 
        signals::GravityTypeValue::Elevator_Static; // this says its linear gravity

    // motion magic
    configs.MotionMagic.MotionMagicCruiseVelocity = 50.0;
    configs.MotionMagic.MotionMagicAcceleration = 100.0;
    configs.MotionMagic.MotionMagicJerk = 1000.0;

    // apply configuration
    m_elevatorMotorA.GetConfigurator().Apply(configs);


    // 2. zero encoder

    // void ElevatorHAL::ZeroEncoder() {
    //     m_elevatorMotorA.SetPosition(0_tr);
    // }


    // move to height

    




    // preset heights

    
}

void ElevatorHAL::SetElevatorPosition(double position) {
        
        // restrict target height
        inches = std::clamp(inches, 0.0, kMaxHeight);

        // convert inchest to motor rotations
        double rotations = 
            (inches / kSpoolCircumference) * kGearRatio;

        // motion magic request command
        m_elevatorMotorA.SetControl(
            m_motionMagic.WithPosition(rotations)
        );
    }

    void ElevatorHAL::SetLevel1() {
        SetHeight(10.0);
    }

    void ElevatorHAL::SetLevel2() {
        SetHeight(25.0);
    }

    void ElevatorHAL::SetLevel3() {
        SetHeight(40.0);
    }


    // get current height
    double ElevatorHAL::GetHeight() {
        
        double rotations = 
            m_motor.GetPosition().GetValueAsDouble();

        return (rotations / kGearRatio) * kSpoolCircumference;
    }


    // stop motor
    
    void ElevatorHAL::Stop() {
        m_motor.StopMotor();
    }