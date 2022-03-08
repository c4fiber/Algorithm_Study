#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

int n, count;
int col[15];

bool isOKtoPlace(int row){
    for (int i=0; i< row; i++){
        // 같은 열에 있거나 가로,세로 길이가 같으면 배치불가
        if (col[i] == col[row]
                || row - i == abs(col[row] - col[i]))
            return false;
    }
    return true;
}

void nqueen(int row){
    if ( n == row ){
        count ++;
    }else{
        for (int i=0; i<n; i++){
            col[row] = i;
            if ( isOKtoPlace(row) )
                nqueen(row+1);
        }
    }

    return;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    nqueen(0);
    cout << count << "\n";
    return 0;
}