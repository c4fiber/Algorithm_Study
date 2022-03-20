// 다이얼
#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <string>

int alphaToNum[10] = {3,3,3,3,3,4,3,4};
string word;

void input() {
    for(int i=0; i<9; i++)
        alphaToNum[i+1] += alphaToNum[i];

    cin >> word;
}

int main() {
	fastio;
	input();

    int totalSec = 0;
    for(int i=0; i<word.length(); i++) {
        int c = word[i] - 65;
        for(int j=0; j<9; j++) {
            if (c < alphaToNum[j]) {
                totalSec += j+3;
                break;
            }
        }
    }

    cout << totalSec << '\n';
	

}
