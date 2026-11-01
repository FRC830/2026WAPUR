#include "InputManager/ClawManager.h"

void ClawManager::HandleInput(RobotControlData &RobotControlData) {
    m_Claw.ClawIntake(RobotControlData.clawInput.ClawState);  
};

void ClawManager::ResetState() {
    m_Claw.ClawIntake(0);
}