#pragma once

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/configs/Configuration.hpp>
#include <CanConfig.h>
#include <ctre/phoenix6/controls/MotionMagicVoltage.hpp>
#include <ctre/phoenix6/controls/Follower.hpp>

class ElevatorHAL
{
    public:
        ElevatorHAL() = default;
        ~ElevatorHAL() = default;

        void SetElevatorPosition(double position);
        double GetElevatorPosition();

        double SetLevel1();

        

        
    private:
        ctre::phoenix6::hardware::TalonFX m_elevatorMotorA{ELEVATOR_MOTOR_A_ID}; 
        ctre::phoenix6::hardware::TalonFX m_elevatorMotorB{ELEVATOR_MOTOR_B_ID};

        ctre::phoenix6::controls::MotionMagicVoltage m_request{0_tr};

        ctre::phoenix6::controls::Follower m_followerRequest{ELEVATOR_MOTOR_A_ID, ctre::phoenix6::signals::MotorAlignmentValue::Aligned};

        static constexpr double kSpoolDiameter = 1.5;
        static constexpr double kGearRatio = 10.0;

        static constexpr double kSpoolCircumference =
            kSpoolDiameter * 3.14159265359;
 
        // maximum elevator height
        static constexpr double kMaxHeight = 50.0;


};