#include "Robot.hpp"
#include "Command.hpp"

RightCommand::RightCommand(Robot &robot) : mRobot(robot)
{

}

void RightCommand::execute() const
{
    mRobot.right();
}
