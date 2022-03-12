#include <iostream>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct target{
    int shark;
    int x;
    int y;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, cnt;
int grid[21][21];
int fish[21][21];
bool visited[21][21];
queue<target> q;

bool fishExist(int shark){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(fish[i][j] < shark)
                return true;
        }
    }
    return false;
}

void hunt(){
    // dfs
    int prey = 0;

    // Checklist
    // 1. 먹을 수 있는 물고기가 존재하는가?
    // 2. 최단거리로 이동하는가? (dfs이므로 성립)
    // 3. 같은크기의 물고기를 지날경우 추후에 다시 확인하는가?

    while(!q.empty()){
        int shark = q.front().shark;     
        int x = q.front().x;
        int y = q.front().y;

        if(prey >= shark){
            prey = 0;
            shark++;
        } 

        if(!fishExist(shark)) return; // #1 먹을수 있는 물고기가 없다면 중단

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(1 <= nx && nx <= n && 1 <= ny && ny <= n){ // #1 인덱스가 범위를 넘어서지 않는가?
                if(fish[nx][ny] <= shark && !visited[nx][ny]){ // #3 큰물고기x, 이전에 방문x
                    q.push({shark, nx,ny});
                    // 잡아먹지 못하면 다시방문
                    fish[nx][ny] == shark ? visited[nx][ny] = false : visited[nx][ny] = true;
                    grid[nx][ny] = grid[x][y] + 1;

                    if(0 < fish[nx][ny]){
                        cnt = grid[nx][ny];
                        fish[nx][ny] = 0;
                        prey++;
                    }
                }
            }
        }
        q.pop();
    }
}

void input() {
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> fish[i][j];
            if(fish[i][j] == 9){
                fish[i][j] = 0;
                q.push({2,i,j});
            }
        }
    }
}

int main() {
	fastio;
	input();
    hunt();
	cout << cnt << '\n';
}