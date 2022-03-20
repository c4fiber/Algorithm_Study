#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
long long hand[500'000];

bool check(const long long value) {
	// 이분탐색
	int lo = 0, hi = n;
	// Checklist
	// 1. v[lo] <= value < v[hi] 를 만족하는가?
	// 2. lo가 정답이 될 수 있는 모든 범위를 표현할 수 있는가? (인덱스 범위는 0 ~ n-1)
	// 3. 찾아낸 인덱스의 값이 원하는 값과 일치하는가?

	while(lo + 1 < hi) { // #1 lo < mid < hi 를 항상 만족하는가?
		int mid = (lo + hi) / 2; // ##1 항상 lo < mid < hi
		if(hand[mid] <= value) lo = mid;
		else hi = mid;
	}

	return hand[lo] == value;
}

void input() {
    cin >> n;
	for(int i=0; i<n; i++) cin >> hand[i];
	cin >> m;
}

int main() {
	fastio;
	input();

	// 이분탐색을 위한 sort
	sort(hand, hand+n);

	// 놓여진 카드를 모두 확인한다.
	for(int i=0; i<m; i++) {
		long long value;
		cin >> value;
		if(check(value)) cout << "1 ";
		else cout << "0 ";
	}
}