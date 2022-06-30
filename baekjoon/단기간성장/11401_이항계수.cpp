/**
 * 모듈러 연산 활용
 * 페르마 소정리, 오일러 정리
 */ 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long power(long long x, long long y, long long p) {
    long long ans = 1;
    while (y > 0) {
        if (y%2 != 0) {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
        y/=2;
    }
    return ans;
}

int main() {
	fastio;
    long long n, k, p;
    p = 1'000'000'007;
    cin >> n >> k;

    // (A * B^-1) mod p [A: n!, B: k!(n-k)!]
    // B^p-1 합동 1 mod p (페르마 소정리)
    // B^p-2 * B 합동 1 mod p -> B^p-2 합동 B^-1 mod p
    // 따라서 A * B^-1 합동 A * B^p-2 mod p
    long long A = 1, B = 1;
    for(long long i=1; i<=n; i++) {
        A = A * i % p;
    }

    for(long long i=1; i<=k; i++) {
        B = B * i % p;
    }
    for (long long i=1; i<=n-k; i++) {
        B = B * i % p;
    }

    // B = ! * (n-k)! mod p
    B = power(B, p-2, p);

    cout << A * B % p << '\n';

    return 0;
}
