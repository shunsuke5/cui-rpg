#include "PrintCoordinate.hpp"
#include <iostream>
#include <vector>
using namespace std;

void PrintCoordinate::Print(vector<vector<int> > coordinate) {
    const int X = 0;        // 行
    const int Y = 1;        // 列
    int currentIndex = 0;   // coordinateの現在インデックス
    int currentRow = 0;     // 現在行

    while (currentIndex < coordinate.size()) {
        if (coordinate[currentIndex][X] != currentRow) {
            cout << endl;
            currentRow++;
            continue;
        } else {
            for (int j = 0; j < MAX_COLUMN; j++) {
                // whileと同じ判定を行っていて無駄なので、どうにか省略できないか気が向いたら考える
                if (currentIndex == coordinate.size()) {
                    break;
                }

                if (coordinate[currentIndex][Y] == j) {
                    cout << '*';
                    currentIndex++;
                } else {
                    cout << ' ';
                }
            }
        }
    }

    cout << endl;
}