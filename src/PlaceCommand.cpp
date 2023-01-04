#include "Robot.hpp"
#include "Table.hpp"
#include "Point.hpp"
#include "Constants.hpp"
#include "Command.hpp"

PlaceCommand::PlaceCommand(Robot &robot, Table &table, Point destination, Direction newDirection) :
    mRobot(robot), mTable(table),
    mDeployPosition(destination), mDeployDirection(newDirection)
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
    mRobot.place(mTable, mDeployPosition, mDeployDirection) ;
}
