#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <algorithm>

int n;
int arr[1'000'000];

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}

int main() {
	fastio;
	input();

    // 내장함수 사용
    sort(arr, arr+n);
    for(int i=0; i<n; i++)
        cout << arr[i] << '\n';
  
    
}