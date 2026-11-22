#pragma once

#include <frc2/command/CommandHelper.h>
#include "RobotControlData.h"
#include "HAL/ElevatorHAL.h"
#include <frc/Timer.h>


class Intaking : public frc2::CommandHelper<frc2::Command, Intaking>
{
    public:
        explicit Intaking(RobotControlData& data);
        ~Intaking() = default;

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:
        RobotControlData& m_robotControlData;
        frc::Timer m_timer;
        const double k_IntakeDuration = 0.2;
        //Elevator el;
};