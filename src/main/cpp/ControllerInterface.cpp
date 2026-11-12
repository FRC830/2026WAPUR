#include "ControllerInterface.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
#include <string>

void ControllerInterface::UpdateRobotControlData(RobotControlData &controlData) {
    UpdateSwerveInput(controlData);
    UpdatePigeonInput(controlData);
    UpdateClawInput(controlData);
    UpdateStates(controlData);
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
#include <iostream>
void ControllerInterface::UpdateClawInput(RobotControlData &controlData)
{
    if (controlData.states.Scoring) {

        controlData.clawInput.ClawState = -1;
        std::cout << "Scoring" << std::endl;

    } else if (controlData.states.Intaking){

        controlData.clawInput.ClawState = 1;
        std::cout << "Intaking" << std::endl;
    } else {
        controlData.clawInput.ClawState = 0;
        std::cout << "Idle" << std::endl;
    }
    
}


void ControllerInterface::UpdateStates(RobotControlData &controlData)
{
    
    if (m_copilot.GetRightBumper()) // Intaking
    {
        controlData.states.Intaking = true; // Ensure Intaking is false when Launching is toggled
        controlData.states.Scoring = false; // Ensure Scoring is false when Launching is toggled
        std::cout << "Intaking" << std::endl;
    } else if (m_copilot.GetLeftBumper()) { // Scoring
        controlData.states.Intaking = false; // 
        controlData.states.Scoring = true; // Ensure Scoring is false when Launching is toggled
        std::cout << "Scoring" << std::endl;
    } 
    else
    {
        controlData.states.Intaking = false;
        controlData.states.Scoring = false;
        std::cout << "idle:" << std::endl;
    }
    std::cout << "got in update state" << std::endl;
}