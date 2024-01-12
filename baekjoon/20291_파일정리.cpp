#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;

#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

int n;
map<string,int> numOfFilesByExt;
vector<string> exts;

// split 함수 임의 구현
vector<string> split (string input, char seperator) {
    vector<string> result;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, seperator)) {
        result.push_back(temp);
    }

    return result;
}

int main() {
	fastio;

    cin >> n;
    for(int i=0; i<n; i++) {
        string input;
        cin >> input;

        vector<string> result = split(input, '.');

        // 기존에 입력된 확장자 체크, 없으면 추가
        if (find(exts.begin(), exts.end(), result[1]) != exts.end()) {
            exts.push_back(result[1]);
            numOfFilesByExt[result[1]] = 0;
        }

        numOfFilesByExt[result[1]] += 1;
    }

    // map은 keys 기준으로 정렬되어 있음. 바로 출력
    for(auto it : numOfFilesByExt) {
        cout << it.first << ' ' << it.second << '\n';
    }


    return 0;
}
