#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;


int R, C, N;
char map[200][200];
int boomTime[200][200];

bool isAvailable(int y, int x) {
    return 0 <= x && x < C && 0 <= y && y < R;
}

void eraseNextBomb(int y, int x) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    for(int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(isAvailable(ny, nx)) {
            boomTime[ny][nx] = 0;
            map[ny][nx] = '.';
        }
    }
}

void installBomb(int nowTime) {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if (boomTime[i][j] == 0) {
                boomTime[i][j] = nowTime + 3;
                map[i][j] = 'O';
            }
        }
    }

}

void boom(int nowTime) {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if (boomTime[i][j] == nowTime) {
                map[i][j] = '.';
                boomTime[i][j] = 0;

                eraseNextBomb(i,j);
            }
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
                boomTime[i][j] = 3;
        }
    }

    for(int nowTime = 2; nowTime <= N; nowTime++) {
        // 짝수 : 폭탄이 없는곳에 폭탄 설치
        if(nowTime % 2 == 0) {
            installBomb(nowTime);
        }else {
            boom(nowTime);
        }
    }

    printMap();

    return 0;
}
