#include <iostream>
#include "sudoku.h"
#include <ctime>
using namespace std;

Sudoku::Sudoku() {
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            for(int k=0; k<10; ++k) {
                arr[i][j][k] = 0;
            }
            arr[i][j][10] = 9;
        }
    }
}

void Sudoku::swapRow(int x, int y) {
    for(int i=0; i<3; ++i) {
        for(int j=0; j<9; ++j) {
            swap(arr[x*3+i][j][0], arr[y*3+i][j][0]);
        }
    }
}

void Sudoku::swapCol(int x, int y) {
    for(int i=0; i<3; ++i) {
        for(int j=0; j<9; ++j) {
            swap(arr[j][x*3+i][0], arr[j][y*3+i][0]);
        }
    }
}

void Sudoku::rotate(int x) {
    int temp[9][9];
    for(int k=0; k<x; ++k) {
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                temp[i][j] = arr[8-j][i][0];
            }
        }

        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                arr[i][j][0] = temp[i][j];
            }
        }
    }
}

void Sudoku::flip(int x) {
    if(x == 0) {
        for(int i=0; i<4; ++i) {
            for(int j=0; j<9; ++j) {
                swap(arr[i][j][0], arr[8-i][j][0]);
            }
        }
    } else {
        for(int i=0; i<4; ++i) {
            for(int j=0; j<9; ++j) {
                swap(arr[j][i][0], arr[j][8-i][0]);
            }
        }
    }
}

Sudoku Sudoku::generate() {
    Sudoku su;
    int temp[9][9] = {{0,0,0,0,0,0,2,0,0}
        ,{5,9,0,0,7,0,0,0,0}
        ,{1,0,0,0,0,0,0,0,0}
        ,{0,0,0,0,0,0,0,7,3}
        ,{0,4,0,8,0,2,0,0,0}
        ,{0,0,0,0,0,3,0,0,0}
        ,{0,0,2,0,0,0,8,0,0}
        ,{6,0,0,0,0,1,0,0,0}
        ,{0,0,0,0,5,0,0,9,0}
    };
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            su.arr[i][j][0] = temp[i][j];
        }
    }
    int times = 0;
    while(times < 5) {
        int n = rand()%4 + 1, x = rand()%2, y = rand()%3;
        switch(n) {
        case 1:
            su.swapRow(x, y);
            break;
        case 2:
            su.swapCol(x, y);
            break;
        case 3:
            su.rotate(x);
            break;
        case 4:
            su.flip(x);
            break;
        }
        times++;
    }

    return su;
}

int main() {
    srand(time(NULL));
    Sudoku su = su.generate();
    for(int i=0; i<9; ++i) {
        for(int j=0; j<8; ++j) {
            cout << su.arr[i][j][0] << " ";
        }
        cout << su.arr[i][8][0] << endl;
    }
    return 0;
}

