#include "HAL/ClawHAL.h"

void Claw::ClawIntake(int dir){
    m_clawMotorA.Set(dir*m_speed);
    m_clawMotorB.Set(-dir*m_speed);
}