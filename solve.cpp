#include <iostream>
#include "sudoku.h"
using namespace std;

int count = 0;

Sudoku::Sudoku() {
    isCorrect = true;
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            for(int k=0; k<10; ++k) {
                arr[i][j][k] = 0;
            }
            arr[i][j][10] = 9;
        }
    }
}

bool Sudoku::wrong() {
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            if(arr[i][j][0] == 0 && arr[i][j][10] == 0) {
                return true;
            }
        }
    }
    return false;
}

void Sudoku::cross(int i, int j, int value) {
    for(int t=0; t<9; ++t) {
        if(arr[i][t][value] != 1) {
            arr[i][t][value] = 1;
            arr[i][t][10]--;
            if(arr[i][t][0] == 0 && arr[i][t][10] == 0)
                isCorrect = false;
        }
        if(arr[t][j][value] != 1) {
            arr[t][j][value] = 1;
            arr[t][j][10]--;
            if(arr[t][j][0] == 0 && arr[t][j][10] == 0)
                isCorrect = false;
        }
    }
    for(int k=(i/3)*3; k<(i/3)*3+3; ++k) {
        for(int l=(j/3)*3; l<(j/3)*3+3; ++l) {
            if(arr[k][l][value] != 1) {
                arr[k][l][value] = 1;
                arr[k][l][10]--;
                if(arr[k][l][0] == 0 && arr[k][l][10] == 0)
                    isCorrect = false;
            }
        }
    }
}

int Sudoku::getMin() {
    int minx = 10, miny = 10;
    int min = 10;
    //arr[minx][miny][10] = 10;//illegal
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            if(arr[i][j][0] == 0 && arr[i][j][10]<min) {
                if(arr[i][j][10] == 1) return i*9+j;
                min = arr[i][j][10];
                minx = i;
                miny = j;
            }
        }
    }
    return minx*9+miny;
}

void Sudoku::solve_at(int min) {
    //print(min);
    count++;
    if(isCorrect == false || min == 100) {
        return ;
    }
    for(int i=1; i<=9; ++i) {
        if(arr[min/9][min%9][i] == 0 && arr[min/9][min%9][0] == 0) {
            if(arr[min/9][min%9][10] == 1) {
                arr[min/9][min%9][0] = i;
                cross(min/9, min%9, i);
                min = getMin();
                solve_at(min);
                break;
            } else {
                int temp[9][9][11], tempMin = min;
                for(int j=0; j<9; ++j) {
                    for(int k=0; k<9; ++k) {
                        for(int l=0; l<11; ++l) {
                            temp[j][k][l] = arr[j][k][l];
                        }
                    }
                };
                arr[min/9][min%9][0] = i;
                cross(min/9, min%9, i);
                min = getMin();
                solve_at(min);
                if(isCorrect == false) {
                    for(int j=0; j<9; ++j) {
                        for(int k=0; k<9; ++k) {
                            for(int l=0; l<11; ++l) {
                                arr[j][k][l] = temp[j][k][l];
                            }
                        }
                    }
                    min = tempMin;
                    arr[min/9][min%9][0] = 0;
                    arr[min/9][min%9][i] = 1;
                    arr[min/9][min%9][10]--;
                    isCorrect = true;
                }/* else {
                    int another[9][9][11];
                    for(int j=0; j<9; ++j) {
                        for(int k=0; k<9; ++k) {
                            for(int l=0; l<11; ++l) {
                                another[j][k][l] = arr[j][k][l];
                                arr[j][k][l] = temp[j][k][l];
                            }
                        }
                    }
                    min = tempMin;
                    arr[min/9][min%9][0] = 0;
                    arr[min/9][min%9][i] = 1;
                    arr[min/9][min%9][10]--;
                    solve_at(min);
                    if(isCorrect == true) {
                        cout << "2" << endl;
                        exit(0);
                    }
                    for(int j=0; j<9; ++j) {
                        for(int k=0; k<9; ++k) {
                            for(int l=0; l<11; ++l) {
                                arr[j][k][l] = another[j][k][l];
                            }
                        }
                    }
                    isCorrect = true;
                }
           */
            }
        }
    }
}

int main() {
    Sudoku su;
    int zeroCount = 0;
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cin >> su.arr[i][j][0];
            if(su.arr[i][j][0] != 0) {
                su.cross(i, j, su.arr[i][j][0]);
            } else {
                zeroCount++;
            }
        }
    }

    if(zeroCount > 64) {
        cout << "2" << endl;
        return 0;
    }

    su.solve_at(su.getMin());
    if(su.wrong()) {
        cout << "0" << endl;
        return 0;
    }

    cout << 1 << endl;
    for(int i=0; i<9; ++i) {
        for(int j=0; j<8; ++j) {
            cout << su.arr[i][j][0] << " ";
        }
        cout << su.arr[i][8][0] << endl;
    }
    return 0;
}

