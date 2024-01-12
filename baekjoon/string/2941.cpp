#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <string>
#include <map>
#include <algorithm>

// c, d, l, n, s, z 뒤에 뭐가오는가?
map<char,int> p = {{'c',0},{'d',1},{'l',2},{'n',3},{'s',4},{'z',5}};
string next[6][2] = {
						{"=", "-"},
						{"z=", "-"},
						{"j"},
						{"j"},
						{"="},
						{"="}
					};
string str;
int cnt;

void input() {
	cin >> str;
}

int main() {
	fastio;
	input();
	
	string temp
	while(str.find('='))
}