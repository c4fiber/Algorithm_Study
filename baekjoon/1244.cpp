// 남자: 배수에 해당하는 스위치 조작
// 여자: 양 옆으로 한칸씩 체크하여 같은 상태일 경우 조작 + 반복 (다른 상태면 조작 X)

#include <iostream>
#include <vector>
using namespace std;

int n;

void maleFunction(vector<bool> &status, int num) {
    for (int i=1; num*i<=n; i++){
        status[num*i] = !status[num*i];
    }
}

void femaleFunction(vector<bool> &status, int num){
    status[num] = !status[num];
    for (int i=1; 1 <= num-i && num+i <= n; i++){
        if (status[num+i] == status[num-i]){
            status[num+i] = !status[num+i];
            status[num-i] = !status[num-i];
        } else {
            break;
        }
    }
}

int main() {
    vector<bool> status = {true};

    //set switches
    cin >> n;
    for (int i=0; i<n; i++){
        bool value;
        cin >> value;
        status.push_back(value);
    }

    // tweak switches
    int numOfInput;
    cin >> numOfInput;

    for (int i=0; i<numOfInput; i++){
        int isMale, num;
        cin >> isMale;
        cin >> num;

        if (isMale == 1) {
            maleFunction(status, num);
        }else if (isMale == 2) {
            femaleFunction(status, num);
        }
    }

    // result
    for (int i=1; i<=n; i++){
        cout << status[i] << " ";
        if (i % 20 == 0){
            cout << endl;
        }
    }

    return 0;
}