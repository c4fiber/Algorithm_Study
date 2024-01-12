#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;

#include <deque>

deque<pair<int,int>> balloons;
int n;


int main() {
	fastio;

    // input
    cin >> n;
    for(int i=1; i<=n; i++) {
        int next;
        cin >> next;

        balloons.push_back({i, next});
    }

    while(!balloons.empty()) {
        auto current = balloons.front();
        cout << current.first << ' ';

        int next = current.second;
        balloons.pop_front();

        if(next > 0) {
            next--;

            while(next != 0) {
                balloons.push_back(balloons.front());
                balloons.pop_front();

                next--;
            }
        }else {
            while(next != 0) {
                balloons.push_front(balloons.back());
                balloons.pop_back();

                next++;
            }
        }
        
    }


    return 0;
}
