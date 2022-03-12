// while문을 사용한게 신박하다
// char배열에 입력받고 길이를 strlen으로 계산하면 |n도 포함되어 반복문을 한번 더 돌릴 수 있다.

#include <cstdio>
#include <cstring>
using namespace std;

int N;

void input(){
    scanf("%d", &N);
    scanf("%*c");
    while(N--){
        char str[80];
        scanf("%s", str);

        int total = 0, score = 1;
        for(int i=0; i<strlen(str); i++){
            if (str[i] == 'O')
                total += score++;
            else
                score = 1;
        }
        printf("%d\n", total);
    }
}

int main() {
    input();
    return 0;
}