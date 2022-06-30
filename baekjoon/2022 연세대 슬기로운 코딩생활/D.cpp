#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;

#include <vector>
#include <queue>

int n, m, k;
vector<vector<int>> map(2000, vector<int>(2000));
queue<pair<int,int>> q;

bool isInIndex(int x, int y) {
    if (0 <= y && y < n && 0 <= x && x < m)
        return true;
    else
        return false;
}

void changeManekinToWall(int x, int y) {
    for(int i = y-k; i <= y+k; i++) {
        for(int j = x-k; j <= x+k; j++) {
            if (isInIndex(i,j) && (abs(y-i) + abs(x-j)) <= k) {
                map[i][j] = 1;
            }
        }
    }
}

bool movable(int x, int y) {
    return map[y][x] == 0 || map[y][x] == 2 ? true : false;
}

int bfs() {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;


        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // index 범위 체크
            if (isInIndex(nx, ny)) {
                if (map[ny][nx] == 2) { // 의자 발견
                    return -(map[y][x] - 1);
                }else if (map[ny][nx] == 0) { // 가지 않은 길 (갈 수 있음)
                    map[ny][nx] = map[y][x] -1;
                    q.push({nx,ny});
                }
            }
        }

        q.pop();
    }

    return -1;
}

int main() {
	fastio;

    cin >> n >> m >> k;

    // init map & save start position
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 4) {
                q.push({j,i});
                map[i][j] = 0;
            }
        }
    }

    // set wall in manekin's range
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (map[i][j] == 3) {
                changeManekinToWall(j, i);
            }
        }
    }

    // find route
    int helth = bfs();

    cout << helth;


}
