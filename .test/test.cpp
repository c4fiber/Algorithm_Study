#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int searched[100][100];
queue<pair<int,int>> q;
int mapSize;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inRange(int x, int y) {
    return 0 <= x && x < mapSize && 0 <= y && y < mapSize;
}

int bfs(vector<string> maps, pair<int,int> startPoint) {
    q.push(startPoint);
    int avaliableFoods = 0;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!searched[ny][nx] && inRange(nx, ny)) {
                q.push(make_pair(ny,nx));
            }
        }
        
        avaliableFoods += maps[y][x] - '0';
        searched[y][x] = 1;
    }
    
    return avaliableFoods;
}

int getAvailableFoods(vector<string> maps, pair<int,int> startPoint) {
    if (maps[startPoint.second][startPoint.first] != 'X') {
        return bfs(maps, startPoint);
    }
    return 0;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i=0; i<maps.size(); i++)
        for(int j=0; j<maps.size(); j++)
            answer.push_back(getAvailableFoods(maps, make_pair(i,j)));

    answer.erase(remove(answer.begin(), answer.end(), 0), answer.end());
    if (answer.size() == 0) answer.push_back(-1);

    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<string> maps = {"X1X","X4X","XXX"};
    mapSize = maps.size();

    vector<int> answer = solution(maps);

    for (int i=0; i<answer.size(); i++) {
        cout << answer.at(i) << endl;
    }

    return 0;
}
