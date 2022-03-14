// 나이순 정렬
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <algorithm>
#include <vector>
#include <string>

int n;
vector<pair<int,string>> arr;

bool compare(const pair<int,string> a, const pair<int,string> b){ // #2 나이만 비교함.
    return a.first < b.first;
}

void input(){
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        string b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
}

int main() {
	fastio;
	input();

    // Checklist
    // 1. 가입순서를 지키는가? 
    // 2. 나이를 오름차순으로 정렬했는가?

    stable_sort(arr.begin(), arr.end(), compare); // #1 stable_sort 사용

    for(auto c : arr) {
        cout << c.first << ' ' << c.second << '\n';
    }
	
}