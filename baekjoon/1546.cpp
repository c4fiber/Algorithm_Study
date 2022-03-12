// 소수 자료형 활용

#include <cstdio>
using namespace std;

int N, M;
int score[1000];

double cheat(){
    double total = 0;
    for(int i=0; i<N; i++){
        total += (double)score[i] / M * 100;
    }

    return total / N;
}

void input(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &score[i]);
        if(score[i] > M) M = score[i];
    }
}

int main() {
    input();
	printf("%lf\n", cheat());
    return 0;
}