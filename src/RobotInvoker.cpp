#include "RobotInvoker.hpp"
#include <memory>
#include <utility>

void RobotInvoker::setCommand(std::unique_ptr<ICommand> command)
{
    mCommand = std::move(command);
}

void RobotInvoker::invokeCommand() const
{
    mCommand->execute();
}
