#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
int arr[1000];

void input(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

}

int main() {
	fastio;
    input();
    // 버블정렬
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
	
    for(int i=0; i<n; i++)
        cout << arr[i] << '\n';
}