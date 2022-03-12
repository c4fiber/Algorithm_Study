#include <iostream>
#include <vector>
using namespace std;


int getGapOfBW(vector<char> board, int first) {
    int gap;

    for (int i=0; i<8; i++) {
        if (board[first + i] == 'B')
            gap++;
        else
            gap--;
    }

    return abs(gap);
}

int main() {
    vector<vector<char>> board;
    vector<vector<int>> gap;
    int row, col;
    char color;
    cin >> row;
    cin >> col;

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            cin >> color;
            board[i].push_back(color);
        }
    }

    for (int i=0; i<row-8; i++){
        for (int j=0; j<row-8; j++){
            gap[i].push_back(getGapOfBW(board[i], i));
        }
    }

    return 0;
}