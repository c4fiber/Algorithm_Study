#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int weight[101];
int value[101];
int dp[101][100'001];

int main() {
	fastio;

    int n, limit;
    cin >> n >> limit;

    // input things
    for (int i=1; i<=n; i++) {
        cin >> weight[i] >> value[i];
    }

    /**
     *  Checklist
     *  1. 모든 물건을 넣으려고 시도하는가 i: 1 ~ n
     *  2. 이전의 최대값과 현재 값을 넣었을 때의 최대값을 비교하는가
     */
    for(int i=1; i<=n; i++) {
        for (int j=1; j<=limit; j++) {
            if (weight[i] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][limit];

    return 0;
}
