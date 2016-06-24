#include <algorithm>
#include <fstream>

#include "polygon.h"

Point::Point()
    : Point(0.0, 0.0)
{
}

Point::Point(float x, float y)
    : mX(x)
    , mY(y)
{
}

bool Point::IsOnTheLeftOf(const Point& p) const
{
    return mX < p.mX;
}

bool Point::IsOnTheLeftOf(const Point& p, const Point& q) const
{
    // Cross-product
    return ((mY - p.mY) * (q.mX - mX) - (mX - p.mX) * (q.mY - mY)) < 0;
}

std::string Point::ToString()
{
    std::ostringstream oss;
    oss << "[" << mX << " , " << mY << "]";
    return oss.str();
}

void Polygon::readInput(char* filename)
{
    std::ifstream input;
    input.open(filename);
    mPoints.clear();
    while(!input.eof())
    {
        float x, y;
        input >> x >> y;
        mPoints.push_back(Point(x, y));
    }
    input.close();
}

Polygon Polygon::ConvexHull() const
{
    // Gift-wrapping algorithm
    if(mPoints.size() < 3)
    {
        return Polygon();
    }
    Point leftmostPoint = mPoints.front();
    for(auto point : mPoints)
    {
        if(point.IsOnTheLeftOf(leftmostPoint))
        {
            leftmostPoint = point;
        }
    }
    Polygon convexHull;
    Point currentHullPoint = leftmostPoint;
    do
    {
        Point nextHullPoint;
        convexHull.mPoints.push_back(currentHullPoint);
        auto NextHullPointIt = std::find(mPoints.begin(), mPoints.end(), currentHullPoint);
        NextHullPointIt++;
        if(NextHullPointIt != mPoints.end())
        {
            nextHullPoint = *(NextHullPointIt);
        }
        else
        {
            nextHullPoint = mPoints.front();
        }
        for(auto candidateHullPoint : mPoints)
        {
            if(candidateHullPoint.IsOnTheLeftOf(currentHullPoint, nextHullPoint))
            {
                nextHullPoint = candidateHullPoint;
            }
        }
        currentHullPoint = nextHullPoint;
    } while(currentHullPoint != leftmostPoint);
    return convexHull;
}

std::string Polygon::ToString() const
{
    std::ostringstream oss;
    for(auto point : mPoints)
    {
        oss << point.ToString() << std::endl;
    }
    return oss.str();
}
