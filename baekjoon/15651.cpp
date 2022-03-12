// DFS, 브루트포스
// 중복을 허용하므로 하나하나 다 넣는다

#include <cstdio>
using namespace std;

#define MAX 7+1

int n, m;
int arr[MAX];

void dfs(int step) {
    if(step >= m){
        for(int i=0; i<m; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i=1; i<=n; i++){
        arr[step] = i;
        dfs(step+1);
    }
}

void input(){
    scanf("%d %d", &n, &m);
}

int main() {
    input();
	dfs(0);
    return 0;
}