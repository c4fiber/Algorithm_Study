#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;

#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

vector<int> v; 
int n;
int m;

int main() {
    fastio;

    cin >> n;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    cin >> m;
    for(int i=0; i<m; i++) {
        int input;
        cin >> input;

        if (binary_search(v.begin(), v.end(), input)) {
            cout << upper_bound(v.begin(), v.end(), input) - lower_bound(v.begin(), v.end(), input) << ' ';
        }else {
            cout << '0' << ' ';
        }
    }


    return 0;
}
// 10816
