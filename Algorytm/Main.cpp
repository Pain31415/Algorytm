#include <iostream>
#include "grid.h"
using namespace std;

int main() {
    Grid grid;

    cout << "Enter the grid (10x10) values:" << endl;
    grid.draw();

    int startX, startY, endX, endY, blockedCount;

    cout << "Enter the starting point (x y): ";
    cin >> startX >> startY;
    grid.markStart(startX, startY);
    cout << "Grid with starting point:" << endl;
    grid.draw();

    cout << "Enter the ending point (x y): ";
    cin >> endX >> endY;
    grid.markEnd(endX, endY);
    cout << "Grid with ending point:" << endl;
    grid.draw();

    cout << "Enter the number of blocked cells: ";
    cin >> blockedCount;
    for (int i = 0; i < blockedCount; ++i) {
        int x, y;
        cout << "Enter blocked cell " << i + 1 << " (x y): ";
        cin >> x >> y;
        grid.markBlocked(x, y);
        cout << "Grid with blocked cell " << i + 1 << ":" << endl;
        grid.draw();
    }

    vector<Point> shortestPath = grid.findShortestPath();

    cout << "Shortest path:" << endl;
    for (const auto& p : shortestPath) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;

    return 0;
}