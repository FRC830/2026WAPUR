// #include "cmds/Level4.h"

// Level4::Level4(RobotControlData& data, Elevator& elevator) : m_robotControlData(data), m_elevator(elevator)
// {}

// void Level4::Initialize()
// {
//     m_timer.Reset();
//     m_timer.Start();
//     m_robotControlData.states.Level0 = true;
//     m_robotControlData.states.Level4 = false;
//     m_robotControlData.states.Level4 = false;
//     m_robotControlData.states.Level4 = false;
//     m_robotControlData.states.Level4 = false;
// }

// void Level4::Execute()
// {
//     m_robotControlData.states.Level0 = false;
//     m_robotControlData.states.Level4 = true;
//     m_robotControlData.states.Level4 = false;
//     m_robotControlData.states.Level4 = false;
//     m_robotControlData.states.Level4 = false;
// }

// bool Level4::IsFinished()
// {
//     return (m_elevator.IsElevatorAtLevel(4));
// }

// void Level4::End(bool interrupted)
// {
//     m_timer.Stop();
// }