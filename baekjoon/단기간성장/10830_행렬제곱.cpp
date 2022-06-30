#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
#include <vector>
using namespace std;

#define MAX 5
using box = vector<vector<int>>;

int n;
long long b;

box A(MAX, vector<int>(MAX, 0));
box result(MAX, vector<int>(MAX, 0));

box multiply (box b1, box b2) {
    box tmpBox(MAX, vector<int>(MAX, 0));
    for(int y=0; y<n; y++) {
        for(int x = 0; x<n; x++) {
            int val = 0;
            for (int i=0; i<n; i++) {
                val += (b1[y][i] % 1000) * (b2[i][x] % 1000);
            }
            tmpBox[y][x] = val % 1000;
        }
    }

    return tmpBox;
}

void power (box b1, long long times) {
    while(times > 0) {
        if (times % 2 != 0) {
            result = multiply(result, b1);
        }

        times /= 2;
        b1 = multiply(b1, b1);
    }
}

int main() {
	fastio;

    // 행렬의 크기: N, 제곱할 횟수: B
    cin >> n >> b;

    // input A
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    // result 단위행렬로 초기화
    for(int i=0; i<n; i++) {
        result[i][i] = 1;
    }

    // 제곱
    power(A, b);

    // 행렬 출력
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

