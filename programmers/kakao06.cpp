#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

vector<vector<int>> board = { {5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5} };
vector<vector<int>> skill = { {1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1} };

void useSkill(vector<int> v) {
    int type = v[0] == 1 ? -1 : 1;
    int r1 = v[1], c1 = v[2], r2 = v[3], c2 = v[4], degree = v[5];

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            board[i][j] += type * degree;
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    for (vector<int> v : skill)
        useSkill(v);
    return answer;
}

int solution2(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    for (vector<int> s : skill) {
        int type = s[0] == 1 ? -1 : 1;
        int r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], degree = s[5];

        for (int i = r1; i <= r2; i++ ) {
            vector<int> v, damage;
            v.assign(board[0].size() - (c2 - c1 + 1), 0);
            damage.assign(c2 - c1 + 1, type * degree);
            v.insert(v.begin() + c1, damage.begin(), damage.end());


            transform(board[i].begin(), board[i].end(), v.begin(), board[i].begin(), plus<int>());
        }
    }

    for (vector<int> b : board){
        for (int value : b){
            if (value > 0)
                answer += 1;
        }
    }

    return answer;
}

int main() {
    cout << solution2(board, skill) << endl;



}