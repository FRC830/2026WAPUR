// #include "cmds/Level3.h"

// Level3::Level3(RobotControlData& data) : m_robotControlData(data)
// {}

// void Level3::Initialize()
// {
//     m_timer.Reset();
//     m_timer.Start();
//     m_robotControlData.states.Level0 = true;
//     m_robotControlData.states.Level3 = false;
//     m_robotControlData.states.Level3 = false;
//     m_robotControlData.states.Level3 = false;
//     m_robotControlData.states.Level4 = false;
// }

// void Level3::Execute()
// {
//     m_robotControlData.states.Level0 = false;
//     m_robotControlData.states.Level3 = true;
//     m_robotControlData.states.Level3 = false;
//     m_robotControlData.states.Level3 = false;
//     m_robotControlData.states.Level4 = false;
// }

// bool Level3::IsFinished()
// {
//     return (m_elevator.IsElevatorAtLevel(3));
// }

// void Level3::End(bool interrupted)
// {
//     m_timer.Stop();
// }