#include "Robot.hpp"
#include "Point.hpp"
#include "Command.hpp"

PlaceCommand::PlaceCommand(Robot robot, Point destination, Direction newDirection) :
    mRobot(robot), mDeployPosition(destination), mDeployDirection(newDirection)
{

}

Point PlaceCommand::getDeployPosition()
{
    return mDeployPosition;
}

Direction PlaceCommand::getDeployDirection()
{
    return mDeployDirection;
}

void PlaceCommand::execute() const
{
    mRobot.place(mDeployPosition, mDeployDirection);
}
