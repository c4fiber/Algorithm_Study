#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <algorithm>

int n;
int arr[10];

bool compare(const int a, const int b){
    return a > b;
}

void input(){
    cin >> n;
}

int main() {
	fastio;
	input();

    int i=10, index = 0;
    while(n != 0){
        arr[index++] = n % i;
        n /= 10;
    }

    sort(arr, arr+index, compare);

    for(int i=0; i<index; i++){
        cout << arr[i];
    }
	
}