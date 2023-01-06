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
    Parser commandParser(argc, argv, std::cin);
    Table myTable;
    Robot myRobot;
    RobotInvoker robotInvoker;
    std::string commandString;

    while (true)
    {
        // TODO: Parser class will return a pointer to a Command object
        // as a result of parsing
        commandParser.readInputCommandString();
        if (commandParser.shouldStopInput())
        {
            std::cout << "Ending inputs as desired by user" << std::endl;
            break;
        }

        std::unique_ptr<ICommand> command = commandParser.convertInputStringToCommand(myRobot, myTable);
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
