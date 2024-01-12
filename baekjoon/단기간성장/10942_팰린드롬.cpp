// brute force 시간초과 -> DP로 해결
// 메모아이제이션

#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;

int N, M;
int nums[2001];
bool memoi[2001][2001];

bool palindrom(int s, int e) {
    if (memoi[s][e]) return true;

    if(nums[s] == nums[e] && palindrom(s+1, e-1)) {
        memoi[s+1][e-1] = true;
        return true;
    }else {
        return false;
    }
}

int main() {
	fastio;

    // input
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> nums[i];
    }
    cin >> M;

    // init
    for(int i=1; i<=N; i++) {
        memoi[i][i] = true;
    }
    for(int i=1; i<=N-1; i++) {
        if(nums[i] == nums[i+1])
            memoi[i][i+1] = true;
    }

    // solution
    for(int index=0; index<M; index++) {
        int s, e;
        cin >> s >> e;

        cout << palindrom(s,e) << '\n';

    }
    
    return 0;
}
