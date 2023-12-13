

class Grid {
    public:
        Grid();
        int getCell(int, int);
        void setCell(int, int, int);
        bool checkWin();
        bool checkDraw();
    private:
        int cells[3][3] = {
            {-1,-1,-1},
            {-1,-1,-1},
            {-1,-1,-1}
        };
};


