#include <iostream>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
#include <vector>
#include <algorithm>

int n;
vector<pair<unsigned int,unsigned int>> coord;

int main() {
	fastio;

    // Input
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        coord.push_back({x+1e9,i});
    }

    // Checklist
    // 1. 출력순서는 1 ~ N 인가?
    // 2. Xi > Xj 를 만족할 때 X'i 는 서로다른 Xj의 개수인가?

    sort(coord.begin(), coord.end());

    int arr[n];
    int beforeMaxValue = coord[0].first; // 지금까지의 최대 좌표값
    int numOfUnderValue = 0;
    for(int i=0; i<n; i++) {
        if(coord[i].first > beforeMaxValue) { // #2 더 큰 Xi가 나오면 기준값 변경
            beforeMaxValue = coord[i].first;
            numOfUnderValue++; // 조건을 만족하는 Xj의 개수
        }
        arr[coord[i].second] = numOfUnderValue; // #1 기존 인덱스에 조건에 맞는 값 개수 저장
    }

    // Output
    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
	
}