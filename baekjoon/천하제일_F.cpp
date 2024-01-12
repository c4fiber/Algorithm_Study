#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
#include <vector>
using namespace std;

vector<int> a,b,c,d, e;

int tc, n, t;


int main() {
	fastio;

    cin >> tc;

    for(int testNum=0; testNum<tc; testNum++) {
        // 각 test case
        cin >> n >> t;

        // N+1개줄
        for(int i=0; i<n; i++) {
            int a_, b_, c_, d_;
            cin >> a_ >> b_ >> c_ >> d_;

            a.push_back(a_);
            b.push_back(b_);
            c.push_back(c_);
            d.push_back(d_);
        }




        a.clear();
        b.clear();
        c.clear();
        d.clear();
    }


}
