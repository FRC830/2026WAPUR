#pragma once

#include <ctre/phoenix6/controls/MotionMagicVoltage.hpp>
#include <ctre/phoenix6/TalonFX.hpp>
#include "CanConfig.h"
#include <ctre/phoenix6/configs/Configuration.hpp>
#include <ctre/phoenix6/controls/Follower.hpp>

class Elevator {
    public:
        Elevator();
        ~Elevator() = default;

        void MoveElevatorToPos(int level);
        bool IsElevatorAtLevel();
        void ToLevel1();
        void ToLevel2();
        void ToLevel3();
        void ToLevel4();

    private:
        ctre::phoenix6::hardware::TalonFX m_elevatorA{ELEVATOR_MOTOR_A_ID};
        ctre::phoenix6::hardware::TalonFX m_elevatorB{ELEVATOR_MOTOR_B_ID};


        ctre::phoenix6::controls::MotionMagicVoltage m_request{0_tr};
        ctre::phoenix6::controls::Follower
            m_followerRequest {
                2, 
                ctre::phoenix6::signals::MotorAlignmentValue::Opposed
            };


        static constexpr double kSpoolDiameter = 1.5;
        static constexpr double kGearRatio = 10.0;
        static constexpr double kSpoolCircumference = kSpoolDiameter * 3.14159265359;

        static constexpr double kMaxHeight = 50.0; 

        int level = 0;


};
