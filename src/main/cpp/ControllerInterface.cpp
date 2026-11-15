#include "ControllerInterface.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
#include <string>

void ControllerInterface::UpdateRobotControlData(RobotControlData &controlData) {
    UpdateSwerveInput(controlData);
    UpdatePigeonInput(controlData);
    UpdateClawInput(controlData);
    UpdateElevatorInput(controlData);
    UpdateStates(controlData);

    frc::SmartDashboard::PutString("Current State", controlData.states.Scoring ? "Scoring" : (controlData.states.Intaking ? "Intaking" : "Idle"));
    frc::SmartDashboard::PutString("Elevator Level", controlData.states.Level1 ? "Level 1" : (controlData.states.Level2 ? "Level 2" : (controlData.states.Level3 ? "Level 3" : (controlData.states.Level4 ? "Level 4" : "Level 0"))));
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
void ControllerInterface::UpdateElevatorInput(RobotControlData &controlData)
{
    if (controlData.states.Level1) {
        controlData.elevatorInput.Level = 1;
        std::cout << "Level 1" << std::endl;
    } else if (controlData.states.Level2) {
        controlData.elevatorInput.Level = 2;
        std::cout << "Level 2" << std::endl;
    } else if (controlData.states.Level3) {
        controlData.elevatorInput.Level = 3;
        std::cout << "Level 3" << std::endl;
    } else if (controlData.states.Level4) {
        controlData.elevatorInput.Level = 4;
        std::cout << "Level 4" << std::endl;
    } else {
        controlData.elevatorInput.Level = 0; // No level selected
        std::cout << "Idle" << std::endl;
    }

    
}
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
    
    if (m_copilot.GetRightBumperButton()) // Intaking
    {
        controlData.states.Intaking = true; // Ensure Intaking is false when Launching is toggled
        controlData.states.Scoring = false; // Ensure Scoring is false when Launching is toggled
        std::cout << "Intaking" << std::endl;
        controlData.states.Level0 = true;
        controlData.states.Level1 = false;
        controlData.states.Level2 = false;
        controlData.states.Level3 = false;
        controlData.states.Level4 = false;
    } else if (m_copilot.GetLeftBumperButton()) { // Scoring
        controlData.states.Intaking = false; // 
        controlData.states.Scoring = true; // Ensure Scoring is false when Launching is toggled
        std::cout << "Scoring" << std::endl;
    } 
    else if (m_copilot.GetAButton()) {
        controlData.states.Level0 = false;
        controlData.states.Level1 = true;
        controlData.states.Level2 = false;
        controlData.states.Level3 = false;
        controlData.states.Level4 = false;
    } 
    else if (m_copilot.GetXButtonPressed()) {
        controlData.states.Level0 = false;
        controlData.states.Level1 = false;
        controlData.states.Level2 = true;
        controlData.states.Level3 = false;
        controlData.states.Level4 = false;
    } 
    else if (m_copilot.GetBButtonPressed()) {
        controlData.states.Level0 = false;
        controlData.states.Level1 = false;
        controlData.states.Level2 = false;
        controlData.states.Level3 = true;
        controlData.states.Level4 = false;
    } 
    else if (m_copilot.GetYButtonPressed()) {
        controlData.states.Level0 = false;
        controlData.states.Level1 = false;
        controlData.states.Level2 = false;
        controlData.states.Level3 = false;
        controlData.states.Level4 = true;
    } 
    else
    {
        controlData.states.Intaking = false;
        controlData.states.Scoring = false;
        std::cout << "idle:" << std::endl;
    }
    
    std::cout << "got in update state" << std::endl;
}