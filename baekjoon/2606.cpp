// 2606 바이러스
// Basic DFS
#include <cstdio>
using namespace std;
#include <queue>

#define MAX_OF_NODES 101

int N, M; // Nodes, Pairs
bool visited[MAX_OF_NODES];
bool edge[MAX_OF_NODES][MAX_OF_NODES];
queue<int> q;
int infectedComputers = 0;

void dfs(){
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int c = q.front();
        for(int i=1; i<=N; i++){
            if (edge[c][i] == true && visited[i] == false){
                q.push(i);
                visited[i] = true;
                infectedComputers++;
            }
        }
        q.pop();
    }
}

void inputExamples(){
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a][b] = edge[b][a] = true;
    }
}

int main() {
    inputExamples();
    dfs();

    printf("%d\n", infectedComputers);
    return 0;
}