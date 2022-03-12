// DFS
// 처음엔 for문을 i--를 이용해서 뒤부터 채우려고 했지만 그럴 필요가 없었다.
// 본질에 접근하자. 단순하게 보자.

#include <cstdio>
using namespace std;

#define MAX 8

int n, m;
int arr[MAX] = {1,};

void dfs(int step){
    if(step > m){
        for(int i=1; i<=m; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }else{
        for(int i=arr[step-1]; i<=n; i++){
            arr[step] = i;
            dfs(step+1);
        }
    }
}

void input(){
    scanf("%d %d", &n, &m);
}

int main() {
    input();
	dfs(1);
    return 0;
}