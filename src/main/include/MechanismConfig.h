#pragma once

#include <rev/config/SparkMaxConfig.h>
#include "PhotonVisionCamera.h"
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/configs/Configuration.hpp>
#include <ctre/phoenix6/configs/Configurator.hpp>
#include <frc/geometry/Transform3d.h>
#include <frc/geometry/Translation3d.h>
#include <ctre/phoenix6/Configs/MotionMagicConfigs.hpp> // cool

namespace ratbot
{

    const double VOLTAGE_COMPENSATION = 10.5f;
    namespace VisionConfig
    {
        constexpr frc::Transform3d ROBOT_TO_CAMERA = frc::Transform3d{frc::Translation3d(15_in, -4_in, 6_in), frc::Rotation3d(0_rad, 28_deg, 0_rad)};
    }
    namespace MoveToPoseConfig
    {
        // TODO: tune values on carpet
        const double MAX_TURN_SPEED_DEG_PER_SEC = 720.0f;
        const double TURN_FEED_FORWARD_DEG_PER_SEC = 20.0f;
        const double MAX_SPEED_M_PER_SEC = 1.32f; // todo: change!!!
        const double SPEED_FEED_FORWARD_M_PER_SEC = 0.1f; //todo: change!!!!!

        
    }   
    namespace ElevatorConfig
    {
        const double P = 0.0;
        const double I = 0.0;
        const double D = 0.0;
        const double kV = 0.0;
        const double kA = 0.0;
        const double kS = 0.0;
        namespace ElevatorMotionMagicConfig
        {
            const double CRUISE_VELOCITY = 0.0;
            const double ACCELERATION = 0.0;
            const double JERK = 0.0;
        }
    }
    
}