#pragma once

#include <frc2/command/CommandHelper.h>
#include "RobotControlData.h"
#include "HAL/ElevatorHAL.h"
#include <frc/Timer.h>
#include "MechanismConfig.h"

class Level2 : public frc2::CommandHelper<frc2::Command, Level2>
{
    public:
        explicit Level2(RobotControlData& data);
        ~Level2() = default;

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:
        RobotControlData& m_robotControlData;
        frc::Timer m_timer;
                const double k_Level2Duration = 0.2;
        Elevator m_elevator;
};