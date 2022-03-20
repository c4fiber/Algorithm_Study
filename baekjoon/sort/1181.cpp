#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

int n;
vector<string> words;


bool compare(const string a, const string b){
    if(a.length() != b.length()){ // #2
        return a.length() < b.length();
    }else {
        for(int i=0; i<a.length(); i++){ // #1
            if(a[i] != b[i]) { // #3
                return a[i] < b[i];
            }
        }
        return a < b; // 길이가 같고, 다른 글자가 없다 = 단어가 일치한다.
    }
}

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }
}

int main() {
	fastio;
	input();
	
    // Checklist
    // 1. 모든 글자를 비교하는가? (인덱스 범위 0 ~ string.length()-1)
    // 2. 길이가 오름차순인가? 
    // 3. 길이가 같다면 알파벳이 오름차순인가?
    // 4. 중복을 제거하는가?

    sort(words.begin(), words.end(), compare);

    string before = "";
    for(auto s : words){
        if( s == before) { // #4
            continue;
        }else {
            cout << s << '\n';
            before = s;
        }
    }
}