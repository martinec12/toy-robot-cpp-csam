#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

//class Robot;

#include "Robot.hpp"
#include "Point.hpp"

class ICommand
{
public:
    virtual ~ICommand(){}
    virtual void execute() const = 0;
};

// For the following concrete commands the doer of commands is a robot

class PlaceCommand : public ICommand
{
public:
    PlaceCommand(Robot robot, Point destination, Direction newDirection);
    Point getDeployPosition();
    Direction getDeployDirection();
    void execute() const;

private:
    Robot &mRobot;
    Point mDeployPosition;
    Direction mDeployDirection;
};

class MoveCommand : public ICommand
{
public:
    MoveCommand(Robot robot);
    void execute() const;
private:
    Robot &mRobot;
};

class LeftCommand : public ICommand
{
public:
    LeftCommand(Robot robot);
    void execute() const;
private:
    Robot &mRobot;
};

class RightCommand : public ICommand
{
public:
    RightCommand(Robot robot);
    void execute() const;
private:
    Robot &mRobot;
};

class ReportCommand : public ICommand
{
public:
    ReportCommand(Robot robot);
    void execute() const;
private:
    Robot &mRobot;
};

#endif // _COMMAND_HPP_
