#pragma once

#include <frc2/command/CommandHelper.h>
#include "RobotControlData.h"
#include "HAL/ElevatorHAL.h"
#include <frc/Timer.h>
#include "MechanismConfig.h"


class Level1 : public frc2::CommandHelper<frc2::Command, Level1>
{
    public:
        explicit Level1(RobotControlData& data);
        ~Level1() = default;

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:
        RobotControlData& m_robotControlData;
        frc::Timer m_timer;
        const double k_Level1Duration = 0.2;
        
        Elevator m_elevator;
};