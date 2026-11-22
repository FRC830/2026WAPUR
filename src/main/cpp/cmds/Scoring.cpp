#include "cmds/Scoring.h"
#include "MechanismConfig.h"

Scoring::Scoring(RobotControlData& data) : m_robotControlData(data)
{}

void Scoring::Initialize()
{
    m_timer.Reset();
    m_timer.Start();
    m_robotControlData.states.Scoring = true;
}

void Scoring::Execute()
{
     m_robotControlData.states.Scoring = true;
}

bool Scoring::IsFinished()
{
    return (m_timer.Get() >= (units::time::second_t) k_ScoringDuration);
}

void Scoring::End(bool interrupted)
{
    m_robotControlData.states.Scoring = false;
    m_timer.Stop();
}