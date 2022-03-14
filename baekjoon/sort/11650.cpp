#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <algorithm>

struct cord{
    int x;
    int y;
};

int n;
cord arr[100'000];

bool compare(const cord a, const cord b){
    if(a.x != b.x){
        return a.x < b.x;
    }else{
        return a.y < b.y;
    }
}

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i].x;
        cin >> arr[i].y;
    }
}

int main() {
	fastio;
	input();
	
    sort(arr, arr+n, compare);

    for(int i=0; i<n; i++){
        cout << arr[i].x << " " << arr[i].y << '\n';
    }
}