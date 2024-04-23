#include "grid.h"

Grid::Grid() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = '.';
        }
    }
}

void Grid::draw() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void Grid::markStart(int x, int y) {
    start = { x, y };
    grid[x][y] = 'S';
}

void Grid::markEnd(int x, int y) {
    end = { x, y };
    grid[x][y] = 'E';
}

void Grid::markBlocked(int x, int y) {
    blockedCells.push_back({ x, y });
    grid[x][y] = 'X';
}

bool Grid::isBlocked(int x, int y) {
    return grid[x][y] == 'X';
}

char Grid::getCellValue(int x, int y) {
    return grid[x][y];
}

void Grid::generateRandomBlockedCells(int count) {
    if (count > 0) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, ROWS - 1);
        for (int i = 0; i < count; ++i) {
            int x = dis(gen);
            int y = dis(gen);
            if ((x != start.x || y != start.y) && (x != end.x || y != end.y) && !isBlocked(x, y)) {
                markBlocked(x, y);
            }
            else {
                --i;
            }
        }
    }
}

vector<Point> Grid::findShortestPath() {

    vector<Point> path;
    path.push_back(start);
    path.push_back(end);

    int steps = 0;
    for (int i = 1; i < path.size(); ++i) {
        int xDiff = abs(path[i].x - path[i - 1].x);
        int yDiff = abs(path[i].y - path[i - 1].y);
        steps += max(xDiff, yDiff);
    }

    cout << "Number of steps: " << steps << endl;

    return path;
}