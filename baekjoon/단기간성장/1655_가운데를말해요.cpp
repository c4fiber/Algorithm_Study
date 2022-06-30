
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <queue>
#include <vector>

int n;
priority_queue<short, vector<short>, greater<short>> hi;
priority_queue<short,vector<short>, less<swhort>> lo;

void input() {
    cin >> n;
}

int main() {
	fastio;
	input();

    // Checklist
    // 1. 항상 lo의 개수는 hi의 개수와 같거나 1 큰가?
    // 2. lo.top() <= hi.top()을 만족하는가?

    // 우선순위 큐 (하위 lo: max heap, 상위 hi: min heap)
    for(int i=0; i<n; i++) {
        short v;
        cin >> v;

        if(lo.size() <= hi.size()) lo.push(v); // #1
        else hi.push(v);

        while(!hi.empty() && lo.top() > hi.top()) { // #2 lo.top <= hi.top 을 만족해야 한다.
            int loTop = lo.top();
            int hiTop = hi.top();

            lo.pop();
            hi.pop();

            lo.push(hiTop);
            hi.push(loTop);
        }

        // Output
        cout << lo.top() << '\n';
    }
}