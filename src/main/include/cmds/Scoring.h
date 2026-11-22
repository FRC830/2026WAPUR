#pragma once

#include <frc2/command/CommandHelper.h>
#include "RobotControlData.h"
#include "HAL/ElevatorHAL.h"
#include <frc/Timer.h>


class Scoring : public frc2::CommandHelper<frc2::Command, Scoring>
{
    public:
        explicit Scoring(RobotControlData& data);
        ~Scoring() = default;

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:
        RobotControlData& m_robotControlData;
        frc::Timer m_timer;
        const double k_ScoringDuration = 0.2;
        //Elevator el;
};