#include "ControllerInterface.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
#include <string>

void ControllerInterface::UpdateRobotControlData(RobotControlData &controlData) {
    UpdateStates(controlData);
    UpdateSwerveInput(controlData);
    UpdatePigeonInput(controlData);
    UpdateClawInput(controlData);

}

void ControllerInterface::UpdateSwerveInput(RobotControlData &controlData)
{  
    
    controlData.swerveInput.xTranslation = -m_pilot.GetLeftY();
    controlData.swerveInput.yTranslation = -m_pilot.GetLeftX();
    controlData.swerveInput.rotation = -m_pilot.GetRightX();    
}

void ControllerInterface::UpdatePigeonInput(RobotControlData &controlData)
{
    controlData.resetPigeon.reset = m_pilot.GetStartButtonPressed();
}

void ControllerInterface::UpdateClawInput(RobotControlData &controlData)
{
    if (controlData.states.Scoring) {

        controlData.clawInput.ClawState = -1;

    } else if (controlData.states.Intaking){

        controlData.clawInput.ClawState = 1;

    } else {
        controlData.clawInput.ClawState = 0;
    }
    
}
void ControllerInterface::UpdateStates(RobotControlData &controlData)
{
    
    if (m_copilot.GetRightBumperPressed()) // Travelling
    {
        controlData.states.Intaking = false; // Ensure Intaking is false when Launching is toggled
        controlData.states.Scoring = !controlData.states.Scoring; // Ensure Scoring is false when Launching is toggled
    } else if (m_copilot.GetLeftBumperPressed()) {
        controlData.states.Intaking = !controlData.states.Intaking; // 
        controlData.states.Scoring = false; // Ensure Scoring is false when Launching is toggled
    } 
}