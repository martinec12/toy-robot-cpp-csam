#include "Table.hpp"
#include "Constants.hpp"
#include "Point.hpp"
#include <iostream>

Table::Table(std::size_t length, std::size_t width) : 
    mLength(length), mWidth(width)
{

}

bool Table::isPointWithinTableBounds(const Point &point)
{
    // No checking for negative coordinates because they are size_t type
    if (point.getXCoordinate() <= mLength &&
        point.getYCoordinate() <= mWidth)
    {
        return true;
    }

    std::cout << "Point (" << point.getXCoordinate() << "," << point.getYCoordinate() << ") is OUT OF BOUNDS" << std::endl;
    return false;
}

OperationStatus Table::occupySlot(const Point &point)
{
    if (isPointWithinTableBounds(point) && !isSlotOccupied(point))
    {
        // std::set.insert makes a copy of the element
        // thus point may be a reference
        std::pair<std::set<Point>::iterator, bool> result = mOccupiedSlots.insert(point);
        if (result.second == true)
        {
            return OperationStatus::SUCCESS;
        }
    }
    std::cout << "Occupy slot ("
              << point.getXCoordinate() << ","
              << point.getYCoordinate() << ") failed" << std::endl;
    return OperationStatus::ERROR;
}

OperationStatus Table::releaseSlot(const Point &point)
{
    if (!isPointWithinTableBounds(point))
    {
        std::cout << "Release slot ("
                  << point.getXCoordinate() << ","
                  << point.getYCoordinate() << ") failed" << std::endl
                  << "Cannot release a slot that is out of bounds of the table" << std::endl;
        return OperationStatus::ERROR;
    }
    if (!isSlotOccupied(point))
    {
        std::cout << "Release slot ("
                  << point.getXCoordinate() << ","
                  << point.getYCoordinate() << ") failed" << std::endl
                  << "Failed to release a slot that is not occupied in the first place" << std::endl;
        return OperationStatus::ERROR;
    }

    if (mOccupiedSlots.erase(point) == 0)
    {
        std::cout << "Release slot ("
                  << point.getXCoordinate() << ","
                  << point.getYCoordinate() << ") failed" << std::endl
                  << "Slot point not erased" << std::endl;
        return OperationStatus::ERROR;
    }

    return OperationStatus::SUCCESS;
}

bool Table::isTableOccupied()
{
    return (!mOccupiedSlots.empty());
}

std::size_t Table::getTableLength() const
{
    return mLength;
}

std::size_t Table::getTableWidth() const
{
    return mWidth;
}

// *****************
// Private functions

bool Table::isSlotOccupied(const Point &point)
{
    for (auto it = mOccupiedSlots.begin(); it != mOccupiedSlots.end(); ++it)
    {
        if ((*it) == point)
        {
            return true;
        }
    }
    return false;
}

#if 0
// might not be needed
OperationStatus Table::removePointFromSet(const Point &point)
{
    for(auto it = mOccupiedSlots.begin(); it != mOccupiedSlots.end(); ++it)
    {
        if ((*it) == point)
        {
            mOccupiedSlots.erase(it);
            return OperationStatus::SUCCESS;
        }
    }
    return OperationStatus::ERROR;
}
#endif

#ifdef DEBUG
void Table::displayOccupiedSlots()
{
    for(std::set<Point>::iterator it = mOccupiedSlots.begin(); it != mOccupiedSlots.end(); ++it)
    {
        std::cout << "(" << (*it).getXCoordinate() << "," << (*it).getYCoordinate() << ")" << std::endl;
    }
}
#endif
