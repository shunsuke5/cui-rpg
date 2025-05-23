#include "PrintCoordinate.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector <int> > coordinate = {
        {0,2},
        {1,1},
        {1,3},
        {2,0},
        {2,2},
        {2,4},
    };
    vector<vector <int> > co = {
        {0,0},
        {0,4},
        {1,1},
        {1,3},
        {2,2},
        {3,1},
        {3,3},
        {4,0},
        {4,4}
    };

    vector<vector <int> > a = {
        {0,0},{0,2},{0,4},{0,6},{0,8},
        {1,1},{1,3},{1,5},{1,7},{1,9},
    };

    PrintCoordinate p;
    p.Print(co);
    p.Print(coordinate);
    p.Print(a);
}