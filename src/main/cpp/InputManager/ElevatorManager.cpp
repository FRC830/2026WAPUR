#include "InputManager/ElevatorManager.h"
#include <frc/smartdashboard/SmartDashboard.h>

void ElevatorManager::HandleInput(RobotControlData &RobotControlData) {
    m_Elevator.MoveElevatorToPos(RobotControlData.elevatorInput.Level);
    frc::SmartDashboard::PutNumber("encoder pos", m_Elevator.GetElevatorRot());
    frc::SmartDashboard::PutNumber("second encoder pos", m_Elevator.GetBElevatorRot());

};

void ElevatorManager::ResetState() {
    // m_Elevator.ResetState();
}