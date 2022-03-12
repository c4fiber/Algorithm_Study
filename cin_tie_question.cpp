#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    cout << "pointer of cout: " << cin.tie() << endl;
    cout << "cout is not tied to any other output stream: " << cin.tie()->tie() << endl;

    cout << endl;

    cout << "before untie cin to cout: " << cin.tie(0) << endl;
    cout << "after untie cin to cout: " << cin.tie() << endl;
    cout << " - tie to 0 == is not tied(?)" << endl;

    return 0;
}