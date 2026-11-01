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
};

struct ClawInput{
    int ClawState;
};

struct RobotControlData
{
    SwerveInput swerveInput;
    ResetPigeon resetPigeon;
    ClawInput clawInput;
    States states;
};