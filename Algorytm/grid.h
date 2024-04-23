#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <random>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

struct Point {
    int x, y;
};

class Grid {
private:
    char grid[ROWS][COLS];
    vector<Point> blockedCells;
    Point start;
    Point end;

public:
    Grid();

    void draw();
    void markStart(int x, int y);
    void markEnd(int x, int y);
    void markBlocked(int x, int y);
    bool isBlocked(int x, int y);
    char getCellValue(int x, int y);
    void generateRandomBlockedCells(int count);
    vector<Point> findShortestPath();
};

#endif // GRID_H