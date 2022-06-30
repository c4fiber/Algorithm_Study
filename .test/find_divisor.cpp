#include <iostream>
#include <vector>
#include <limits.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template <typename T>
bool isPerfectNumber(T n) {
    T sumOfDivisors = 0;
    for(T i=1; i<n; i++) {
        if (n % i == 0)
            sumOfDivisors += i;
    }

    if (sumOfDivisors == n) {
        return true;
    }   

    return false;
}

int main() {
	fastio;
    vector<unsigned long long> perfectNums;
    int k;
    cout << "input k: ";
    cin >> k;
    
    for (unsigned long long i=1; i < ULONG_MAX; i++) {
        if (isPerfectNumber(i)) {
            perfectNums.push_back(i);
            cout << i << '\n';
        }
        if (perfectNums.size() <= k) {
            break;
        }
    }

    cout << "answer : " << perfectNums.back() << '\n';


    return 0;
}
