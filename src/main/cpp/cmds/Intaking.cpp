#include "cmds/Intaking.h"
#include "MechanismConfig.h"

Intaking::Intaking(RobotControlData& data) : m_robotControlData(data)
{}

void Intaking::Initialize()
{
    m_timer.Reset();
    m_timer.Start();
    m_robotControlData.states.Intaking = true;
}

void Intaking::Execute()
{
     m_robotControlData.states.Intaking = true;
}

bool Intaking::IsFinished()
{
    return (m_timer.Get() >= (units::time::second_t) k_IntakeDuration);
}

void Intaking::End(bool interrupted)
{
    m_robotControlData.states.Intaking = false;
    m_timer.Stop();
}