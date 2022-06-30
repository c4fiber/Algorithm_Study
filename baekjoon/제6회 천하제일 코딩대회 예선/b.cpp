#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int getLastDay(int month) {
    switch(month) {
        case 2:
            return 28;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
    }

    return -1;
}

bool yoonYear(int year) {
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0 ) {
        return true;
    }else {
        return false;
    }
}

int main() {
	fastio;
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int year, month, day;
        cin >> year >> month;
        
        if (month == 1) {
            year -= 1;
            month = 12;
        }else {
            month -= 1;
        }
        
        day = getLastDay(month);
        if (yoonYear(year) && month == 2) {
            day += 1;
        }
        
        cout << year << ' ' << month << ' ' << day << '\n';
    }

}
