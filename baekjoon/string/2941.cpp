#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <string>
#include <algorithm>

string words[10] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
string str;
int cnt;

void input() {
	cin >> str;
}

int main() {
	fastio;
	input();
	
	for(int i=0; i<str.length()-2; i++) {
		for (int j=0; j<10; j++) {
			if(str.substr(i,2) == words[j]) {
				str[i] = '?';
				str[i+1] = '?';
				cnt += 1;
				break;
			}
			if(str.substr(i,3) == words[j]) {
				str[i] = '?';
				str[i+1] = '?';
				str[i+2] = '?';
				cnt += 2;
				break;
			}
		}
	}

	cnt  = count(str.begin(), str.end(), '?') / 2;
	cout << str.length() - cnt << '\n';
}