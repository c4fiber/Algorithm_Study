// 9663 N-Queen
// 백트래킹, 브루트포스

#include <cstdio>
#include <cmath>
using namespace std;

int N, howManyNqueens;
int col[15]; // 이게 정말 신박하다

bool isOKtoPlace(int row){
    for (int i=0; i< row; i++){
        // 같은 열에 있거나 가로,세로 길이가 같으면 배치불가
        // i는 반드시 row보다 작으므로 abs 불필요
        if (col[i] == col[row] || row - i == abs(col[row] - col[i]))
            return false;
    }
    return true;
}

void nqueen(int row){
    if ( N <= row ){
        howManyNqueens ++;
    }else{
        for (int i=0; i<N; i++){
            col[row] = i;
            if ( isOKtoPlace(row) )
                nqueen(row+1);
        }
    }

    return;
}

void input() {
    scanf("%d\n", &N);
}

int main() {
    nqueen(0);
    
    printf("%d\n", howManyNqueens);
    return 0;
}