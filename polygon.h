#ifndef POLYGON_H
#define POLYGON_H

#include <list>
#include <string>
#include <sstream>

class Point
{
public:
    Point();
    Point(float x, float y);
    bool IsOnTheLeftOf(const Point& p) const;
    bool IsOnTheLeftOf(const Point& p, const Point &q) const;
    std::string ToString();
    friend bool operator==(const Point& lhs, const Point& rhs);
    friend bool operator!=(const Point& lhs, const Point& rhs);

private:
    float mX;
    float mY;
};

inline bool operator==(const Point& lhs, const Point& rhs)
{
    return (lhs.mX == rhs.mX) && (lhs.mY == rhs.mY);
}

inline bool operator!=(const Point& lhs, const Point& rhs)
{
    return !(lhs == rhs);
}

class Polygon
{
public:
    void readInput(char* filename);
    Polygon ConvexHull() const;
    std::string ToString() const;

private:
    std::list<Point> mPoints;
};

#endif // POLYGON_H

