#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <string>

string str1, str2;

void input() {
    cin >> str1;
    cin >> str2;
}

int main() {
	fastio;
	input();
	
    bool answerIsFirst = false;
    for(int i=3; i>=0; i--) {
        if (str1[i] > str2[i]) {
            answerIsFirst = true;
            break;
        }
        else if (str1[i] < str2[i]) {
            answerIsFirst = false;
            break;
        }
    }

    
    if(answerIsFirst) {
        string result(str1.crbegin(), str1.crend());
        cout << result << '\n';
    }else {
        string result(str2.crbegin(), str2.crend());
        cout << result << '\n';
    }
}