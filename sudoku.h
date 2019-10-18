#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku {
  public:
    Sudoku();
    int arr[9][9][11];
    bool isCorrect;
    // generate
    Sudoku generate();

    // transform
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    void solve_at(int);
    bool wrong();
    void cross(int, int, int);
    int getMin();

};

#endif // SUDOKU_H
