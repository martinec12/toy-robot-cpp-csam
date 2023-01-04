#include <string>
#include <vector>
#include "Constants.hpp"
#include "Helper.hpp"

std::vector<Direction> orderedDirections
{
    Direction::NORTH,
    Direction::EAST,
    Direction::SOUTH,
    Direction::WEST
};

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
