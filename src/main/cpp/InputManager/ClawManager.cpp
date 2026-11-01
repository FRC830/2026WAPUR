#include "InputManager/ClawManager.h"

void ClawManager::HandleInput(RobotControlData &robotControlData)
{   
m_Claw.ClawIntake(robotControlData.clawInput.clawState);
}

void ClawManager::ResetState()
{
    m_Claw.ClawIntake(0); 
}