#include <iostream>
using namespace std;
#include <queue>

#define MAX_OF_NODES 101

int N, M;
int visited[MAX_OF_NODES];
int graph[MAX_OF_NODES][MAX_OF_NODES];
queue<int> q;
int count = 0;

void dfs(){
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int c = q.front();
        for(int i=1; i<=N; i++){
            if (graph[c][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
                count++;
            }
        }
        q.pop();
    }
}

void init(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input(){
    cin >> N;
    cin >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }
}

int main() {
    init();
    input();
    dfs();

    cout << count << "\n";
    return 0;
}