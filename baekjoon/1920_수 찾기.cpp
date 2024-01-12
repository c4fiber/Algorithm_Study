#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> A;
int val;


int main() {
	fastio;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> val;   
        A.push_back(val);
    }

    sort(A.begin(), A.end());

    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> val;

        if (binary_search(A.begin(), A.end(), val))
            cout << '1' << '\n';
        else 
            cout << '0' << '\n';
    }
    
    return 0;
}
