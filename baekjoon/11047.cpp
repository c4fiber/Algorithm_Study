#include <iostream>
using namespace std;

int main() {
    int coinNum = 0;
    int n, k;
    cin >> n >> k;

    int coinKinds[10] = {};
    for (int i = n-1; i >= 0; i--) {
        cin >> coinKinds[i];
    }

    for (int i=0; i < n  && k != 0; i++) {
        coinNum  += k / coinKinds[i];
        k %= coinKinds[i];
    }

    cout << coinNum << endl;
    
    return 0;
}