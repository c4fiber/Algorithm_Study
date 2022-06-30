#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int seperateRank(int height, int weight) {
    float bmi = (float)weight / (height * height) * 10000;

    if (height <= 140) {
        return 6;
    }else if (height < 146) {
        return 5;
    }else if (height < 159) {
        return 4;
    }else if (height < 161) {
        //BMI check
        if (16.0 <= bmi && bmi < 35.0) 
            return 3;
        else
            return 4;
    }else if (height < 204) {
        //BMI check
        if (20 <= bmi && bmi < 25) {
            return 1;
        }else if (18.5 <= bmi && bmi < 30) {
            return 2;
        }else if (16.0 <= bmi && bmi < 35) {
            return 3;
        }else {
            return 4;
        }
    }else {
        return 4;
    }
}


int main() {
	fastio;
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int h, w;
        cin >> h >> w;
        cout << seperateRank(h, w) << '\n';
    }

}
