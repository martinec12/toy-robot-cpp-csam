#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#include <cstddef>
#include "Point.hpp"
#include "Constants.hpp"
#include <set>

class Table
{
public:
    Table(std::size_t length = 5, std::size_t width = 5);
    bool isPointWithinTableBounds(const Point &point);
    OperationStatus occupySlot(const Point &point);
    OperationStatus releaseSlot(const Point &point);
    bool isTableOccupied();
    std::size_t getTableLength() const;
    std::size_t getTableWidth() const;
    
private:
    bool isSlotOccupied(const Point &point);
    //OperationStatus removePointFromSet(const Point &point);
#ifdef DEBUG
    void displayOccupiedSlots();
#endif
    // Length will be intepreted as running along x-axis; and Width, along y-axis
    std::size_t mLength;
    std::size_t mWidth;
    std::set<Point> mOccupiedSlots;
};

#endif // _TABLE_HPP_
