#include <iostream>
using namespace std;

#include <queue>

int M, N, day;
int tomato[1001][1001];
queue<vector<int>> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool isInIndexRange(int x, int y) {
    return (0 <= x && x < M && 0 <= y && y < N);
}

void spread(int x, int y){
    for(int i=0; i<4; i++){
        int rx = x + dx[i];
        int ry = y + dy[i];

        if (isInIndexRange(rx,ry) == 1 && tomato[rx][ry] == 0){
            tomato[ry][rx] = tomato[y][x] + 1;
            q.push({ry,rx});
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tomato[i][j];
            if (tomato[i][j] == 1){
                q.push({i,j});
            }
        }
    }    
    
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        q.pop();
        
        for(int i=0; i<4; i++){
            int rx = x + dx[i];
            int ry = y + dy[i];

            if (isInIndexRange(rx,ry) == 1 && tomato[rx][ry] == 0){
                tomato[ry][rx] = tomato[y][x] + 1;
                q.push({ry,rx});
            }
        }
        
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {
            if (tomato[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
            if (day < tomato[i][j])
                day = tomato[i][j];
        }
    }

    cout << day - 1 << "\n";
    return 0;
}