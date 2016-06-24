#include <iostream>

#include "polygon.h"

void usage(char** argv)
{
    std::cout << "Usage: " << argv[0] << " <file>" << std::endl;
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        usage(argv);
        return 1;
    }
    Polygon p;
    Polygon convexHull;
    p.readInput(argv[1]);
    convexHull = p.ConvexHull();
    std::cout << convexHull.ToString() << std::endl;
    return 0;
}

