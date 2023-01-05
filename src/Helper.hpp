#ifndef _HELPER_HPP_
#define _HELPER_HPP_

#include <string>
#include <vector>
#include "Constants.hpp"

extern std::vector<Direction> orderedDirections;

std::string stringToUpper(const std::string &inputString);
std::string stringToLower(const std::string &inputString);
std::string directionToString(const Direction &direction);
Direction stringToDirection(const std::string &directionString);

#endif // _HELPER_HPP_
