#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
using namespace std;

#include <list>

list<char> notepad;
list<char>::iterator cursor;
int n;


int main() {
	fastio;

    string init;
    cin >> init;
    for(char c : init) {
        notepad.push_back(c);
    }
    cursor = notepad.end();

    cin >> n;
    char c;
    for(int i=0; i<n; i++) {
        cin >> c;
        switch(c) {
            case 'L': // 왼쪽 커서이동
                if (cursor != notepad.begin())
                    cursor--;
                break;
            case 'D': // 오른쪽 커서이동
                if (cursor != notepad.end())
                    cursor++;
                break;
            case 'B': // 왼쪽 글자 지우기
                if (cursor != notepad.begin()) {
                    cursor = notepad.erase(--cursor);
                }
                break;
            case 'P': // 왼쪽에 글자 추가
                cin >> c;
                cursor = notepad.insert(cursor, c)++;
                break;
            default: // 입력값이 잘못되면 에러 출력
                cout << "ERROR!!" << '\n';
                return 1;
        }
    }
    
    for(char c : notepad) {
        cout << c;
    }

    return 0;
}
