#include <iostream>
using namespace std;

long long int a, b, c;

long long int letMod(long long int round){
    if (round == 1)
        return a % c;
    
    long long int t = letMod(round/2);
    if (round % 2 == 0){
        return (t * t) % c;
    }else{
        return (t * t) % c * a % c;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> a;
    cin >> b;
    cin >> c;
    long long int result = letMod(b);
    
    cout << result << "\n";
    return 0;
}