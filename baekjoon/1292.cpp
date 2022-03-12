#include <iostream>
using namespace std;

int main() {
    int start = 0, sum = 0;
    int first, last, cnt;
    cin >> first;
    cin >> last;
    cnt = last - first + 1;

    // start = 구간 처음 숫자의 인덱스

    int i, j;
    for (i=1; i <= 1000; i++) {
        start = start + i;

        if (start >= first) {
            sum += i * (start - first + 1);
            first = start+1;
        }

        if (start >= last) {
            sum -= i * (start - last);
            break;
        }
    }
    cout << sum << endl;
    return 0;
}