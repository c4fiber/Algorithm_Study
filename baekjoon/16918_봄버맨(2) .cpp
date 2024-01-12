#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
#include <queue>
using namespace std;


int R, C, N;
char map[200][200];
queue<pair<int,int>> q;

bool isAvailable(int y, int x) {
    return 0 <= x && x < C && 0 <= y && y < R;
}

void eraseNextBomb(int y, int x) {
    int dy[5] = {0, -1, 0, 1, 0};
    int dx[5] = {-1, 0, 1, 0, 0};

    for(int i=0; i<5; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(isAvailable(ny, nx)) {
            map[ny][nx] = '.';
        }
    }
}

void fullWithBomb() {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            map[i][j] = 'O';
        }
    }
}

void printMap() {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}

int main() {
	fastio;

    // input
    cin >> R >> C >> N;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'O')
                q.push({i,j});
        }
    }

    if(N % 2 == 0) {
        fullWithBomb();
        printMap();
        return 0;
    }

    for(int nowTime = 3; nowTime <= N; nowTime+=2) {
        fullWithBomb();
        
        while(!q.empty()) {
            eraseNextBomb(q.front().first, q.front().second);
            q.pop();
        }

        // reload next bombs
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(map[i][j] == '.')
                    q.push({i,j});
            }
        }
    }

    printMap();

    return 0;
}
