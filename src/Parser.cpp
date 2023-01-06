#include "Parser.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include "Helper.hpp"
#include "Command.hpp"
#include <memory>
#include <istream>

Parser::Parser(int mainArgs, const char * const mainArgv[], std::istream &customIStream) :
    mInternalFilestream(build_stream(mainArgs, mainArgv)),
    mInputStream(mInternalFilestream.is_open() ? mInternalFilestream : customIStream),
    mStopInputs(false)
{

}

Parser::~Parser()
{
    mInternalFilestream.close();
}

void Parser::readInputCommandString()
{
    if (mInputStream.eof())
    {
        std::cout << "Eof encountered before any inputs/Empty input" << std::endl;
        mStopInputs = true;
    }
    std::getline(mInputStream, mInputCommandString);
    if (mInputStream.eof())
    {
        std::cout << "Eof of the input" << std::endl;
        mStopInputs = true;
    }
}

/// Conversion of the command from string format to a command object using regex
std::unique_ptr<ICommand> Parser::convertInputStringToCommand(Robot &robot, Table &table)
{
    
    std::string mainCommand;
    Point parsedDestination;
    Direction parsedDirection;
    std::size_t numMatches;
    
    // solution:
    // Step#1 1st match - match any of the main commands: PLACE, MOVE, LEFT, RIGHT, REPORT -- case insensitive
    std::string mainCommandPattern = "\\bPLACE\\b|\\bMOVE\\b|\\bLEFT\\b|\\bRIGHT\\b|\\bREPORT\\b";
    std::smatch mainCommandMatch;
    std::regex mainCommandRegex(mainCommandPattern, std::regex_constants::ECMAScript | std::regex_constants::icase);
    std::regex_search(mInputCommandString, mainCommandMatch, mainCommandRegex);

    // The following ensures only 1 match of either of the valid main commands
    // also no duplicates such as "MOVE MOVE" or "left left" or "PLACE x,y,f Place x,y,f"
    numMatches = mainCommandMatch.size();
    if (numMatches != 1)
    {
        std::cout << "Main command match is not exactly 1. # of matches: " << numMatches << std::endl;
        return nullptr;
    }

    mainCommand = mainCommandMatch.str(0);
    
    // Step#2 Command-specific handling
    std::string secondaryPattern;
    std::smatch secondaryMatch;
    std::regex secondaryRegex;

    if (stringToLower(mainCommand) != "place")
    {
        // 2.1. for MOVE, LEFT, RIGHT, REPORT: pattern is the command and no other non-whitespace
        secondaryPattern = "^\\s*(MOVE)\\s*$|^\\s*(LEFT)\\s*$|^\\s*(RIGHT)\\s*$|^\\s*(REPORT)\\s*$";
        secondaryRegex.assign(secondaryPattern, std::regex_constants::ECMAScript | std::regex_constants::icase);
        std::regex_search(mInputCommandString, secondaryMatch, secondaryRegex);

        // The following ensures only 1 match of either of the valid commands that are not place
        // also there are 4 match groups (enclosed with parentheses) used in the pattern
        unsigned int matchGroupsUsed = 4;
        numMatches = secondaryMatch.size() - matchGroupsUsed;
        if (numMatches != 1)
        {
            std::cout << "No match for valid syntax of non-PLACE command" << std::endl;
            return nullptr;
        }

        if (stringToLower(mainCommand) == "move")
        {
            return std::make_unique<MoveCommand>(robot, table);
        }
        else if (stringToLower(mainCommand) == "left")
        {
            return std::make_unique<LeftCommand>(robot);
        }
        else if (stringToLower(mainCommand) == "right")
        {
            return std::make_unique<RightCommand>(robot);
        }
        else if (stringToLower(mainCommand) == "report")
        {
            return std::make_unique<ReportCommand>(robot);
        }
        else // somehow an unknown command
        {
            std::cout << "Unknown command" << std::endl;
            return nullptr;
        }
    }
    else
    {
        // 2.2. for PLACE x,y,f: pattern is the following:
        // ^\s*\bPLACE\b\s+([0-9]+),([0-9]+),\b(NORTH|EAST|SOUTH|WEST)\b\s*$
        secondaryPattern = "^\\s*\\bPLACE\\b\\s+([0-9]+),([0-9]+),\\b(NORTH|EAST|SOUTH|WEST)\\b\\s*$";
        secondaryRegex.assign(secondaryPattern, std::regex_constants::ECMAScript | std::regex_constants::icase);
        std::regex_search(mInputCommandString, secondaryMatch, secondaryRegex);

        // Expecting 4 matches because besides the overall match
        // regex_search counts each catch group/parenthetical group as 1 match
        unsigned int matchGroupsUsed = 3;
        // There should be exactly 1 match after removing the catch groups
        numMatches = secondaryMatch.size() - matchGroupsUsed;
        if (numMatches != 1)
        {
            std::cout << "No match for valid syntax of PLACE command" << std::endl;
            return nullptr;
        }

        // First catch group is for the x-value, second is for the y-value
        // and the third is for the direction
        parsedDestination.setXCoordinate(static_cast<std::size_t>(std::stoul(secondaryMatch.str(1))));
        parsedDestination.setYCoordinate(static_cast<std::size_t>(std::stoul(secondaryMatch.str(2))));
        parsedDirection = stringToDirection(secondaryMatch.str(3));
        return std::make_unique<PlaceCommand>(robot, table, parsedDestination, parsedDirection);
    }
}

bool Parser::shouldStopInput()
{
    return mStopInputs;
}
