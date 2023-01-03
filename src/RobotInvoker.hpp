#ifndef _ROBOT_INVOKER_HPP_
#define _ROBOT_INVOKER_HPP_

#include "Command.hpp"
#include <memory>

class RobotInvoker
{
public:
    void setCommand(std::unique_ptr<ICommand> command);
    void invokeCommand() const;
private:
    // Actual command acquired from main
    // For every iteration of parsed user input is a corresponding command
    std::unique_ptr<ICommand> mCommand;
};


#endif // _ROBOT_INVOKER_HPP_
