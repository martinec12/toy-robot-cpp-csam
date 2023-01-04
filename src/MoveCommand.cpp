#include "Robot.hpp"
#include "Table.hpp"
#include "Command.hpp"

MoveCommand::MoveCommand(Robot &robot, Table &table) :
    mRobot(robot), mTable(table)
{

}

void MoveCommand::execute() const
{
    mRobot.move(mTable);
}
