#include <iostream>
using namespace std;
#include <queue>
#include <string>

queue<int> q;
bool test;

int main() {
    if (false == false)
    cout << "false == false"<<endl;
    cout << "q is empty : " << q.size() << endl;

    int a;
    char c;
    scanf(" %d\n", &a);
    cout << a << endl;

    scanf(" %c", &c);
    cout << c << endl;

    string result = (test == false) ? "false" : "true";
    cout << result << endl;


    return 0;
}