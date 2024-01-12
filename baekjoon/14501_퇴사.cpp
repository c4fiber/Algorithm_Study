//퇴사
// 최대 이익 -> 그리디?
// 미완성

#include <iostream>
using namespace std;
#include <vector>

int N;
vector<vector<int>> table;

int calcMaxPay(int pick, int totalPay) {
    if (pick > N){
        return 0;
    }

    int taken = table[pick].front();
    int pay = table[pick].back();

    return pay+ calcMaxPay(pick + taken, totalPay+pay);
}

int main() {
    cin >> N;
    

    for (int i=0; i<N; i++){
        int taken, pay;
        cin >> taken;
        cin >> pay;

        table[i].push_back(taken);
        table[i].push_back(pay);
    }

    int maximum;
    for (int i=0; i<N; i++){
        maximum = max(maximum, calcMaxPay(table, i));
    }

    cout << maximum;

}