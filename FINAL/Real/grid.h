

class Grid {
    public:
        int getCell(int cellX, int cellY) {return cells[cellX][cellY];}
        void setCell(int cellX, int cellY, int numFill) {cells[cellX][cellY] = numFill;}

    private:
        int cells[3][3] = {
            {-1,-1,-1},
            {-1,-1,-1},
            {-1,-1,-1}
        };
};


