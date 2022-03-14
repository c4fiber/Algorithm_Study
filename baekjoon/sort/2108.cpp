// 통계학

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <cmath>
#include <algorithm>

int n;
long long total;
short arr[500'000];
int cnt[8001];

int frequent(){
    bool moreThanTwo = false;
    int maxTimes = 0, value = 0;
    for(int i=0; i<8001; i++){
        // 새로운 최고빈도수가 나타날 경우 maxTimes 갱신, 처음이므로 moreThanTwo는 false로 변경
        if(cnt[i] > maxTimes){
            maxTimes = cnt[i];
            value = i-4000;
            moreThanTwo = false;
        }else if(cnt[i] == maxTimes && !moreThanTwo){ // #1 최대 빈도수가 두번째로 나타났을경우 해당값 보존 
            moreThanTwo = true;
            value = i-4000;
        }
    }

    return value;
}

void input(){
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        total += arr[i];
        cnt[arr[i]+4000]++;
    }
}

int main() {
	fastio;
	input();

    sort(arr,arr+n);

    // Checklist
    // 1. 최빈값 중 두번째로 작은 값을 출력하는가?
    // 2. -0을 출력하지 않는가?

    // 평균, 중앙, 최빈, 범위
    cout << round((float)total / n) + 0 << '\n'; // #2 +0을 통해 -0이 출력되지 않게 함
    cout << arr[n/2] << '\n';
    cout << frequent() << '\n';
    cout << arr[n-1] - arr[0] << '\n';

}