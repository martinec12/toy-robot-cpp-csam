#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <vector>
#include <string>
#include <cstddef>
#include <istream>
#include <fstream>
#include <iostream>
#include "Constants.hpp"
#include <memory>
#include "Command.hpp"
#include "Robot.hpp"
#include "Table.hpp"
#include <istream>

class Parser
{
public:
    Parser();
    void readInputCommandString();
    std::unique_ptr<ICommand> convertInputStringToCommand(Robot &robot, Table &table);
    bool shouldStopInput();

protected:
    std::unique_ptr<std::istream> mInputStream;

private:
    std::string mInputCommandString;
    bool mStopInputs;
};

class FileParser : public Parser
{
public:
    FileParser(const char * fileName);
    ~FileParser();
};

class CommandLineParser : public Parser
{
public:
    CommandLineParser();
};

class StringParser : public Parser
{
public:
    StringParser(std::string inputString);
};


#endif // _PARSER_HPP_
