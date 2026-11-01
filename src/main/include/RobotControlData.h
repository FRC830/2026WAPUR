#pragma once
struct States
{
bool Travelling;
bool Intake;
bool Scoring;
};
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
struct ClawInput 
{
    int clawState;
};

struct RobotControlData
{
    SwerveInput swerveInput;
    ResetPigeon resetPigeon;
    States states; 
    ClawInput clawInput;
};

