#include "Robot.hpp"
#include "Constants.hpp"
#include <iostream>
#include "Helper.hpp"
#include "Command.hpp"
#include <memory>
#include "Point.hpp"
#include <algorithm>

Robot::Robot() : mIsPlaced(false)
{
    // TODO: replace with ID generation
    mRobotId = 1;
    std::cout << "Robot [" << mRobotId << "] is created." << std::endl;
}

unsigned int Robot::getRobotId()
{
    return mRobotId;
}

OperationStatus Robot::place(Table &table, Point destination, Direction direction)
{
    if (!mIsPlaced || mLocation != destination)
    {
        if (!checkDestinationValidity(table, destination))
        {
            std::cout << "Destination is invalid" << std::endl;
            return OperationStatus::ERROR;
        }
        if (mIsPlaced)
        {
            if (table.releaseSlot(mLocation) == OperationStatus::ERROR)
            {
                std::cout << "Failed to release slot in location (" 
                          << mLocation.getXCoordinate() << "," 
                          << mLocation.getYCoordinate() << ")" << std::endl;
                return OperationStatus::ERROR;
            }
        }
        if (table.occupySlot(destination) == OperationStatus::ERROR)
        {
            std::cout << "Failed to occupy slot in location (" 
                      << destination.getXCoordinate() << "," 
                      << destination.getYCoordinate() << ")" << std::endl;
            return OperationStatus::ERROR;
        }
        setRobotLocation(destination);
    }
    setRobotDirection(direction);
    return OperationStatus::SUCCESS;
}

OperationStatus Robot::move(Table &table)
{
    if (!mIsPlaced)
    {
        std::cout << "Robot [" << mRobotId
                  << "] is not yet on the table!" << std::endl;
        return OperationStatus::ERROR;
    }
    Point destination;
    if (computeDestinationXY(destination) == OperationStatus::ERROR)
    {
        std::cout << "Unable to determine the destination's coordinates" << std::endl;
        return OperationStatus::ERROR;
    }
    if (mLocation != destination)
    {
        if (!checkDestinationValidity(table, destination))
        {
            std::cout << "Destination is invalid" << std::endl;
            return OperationStatus::ERROR;
        }
        if (table.releaseSlot(mLocation) == OperationStatus::ERROR)
        {
            std::cout << "Failed to release slot in location (" 
                      << mLocation.getXCoordinate() << "," 
                      << mLocation.getYCoordinate() << ")" << std::endl;
            return OperationStatus::ERROR;
        }
        if (table.occupySlot(destination) == OperationStatus::ERROR)
        {
            std::cout << "Failed to occupy slot in location (" 
                      << destination.getXCoordinate() << "," 
                      << destination.getYCoordinate() << ")" << std::endl;
            return OperationStatus::ERROR;
        }
        setRobotLocation(destination);
    }
    return OperationStatus::SUCCESS;
}

OperationStatus Robot::left()
{
    if (!mIsPlaced)
    {
        std::cout << "Robot [" << mRobotId
                  << "] is not yet on the table!" << std::endl;
        return OperationStatus::ERROR;
    }
    OperationStatus result = computeNewDirection("left");
    return result;
}

OperationStatus Robot::right()
{
    if (!mIsPlaced)
    {
        std::cout << "Robot [" << mRobotId
                  << "] is not yet on the table!" << std::endl;
        return OperationStatus::ERROR;
    }
    OperationStatus result = computeNewDirection("right");
    return result;
}

OperationStatus Robot::report()
{
    if (!mIsPlaced)
    {
        std::cout << "Robot [" << mRobotId
                  << "] is not yet on the table!" << std::endl;
        return OperationStatus::ERROR;
    }
    std::cout << "Output: " <<
        std::to_string(mLocation.getXCoordinate()) << "," <<
        std::to_string(mLocation.getYCoordinate()) << "," <<
        directionToString(mDirection) << std::endl;

    return OperationStatus::SUCCESS;
}

Point Robot::getRobotLocation()
{
    return mLocation;
}

Direction Robot::getRobotDirection()
{
    return mDirection;
}

// *****************
// Private functions

bool Robot::checkDestinationValidity(Table &table, Point &destination)
{
    bool isValid = true;
    
    isValid &= table.isPointWithinTableBounds(destination);
    // For additional checks for validity, add here by ANDing to isValid

    return isValid;
}

OperationStatus Robot::computeDestinationXY(Point &destination)
{
    // Determines the destination point after doing a MOVE
    switch (mDirection)
    {
        case Direction::NORTH:
            destination.setXCoordinate(mLocation.getXCoordinate());
            destination.setYCoordinate(mLocation.getYCoordinate() + 1);
            break;
        case Direction::EAST:
            destination.setXCoordinate(mLocation.getXCoordinate() + 1);
            destination.setYCoordinate(mLocation.getYCoordinate());
            break;
        case Direction::WEST:
            if (mLocation.getXCoordinate() == 0)
            {
                std::cout << "Cannot go WEST anymore, so not moving" << std::endl;
                return OperationStatus::ERROR;
            }
            destination.setXCoordinate(mLocation.getXCoordinate() - 1);
            destination.setYCoordinate(mLocation.getYCoordinate());
            break;
        case Direction::SOUTH:
            if (mLocation.getYCoordinate() == 0)
            {
                std::cout << "Cannot go SOUTH anymore, so not moving" << std::endl;
                return OperationStatus::ERROR;
            }
            destination.setXCoordinate(mLocation.getXCoordinate());
            destination.setYCoordinate(mLocation.getYCoordinate() - 1);
            break;
    }
    return OperationStatus::SUCCESS;
}

OperationStatus Robot::computeNewDirection(std::string rotation)
{
    if (rotation == "right")
    {
        std::vector<Direction>::iterator it = std::find(orderedDirections.begin(), orderedDirections.end(), mDirection);
        std::vector<Direction>::iterator newDirectionIt;        
        newDirectionIt = ++it;
        if(newDirectionIt == orderedDirections.end())
        {
            newDirectionIt = orderedDirections.begin();
        }
        mDirection = *newDirectionIt;
    }
    else
    {
        std::vector<Direction>::reverse_iterator it = std::find(orderedDirections.rbegin(), orderedDirections.rend(), mDirection);
        std::vector<Direction>::reverse_iterator newDirectionIt;       
        newDirectionIt = ++it;
        if(newDirectionIt == orderedDirections.rend())
        {
            newDirectionIt = orderedDirections.rbegin();
        }
        mDirection = *newDirectionIt;
    }
    return OperationStatus::SUCCESS;
}    

void Robot::setRobotLocation(Point destination)
{
    mLocation = destination;
    mIsPlaced = true;
}

void Robot::setRobotDirection(Direction newDirection)
{
    mDirection = newDirection;
}
