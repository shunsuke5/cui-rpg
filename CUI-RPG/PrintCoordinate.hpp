#include <iostream>
#include <vector>

/*
* 座標情報を持つvector<vector<int>>の配列から描画するクラス
*/

class PrintCoordinate {
public:
    void Print(std::vector<std::vector<int> > coordinate);

private:
    const int MAX_COLUMN = 74; // 1行に表示する最大文字数
};