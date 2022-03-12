#include <iostream>
using namespace std;
#include <queue>

#define MAX 1001

int N, M;
int V;
int map[MAX][MAX];
int visited[MAX];
queue<int> q;

// dfs, bfs 모두 출력하기용, visited를 초기화 해야한다.
void eraseVisited(){
    for (int i=1; i<=N; i++)
        visited[i] = 0;
    cout << "\n";
}

// recursive로 구현한 DFS
void dfs(int root){
    cout << root << " ";
    visited[root] = 1;
    for (int i=1; i<=N; i++){
        if (map[root][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

// push와 동시에 방문했다는 사실을 잊지말자
void bfs(){
    q.push(V);
    visited[V] = 1;
    while(!q.empty()){
        int p = q.front();
        for (int i=1; i<=N; i++){
            if (map[p][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
        cout << p << " ";
        q.pop();
    }
}

void init(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input(){
    cin >> N >> M >> V;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }
}

int main() {
    init();
    input();

    dfs(V);
    eraseVisited();
    bfs();
    
    return 0;
}