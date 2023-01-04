#include "Robot.hpp"
#include "Command.hpp"

LeftCommand::LeftCommand(Robot &robot) : mRobot(robot)
{

}

void LeftCommand::execute() const
{
    mRobot.left();
}
