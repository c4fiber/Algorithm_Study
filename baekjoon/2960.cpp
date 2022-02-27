#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> line;

    for (int i=2; i<=n; i++){
        line.push_back(i);
    }

    for (int i=0; i<n; i++){
        int minNum = line.front();
        for (int j=minNum; j <= line.back(); j += minNum){
            int size = line.size();            
            line.erase( remove(line.begin(),line.end(),j), line.end()); 

            // 원소가 없으면 k값을 줄이면 안된다.
            if (size > line.size())
                k--;

            if (k == 0){
                cout << j;
                return 0;
            }
        }
    }

    return 0;
}