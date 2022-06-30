// 미완성

#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
#include <string>
using namespace std;


string bw[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string wb[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

int n, m;
string board[50];

int compare_with_bw(int row, int col) {
    int cnt = 0;

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if (bw[i][j] != board[row+i][col+j])
                cnt++;
        }
    }

    return cnt;
}

int compare_with_wb(int row, int col) {
    int cnt = 0;

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if (wb[i][j] != board[row+i][col+j])
                cnt++;
        }
    }

    return cnt;
}


int main() {
    fastio;
    
    // input
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }

    int minimum = n*m;
    for (int row=0; row<=n-8; row++) {
        for (int col=0; col<=m-8; col++) {
            int temp_bw = compare_with_bw(row,col);
            int temp_wb = compare_with_wb(row,col);

            minimum = min(minimum, min(temp_bw,temp_wb));
        }
    }

    cout << minimum;

    return 0;
}