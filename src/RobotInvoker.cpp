#include "RobotInvoker.hpp"
#include <memory>
#include <utility>

void RobotInvoker::setCommand(std::unique_ptr<ICommand> command)
{
    // Transfer ownership of command to RobotInvoker
    mCommand = std::move(command);
}

void RobotInvoker::invokeCommand() const
{
    mCommand->execute();
}
