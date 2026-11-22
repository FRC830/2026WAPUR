#pragma once
#include "HAL/ElevatorHAL.h"
#include "RobotControlData.h"

class ElevatorManager {
    public:
        ElevatorManager() = default;
        ~ElevatorManager() = default;
        void ResetState();
        void HandleInput(RobotControlData &robotControlData);
    private:
        Elevator m_Elevator;
};