#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;

int main() {
	fastio;

    cin >> n >> k;

    vector<int> scores;
    for(int i=0; i<n; i++) {
        int score;
        cin >> score;
        scores.push_back(score);
    }

    sort(scores.begin(), scores.end(), [](const int a, const int b) {return a>b;});

    cout << scores[k-1];


    return 0;
}
