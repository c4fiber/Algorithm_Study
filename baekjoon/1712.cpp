// 손익분기점
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long a, b, c;

void input() {
    cin >> a >> b >> c;
}

int main() {
	fastio;
	input();

    // 아무리 만들어도 손해면 끗
    if (c - b <= 0) {
	    cout << "-1" << '\n';
	    return 0;
    } else {
        cout << a / (c - b) + 1 << '\n';
    }

}