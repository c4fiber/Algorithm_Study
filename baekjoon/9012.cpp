#include <iostream>
#include <vector>
using namespace std;

bool checkVPS(string);

int main() {
    int rownum = 0;
    cin >> rownum;

    for (int i=0; i<rownum; i++) {
        string row;       
        cin >> row;
        
        cout << (isVPS(row) ? "YES" : "NO") << endl;
    }

    return 0;
}

bool isVPS(string row) {
    vector<char> stack;
    for (int j=0; j<row.length(); j++) {
            if (row[j] == '(')
                stack.push_back(row[j]);
            else if (stack.empty()) // ')' AND stack is empty
                return false;
            else
                stack.pop_back();
    }
    if (stack.empty()) return true;

    return false;
}