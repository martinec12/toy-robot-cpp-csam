#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Constants.hpp"
#include "Helper.hpp"

std::vector<Direction> orderedDirections
{
    Direction::NORTH,
    Direction::EAST,
    Direction::SOUTH,
    Direction::WEST
};

std::string stringToUpper(const std::string &inputString)
{
    std::string outputString = inputString;
    std::transform(inputString.begin(), inputString.end(), 
                   outputString.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return outputString;
}

std::string stringToLower(const std::string &inputString)
{
    std::string outputString = inputString;
    std::transform(inputString.begin(), inputString.end(), 
                   outputString.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return outputString; 
}

std::string directionToString(const Direction &direction)
{
    std::string conversion;
    switch (direction)
    {
        case Direction::NORTH:
            conversion = "NORTH";
            break;
        case Direction::EAST:
            conversion = "EAST";
            break;
        case Direction::WEST:
            conversion = "WEST";
            break;
        case Direction::SOUTH:
            conversion = "SOUTH";
            break;
    }
    return conversion;
}

Direction stringToDirection(const std::string &directionString)
{
    if (stringToUpper(directionString) == "NORTH")
    {
        return Direction::NORTH;
    }
    else if (stringToUpper(directionString) == "EAST")
    {
        return Direction::EAST;
    }
    else if (stringToUpper(directionString) == "WEST")
    {
        return Direction::WEST;
    }
    else // if (stringToUpper(directionString) == "SOUTH")
    {
        return Direction::SOUTH;
    }
}
