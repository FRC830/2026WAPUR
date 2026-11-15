#include "InputManager/ElevatorManager.h"

void ElevatorManager::HandleInput(RobotControlData &RobotControlData) {
    m_Elevator.MoveElevatorToPos(RobotControlData.elevatorInput.Level);
};

void ElevatorManager::ResetState() {
    // m_Elevator.ResetState();
}