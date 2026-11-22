// #include "cmds/Level1.h"

// Level1::Level1(RobotControlData& data) : m_robotControlData(data)
// {}

// void Level1::Initialize()
// {
//     m_timer.Reset();
//     m_timer.Start();
//     m_robotControlData.states.Level0 = true;
//     m_robotControlData.states.Level1 = false;
//     m_robotControlData.states.Level2 = false;
//     m_robotControlData.states.Level3 = false;
//     m_robotControlData.states.Level4 = false;
// }

// void Level1::Execute()
// {
//     m_robotControlData.states.Level0 = false;
//     m_robotControlData.states.Level1 = true;
//     m_robotControlData.states.Level2 = false;
//     m_robotControlData.states.Level3 = false;
//     m_robotControlData.states.Level4 = false;
// }

// bool Level1::IsFinished()
// {
//     return (m_elevator.IsElevatorAtLevel(1));
// }

// void Level1::End(bool interrupted)
// {
//     m_timer.Stop();
// }