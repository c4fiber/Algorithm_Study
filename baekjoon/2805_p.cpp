#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0) 
// https://velog.io/@c4fiber/cin.tieNULL-syncwithstdiofalse 세부내용 정리
using namespace std;

// https://www.acmicpc.net/blog/view/109
// 익숙하게 작성할 수 있도록 연습

int n, m, v[1'000'000]; 
// https://velog.io/@c4fiber/%EC%83%81%EC%88%98-%EC%82%AC%EC%9D%B4%EC%97%90-%EB%94%B0%EC%98%B4%ED%91%9C 세부내용 정리

bool check(const int mid){
	long long sum = 0;
	for(int i=0; i<n; i++) {
		if(v[i] > mid) sum += v[i] - mid;
	} 
	return sum >= m;
}

void input(){
    cin >> n >> m;
	for (int i=0; i<n; i++) cin >> v[i];
}

int main() {
	fastio;
	input();
	
	// 이분탐색
	int lo = 0, hi = 1'000'000'000;
	// 정답을 위한 Checklist
	// 1. check(lo) = F, check(hi) = T를 만족하는가?
	// 2. lo를 기준으로 판단할 것이므로 lo가 모든 범위 (0 ~ max(v))를 만족하는가? (정답은 0 ~ max(v)-1, m의 최솟값은 1이므로)

	while(lo + 1 < hi) { // #1 lo < mid < hi 를 만족하는가?
		int mid = (lo + hi) / 2; // ##1 항상 lo < mid < hi 만족
		if(check(mid)) lo = mid;
		else hi = mid;
	} 
    cout << lo << endl;
}