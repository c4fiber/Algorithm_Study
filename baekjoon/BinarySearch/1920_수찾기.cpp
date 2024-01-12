#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <algorithm>

int n, m;
int pick[100'000]; // 내가 가진 수
int base[100'000]; // 주어진 수


bool binarySearch(int lo, int hi) {
	if (hi - lo <= 1) {
		
	}
}

void input() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> base[i];
	cin >> m;
	for (int i=0; i<n; i++) cin >> pick[i];
}

int main() {
	fastio;
	input();
	
	sort(base, base+n);
	sort(pick, pick+m);


}