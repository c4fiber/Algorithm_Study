#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#include <vector>

vector<int> scores;

void input(){
    int n;
    cin >> n;
    cout << fixed; // 소숫점 자릿수 고정
    cout.precision(3); // 소숫점 4번째 자리에서 반올림

    for(int i=0; i<n; i++){
        int m, cnt=0, total = 0;
        cin >> m;
        
        // 평균 구하기
        for(int i=0; i<m; i++){
            int score;
            cin >> score;
            total += score;
            scores.push_back(score);
        }
        double average = (double)total / m;

        // 비율 구하기
        for(int i=0; i<m; i++){
            if(scores[i] > average) cnt++;
        }
        
        
        cout << (double)cnt / m * 100 << '%' << '\n';
        scores.clear();
    }
    
    
}

int main() {
	fastio;
	input();
	
}