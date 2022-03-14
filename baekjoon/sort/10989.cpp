// 수 정렬하기 3
// 카운팅 정렬

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
int counting[10001];

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        short value;
        cin >> value;
        counting[value]++;
    }
}

int main() {
	fastio;
	input();

    // counting sort

/*
    // 발견된 숫자의 누적합
    for(int i=1; i<10001; i++) {
        counting[i] += counting[i-1];
    }
*/
    short num=0;
    for(int i=0; i<n; i++){
        if(counting[num] > 0){
            cout << num << '\n';
            counting[num]--;
        }else{
            num++;
            i--;
        }
    }
}