#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    std::cout << "test" << std::endl;
    vector<int> v (10);

    v[2] = 1;

    cout << v.front() << endl;
    cout << v[2] << endl;
    
    v[0] = 2;
    cout << v.front() << endl;

    return 0;
}
