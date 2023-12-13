#include "Grid.h"

Grid::Grid() {

}

void Grid::setCell(int cellX, int cellY, int numFill) {
    cells[cellX][cellY] = numFill;
}

int Grid::getCell(int cellX, int cellY) {
    return cells[cellX][cellY];
}

bool Grid::checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (cells[i][0] != -1 && cells[i][0] == cells[i][1] && cells[i][0] == cells[i][2]) {
            return true;
        }
        if (cells[0][i] != -1 && cells[0][i] == cells[1][i] && cells[0][i] == cells[2][i]) {
            return true;
        }
    }

    if (cells[0][0] != -1 && cells[0][0] == cells[1][1] && cells[0][0] == cells[2][2]) {
        return true;
    }
    if (cells[0][2] != -1 && cells[0][2] == cells[1][1] && cells[0][2] == cells[2][0]) {
        return true;
    }

    return false;
}

bool Grid::checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(cells[i][j] == -1) {
                return false;
            }
        }
    }
    return true;
}
