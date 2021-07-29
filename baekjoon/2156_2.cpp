#include <iostream>
using namespace std;

int computeMax(int a, int b) { return a > b ? a : b; }
int main () {

    int number, i, answer = 0;

    scanf("%d", &number);
    int wine[10003] = { 0, };
    int dp[10003] = { 0, };

    for (i = 3; i < number+3; i++) scanf("%d", &wine[i]);

    for (i = 3; i < number+3; i++) {
        dp[i] = computeMax(dp[i-3] + wine[i-1] + wine[i], dp[i-2] + wine[i]);
        dp[i] = computeMax(dp[i-1], dp[i]);
        answer = computeMax(answer, dp[i]);
    }

    printf("%d\n", answer);

    return 0;
}