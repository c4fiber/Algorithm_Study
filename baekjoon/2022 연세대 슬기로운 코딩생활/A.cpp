#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;

int x, n;

int main() {
	fastio;

    cin >> x;
    cin >> n;

    int receipt = 0;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        receipt += a*b;
    }

    if (x == receipt) {
        cout << "Yes";
    }else {
        cout << "No";
    }

    return 0;

}
