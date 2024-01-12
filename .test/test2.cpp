#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> v(10, "TEST");

    cout << v[0][1] << endl;
    cout << typeid(v[0][0]).name() << endl;
    cout << typeid(char).name() << endl;
    
    return 0;
}