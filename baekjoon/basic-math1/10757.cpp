#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#include <string>
#include <queue>
using namespace std;

string inputA, inputB;
queue<unsigned long long> a, b;


unsigned long long splitBigNumber(string num, int lenFromEnd) {
    char*tmp = num.substr(num.length()-lenFromEnd, num.length());
    num = 

    return stoull(tmp);
}

void input() {
    cin >> inputA >> inputB;
}

int main() {
	fastio;
	input();

    // split by 1e+19 -> 18자리 숫자
    while(inputA.length() > 0) {
        cout << splitBigNumber(inputA, 18);
    }
    
}