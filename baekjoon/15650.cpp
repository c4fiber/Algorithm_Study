// 백준 15650 N과 M(2)
// 1 ~ N 까지의 수를 이용하여 M길이의 수열 만들기
// 15649에서 오름차순조건 추가

#include <cstdio>
using namespace std;

#define MAX 9

int N, M; 
int arr[MAX];
bool visited[MAX];

void printAll(){
    for (int i=0; i<M; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void NnM(int step, int root){
    if (step == M){
        printAll();
    } else {
        for(int i=root; i<=N; i++){
            if (!visited[i]){
                visited[i] = true;
                arr[step] = i;
                NnM(step+1, i);
                visited[i] = false;
            }
        } 
    }
}

void input(){
    scanf("%d %d", &N, &M);
}

int main() {
    input();
	NnM(0, 1);
    return 0;
}