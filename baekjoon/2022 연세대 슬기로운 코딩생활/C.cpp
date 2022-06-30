#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;

long long a, b;


int main() {
	fastio;

    cin >> a >> b;


    long long result = b;
    for(long long i=a; i<b; i++) {
        result = result ^ i;
    }
    
    cout << result;


    return 0;
}
