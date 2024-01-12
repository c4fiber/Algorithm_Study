#include <iostream>
using namespace std;
#include <vector>

int main() {
    vector<vector<int>> board;
    vector<int> strap;
    int n;
    cin >> n;

    // input data
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int value;
            cin >> value;
            board[i].push_back(value);
        }
    }

    // collect synergy
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            int synergy = board[i][j] + board[j][i];
            strap.push_back(synergy);
        }
    }

    // find combination
    int total = 0;
    for (int i=0; i<n/2; i++){
        total += strap[i];
    }

    for (int i=0; i<n/2; i++){
        
    }

}