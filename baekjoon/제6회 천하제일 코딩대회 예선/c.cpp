#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <vector>
#include <string>

int main() {
	fastio;
    int n;
    cin >> n;
    string answer = "YES";

    vector<int> array;
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        for (int j=0; j<k; j++) {
            int temp;
            cin >> temp;
            array.push_back(temp);
        }

        
        for (int x = 0; x < k/2; x++) {
            int max1 = max(array[x], array[k-1-x]);
            int min1 = min(array[x], array[k-1-x]);

            for (int y = x+1; y < k/2+1; y++) {
                int max2 = max(array[y], array[k-1-y]);
                int min2 = min(array[y], array[k-1-y]);

                if (max1 < max2 || min1 > min2) {
                    answer = "NO";
                    break;
                }
            }
        }

        cout << answer << '\n';
        array.clear();
    }

    return 0;
}
