#include <iostream>
#include "sudoku.h"
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


void Sudoku::swapNum(int x, int y) {
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            if(arr[i][j][0] == x)
                arr[i][j][0] = y;
            else if(arr[i][j][0] == y)
                arr[i][j][0] = x;
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

int main() {
    Sudoku su;
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cin >> su.arr[i][j][0];
        }
    }

    int n, x, y;

    while(cin >> n) {
        if(n == 0)
            break;
        switch(n) {
        case 1:
            cin >> x >> y;
            su.swapNum(x, y);
            break;
        case 2:
            cin >> x >> y;
            su.swapRow(x, y);
            break;
        case 3:
            cin >> x >> y;
            su.swapCol(x, y);
            break;
        case 4:
            cin >> x;
            su.rotate(x);
            break;
        case 5:
            cin >> x;
            su.flip(x);
            break;
        }
    }

    for(int i=0; i<9; ++i) {
        for(int j=0; j<8; ++j) {
            cout << su.arr[i][j][0] << " ";
        }
        cout << su.arr[i][8][0] << endl;
    }
    return 0;
}
