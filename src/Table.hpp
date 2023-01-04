#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#include <cstddef>
#include "Point.hpp"
#include "Constants.hpp"
#include <set>
#include <iostream>

class Table
{
public:
    Table(std::size_t length = 5, std::size_t width = 5);
    bool isPointWithinTableBounds(const Point &point);
    OperationStatus occupySlot(const Point point);
    OperationStatus releaseSlot(const Point point);
    
private:

    // Length will be intepreted as running along x-axis; and Width, along y-axis
    std::size_t mLength;
    std::size_t mWidth;
    std::set<Point> mOccupiedSlots;
};

#endif // _TABLE_HPP_
