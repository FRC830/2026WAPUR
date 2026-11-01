#include "ControllerInterface.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
#include <string>

void ControllerInterface::UpdateRobotControlData(RobotControlData &controlData)
{
    UpdateSwerveInput(controlData);
    UpdatePigeonInput(controlData);
    UpdateStates(controlData);
    UpdateClawInput(controlData);
}

void ControllerInterface::UpdatePigeonInput(RobotControlData &controlData)
{
    controlData.resetPigeon.reset = m_pilot.GetStartButtonPressed();
}

void ControllerInterface::UpdateClawInput(RobotControlData &controlData)
{
    
    if (controlData.states.Intake)
    {
        controlData.clawInput.clawState = 1; // Intake
    }
    else if (controlData.states.Scoring)
    {
        controlData.clawInput.clawState = -1; // Outtake
    }
    else {
        controlData.clawInput.clawState = 0; // Stop
    }
}

void ControllerInterface::UpdateStates(RobotControlData &controlData)
{
    
    if (m_copilot.GetRightBumperPressed())
    {
        controlData.states.Scoring = !controlData.states.Scoring; 
        controlData.states.Intake = false;
    }
     else if (m_copilot.GetLeftBumperPressed())
    {
        controlData.states.Scoring = false; 
        controlData.states.Intake = !controlData.states.Intake;
    }
}