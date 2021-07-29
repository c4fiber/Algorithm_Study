#include <iostream>
using namespace std;

int main() {
    int n, total;
    int min = 10000000;
    int wine[10000] = {};

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> wine[i];
        total += wine[i];
    }

    cout<<"test"<<endl;

    for (int i=0; i < n; i++){
        int tmp = 0;
        for (int j=i%4; j<n; j+3){
            tmp = tmp + wine[j];
        }
        if (min > tmp){
            min = tmp;
        }
    }
    cout << total - 2*min << endl;

}