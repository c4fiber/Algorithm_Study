#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <string>
#include <algorithm>

void input() {

}

int main() {
	fastio;
	input();
	
    string str;
    cin >> str;

    bool multipleCharacterFreq = false;
    pair<char,int> stat = {'A',0};
    for(char c='A'; c <= 'Z'; c++) {
        int cnt = count(str.begin(), str.end(), c);
        cnt += count(str.begin(), str.end(),c+32);

        if(stat.second == cnt) {
            multipleCharacterFreq = true;
        }else if (stat.second < cnt) {
            stat.first = c;
            stat.second = cnt;
            multipleCharacterFreq = false;
        }
    }

    if(multipleCharacterFreq) cout << "?\n";
    else cout << stat.first << '\n';
	
	// Output
}