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
    Parser(int mainArgs, const char * const mainArgv[], std::istream &customIStream);
    ~Parser();
    void readInputCommandString();
    std::unique_ptr<ICommand> convertInputStringToCommand(Robot &robot, Table &table);
    bool shouldStopInput();

private:

    // This is called as part of constructor initializer for member mInternalFilestream
    static std::ifstream build_stream(int mainArgs, const char * const mainArgv[]) 
    {
        std::ifstream localInputFilestream;
        std::string inputFilename;
        if (mainArgs < 2)
        {
            inputFilename = DEFAULT_INPUT_FILENAME;
        }
        else
        {
            inputFilename = mainArgv[1];
        }

        localInputFilestream.open(inputFilename);
        return localInputFilestream;
    }

    std::string mInputCommandString;
    std::ifstream mInternalFilestream;
    std::istream &mInputStream;
    bool mStopInputs;
};

#endif // _PARSER_HPP_
