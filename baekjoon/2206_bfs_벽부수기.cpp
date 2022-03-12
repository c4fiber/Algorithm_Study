// BFS
// 인자로 벽을 부순적 있는지 없는지 확인한다.
// x,y 는 배열을 왼쪽으로 90도 회전시켜서 바라본다.

#include <iostream>
using namespace std;
#include <queue>

#define MAX 1000

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX][2]; // [0]: 부수지 않고 방문, [1]: 부수고 방문
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

bool isInIndexRange(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < M);
}

void bfs(){
    queue<vector<int>> q;
    q.push({0,0,0});
    visited[0][0][0] = 1;
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int didBreak = q.front()[2];
        q.pop();

        if(x == N-1 && y == M-1){
            cout << visited[x][y][didBreak] << "\n";
            return;
        }

        for(int i=0; i<4; i++){
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (isInIndexRange(rx,ry)){
                // 벽이 있고 부술 수 있다면 부수고 들어간다.
                if (map[rx][ry] == 1 && didBreak == 0){
                    visited[rx][ry][1] = visited[x][y][0] + 1;
                    q.push({rx,ry,1});
                // 벽이없고 현재상태(부순적 있는지 없는지)에서 방문한 적이 없다면 방문한다.
                }else if (map[rx][ry] == 0 && visited[rx][ry][didBreak] == 0){
                    visited[rx][ry][didBreak] = visited[x][y][didBreak] + 1;
                    q.push({rx,ry,didBreak});
                }  
            }
        }
    }

    cout << -1 << "\n";
}

int init(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

int input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin >> c;
            map[i][j] = (int)c - 48;
        }
    } 
}

int main() {
    init();
    input();
    bfs();
    return 0;
}