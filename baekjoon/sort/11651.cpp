// 좌표 정렬하기

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <vector>
#include <algorithm>

int n;
vector<pair<int,int>> cord;

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        cord.push_back({y,x});
    }
}

int main() {
	fastio;
	input();
	
    // pair를 sort할 경우 first, second 모두 정렬됨
    // 사용하는 알고리즘은 intro sort (quick + heap)
    sort(cord.begin(), cord.end());

    // 컴파일러 입장에서 들어있는 값을 충분히 예측할 수 있다면 오히려 성능향상
    for(auto c : cord){
        cout << c.second << ' ' << c.first << '\n';
    }
}