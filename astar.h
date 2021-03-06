#ifndef ASTAR_H
#define ASTAR_H
#include "dijkstra.h"

//A* search.
class Astar : public Dijkstra
{
    public:
        Astar(bool WithTime = false, double HW = 1.0, bool BT = true);

    protected:
        double computeHFromCellToCell(int i1, int j1, int i2, int j2) override;
        double euclideanDistance(int x1, int y1, int x2, int y2);
        double manhattanDistance(int x1, int y1, int x2, int y2);
        double chebyshevDistance(int x1, int y1, int x2, int y2);
        double diagonalDistance(int x1, int y1, int x2, int y2);
        double metric(int x1, int y1, int x2, int y2);
};

#endif
