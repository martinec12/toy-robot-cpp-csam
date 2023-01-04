#include "Robot.hpp"
#include "Command.hpp"

ReportCommand::ReportCommand(Robot &robot) : mRobot(robot)
{

}

void ReportCommand::execute() const
{
    mRobot.report();
}
