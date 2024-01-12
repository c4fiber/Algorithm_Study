// d(n)은 n과 n의 각 자리수를 더하는 함수

#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;


bool isNotSelfNum[20'000];

void markNotSelfNumber(int input) {
	int nextSelfNum = input;

	while(input) {
		nextSelfNum += input % 10;
		input /= 10;
	}

	isNotSelfNum[nextSelfNum] = true;
}

int main() {
	fastio;


	for(int i=1; i<10'000; i++) {
		markNotSelfNumber(i);
	}

	for(int i=1; i<10'000; i++) {
		if(!isNotSelfNum[i])
			cout << i << '\n';
	}

	return 0;
}
