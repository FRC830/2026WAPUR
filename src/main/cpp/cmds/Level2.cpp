// #include "cmds/Level2.h"

// Level2::Level2(RobotControlData& data) : m_robotControlData(data)
// {}

// void Level2::Initialize()
// {
//     m_timer.Reset();
//     m_timer.Start();
//     m_robotControlData.states.Level0 = true;
//     m_robotControlData.states.Level2 = false;
//     m_robotControlData.states.Level2 = false;
//     m_robotControlData.states.Level3 = false;
//     m_robotControlData.states.Level4 = false;
// }

// void Level2::Execute()
// {
//     m_robotControlData.states.Level0 = false;
//     m_robotControlData.states.Level2 = true;
//     m_robotControlData.states.Level2 = false;
//     m_robotControlData.states.Level3 = false;
//     m_robotControlData.states.Level4 = false;
// }

// bool Level2::IsFinished()
// {
//     return (m_elevator.IsElevatorAtLevel(2));
// }

// void Level2::End(bool interrupted)
// {
//     m_timer.Stop();
// }