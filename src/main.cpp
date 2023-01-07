#include "Parser.hpp"
#include "Table.hpp"
#include "Robot.hpp"
#include <iostream>
#include <string>
#include "RobotInvoker.hpp"
#include "Command.hpp"
#include <memory>
#include <utility>

int main(int argc, char *argv[])
{
    std::unique_ptr<Parser> commandParser;
    Table myTable;
    Robot myRobot;
    RobotInvoker robotInvoker;
    std::string commandString;

    if (argc == 2)
    {
        commandParser = std::make_unique<FileParser>(argv[1]);
    }
    else
    {
        commandParser = std::make_unique<CommandLineParser>();
    }

    while (true)
    {
        commandParser->readInputCommandString();
        if (commandParser->shouldStopInput())
        {
            std::cout << "Ending inputs as desired by user" << std::endl;
            break;
        }

        std::unique_ptr<ICommand> command = commandParser->convertInputStringToCommand(myRobot, myTable);
        if (command == nullptr)
        {
            std::cout << "Invalid command. Try again." << std::endl;
            continue;
        }
        
        // register the command into the invoker then invoke it
        // Transfer ownership of command to setCommand
        robotInvoker.setCommand(std::move(command));
        robotInvoker.invokeCommand();
    }
    
    return 0;
}
