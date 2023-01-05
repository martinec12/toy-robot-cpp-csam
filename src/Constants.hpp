#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

#include <string>

enum class Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

enum class OperationStatus
{
    SUCCESS,
    ERROR
};

extern const std::string DEFAULT_INPUT_FILENAME;

#endif // _CONSTANTS_HPP_