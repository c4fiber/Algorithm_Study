/* 소숫점 자릿수 + 나누기 연산에 대한 이해 */
// precision을 이용해서 출력할 소숫점 자릿 수를 조절할 수 있다.

#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a;
    cin >> b;
    
    cout.precision(19);
    cout << (double)a/b << endl;
    return 0;
    
}