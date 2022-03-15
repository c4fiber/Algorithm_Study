#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <string>

int n;

void input() {
    cin >> n;
}

int main() {
	fastio;
	input();
	
    for(int i=0; i<n; i++) {
        int times;
        cin >> times;
        string str;
        cin >> str;
        for(int k=0; k<str.length(); k++) {
            for(int j=0; j<times; j++) {
                cout << str[k];
            }
        }
        cout << '\n';
    }
}