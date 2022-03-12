#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

int n, k;
vector<long long> lines;

// length 길이로 잘랐을 때 얻을 수 있는 랜선 개수
long long howManyLines(long long length){
    long long t = 0;
    for (int i=0; i<k; i++)
        t += lines[i] / length;
    
    return t;
}

long long getMaxLength(long long min, long long max){
    long long mid = (min + max) / 2;
    long long LANs = howManyLines(mid);

    // 모든 경우에서 mid를 최대로 높이려고 시도한 상태. 수렴한 mid로 결과를 도출할때 LANs 가 n보다 작을 확률이 있음
    if (max - min <= 1){
        if (LANs < n)
            return mid-1;
        else 
            return mid;
    }

    // 랜선 n개 이상을 얻었을 경우 길이를 늘린다. (n개를 얻어도 이 중에서 최대 길이를 찾아야 함)
    return LANs >= n ? getMaxLength(mid+1, max)
        : getMaxLength(min, mid-1);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> k >> n;
    
    for (int i=0; i<k; i++){
        long long line; cin >> line;
        lines.push_back(line);
    }

    cout << getMaxLength(1, pow(2,31)) << "\n";
    cin >> k;
    return 0;
}