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
#if 0
    // TODO: create a Parser class to handle parsing of user input
    Parser commandParser(argc, argv);
#endif
    Table myTable;
    Robot myRobot;
    RobotInvoker robotInvoker;
    std::string commandString;

    while (true)
    {
#if 0
        // TODO: Parser class will return a pointer to a Command object
        // as a result of parsing
        std::unique_ptr<ICommand> command = commandParser.readAndParseCommand();
        if (command == nullptr)
        {
            std::cout << "Invalid command. Try again." << std::endl;
            continue;
        }
        
        // register the command into the invoker then invoke it
        // Transfer ownership of command to setCommand
        robotInvoker.setCommand(std::move(command));
        robotInvoker.invokeCommand();
#endif
    }
    
    return 0;
}
