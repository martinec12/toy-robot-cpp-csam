#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <cstddef>

class Point
{
public:
    Point(std::size_t x = 0, std::size_t y = 0) : mX(x), mY(y)
    {

    }
    inline std::size_t getXCoordinate() const
    {
        return mX;
    }
    inline std::size_t getYCoordinate() const
    {
        return mY;
    }
    inline void setXCoordinate(std::size_t x)
    {
        mX = x;
    }
    inline void setYCoordinate(std::size_t y)
    {
        mY = y;
    }

private:
    std::size_t mX;
    std::size_t mY;
};

inline bool operator==(const Point &pointA, const Point &pointB)
{
    return ((pointA.getXCoordinate() == pointB.getXCoordinate()) &&
            (pointA.getYCoordinate() == pointB.getYCoordinate()));
}

inline bool operator!=(const Point &pointA, const Point &pointB)
{
    return !(pointA == pointB);
}

inline bool operator<(const Point &pointA, const Point &pointB)
{
    return ((pointA.getXCoordinate() == pointB.getXCoordinate()) &&
            (pointA.getYCoordinate() == pointB.getYCoordinate()));
}

#endif // _POINT_HPP_
