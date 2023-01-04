#include "Robot.hpp"
#include "Constants.hpp"
#include <iostream>
#include "Helper.hpp"
#include "Command.hpp"
#include <memory>
#include "Point.hpp"

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
    // TODO:
    return OperationStatus::SUCCESS;
}

OperationStatus Robot::computeNewDirection(std::string rotation)
{
    // TODO:
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
