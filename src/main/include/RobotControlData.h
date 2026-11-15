#pragma once

struct SwerveInput{
    double xTranslation;
    double yTranslation;
    double rotation;

    bool autoTarget;
    bool goFieldOriented;
};

struct ResetPigeon
{
    bool reset;
};

struct States {
    bool Travelling;
    bool Scoring;
    bool Intaking;
    bool Level0;
    bool Level1;
    bool Level2;
    bool Level3;
    bool Level4;
};

struct ClawInput{
    int ClawState;
};

struct ElevatorInput{
    int Level;
};

struct RobotControlData
{
    SwerveInput swerveInput;
    ResetPigeon resetPigeon;
    ClawInput clawInput;
    ElevatorInput elevatorInput;
    States states;
};