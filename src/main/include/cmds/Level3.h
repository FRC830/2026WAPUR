// #pragma once

// #include <frc2/command/CommandHelper.h>
// #include "RobotControlData.h"
// #include "HAL/ElevatorHAL.h"
// #include <frc/Timer.h>
// #include "MechanismConfig.h"

// class Level3 : public frc2::CommandHelper<frc2::Command, Level3>
// {
//     public:
//         explicit Level3(RobotControlData& data, Elevator& elevator);
//         ~Level3() = default;

//         void Initialize() override;
//         void Execute() override;
//         bool IsFinished() override;
//         void End(bool interrupted) override;

//     private:
//         RobotControlData& m_robotControlData;
//         frc::Timer m_timer;
//         const double k_Level3Duration = 0.2;
//         Elevator& m_elevator;
// };