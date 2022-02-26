#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 이분탐색 */
long long solution(int n, vector<int> times) {    
    sort(times.begin(), times.end()); // 입력값이 오름차순임이 명시되지 않았음

    long long low = times[0];
    long long high = times[times.size()-1] * n;
    long long answer = high; // 소요시간

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long passed = 0;

        for (int i=0; i<times.size(); i++) 
            passed += mid / times[i];

        if (passed >= n) {
            if (answer >= mid)
                answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}