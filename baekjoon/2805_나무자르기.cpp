#include <iostream>
#include <cstdio>
using namespace std;
#include <vector>

int N, M;
int v[1'000'000];
vector<int> trees;

long long cut(int cutLength){
    long long getWoods = 0;
    for(int i=0; i<N; i++){
        if(trees[i] > cutLength)
            getWoods += trees[i] - cutLength;
    }

    return getWoods;
}

int getWood(int begin, int end){
    int mid = (begin + end) / 2;
    long long woods = cut(mid);

    if(end - begin <= 1){
        if(woods >= M)
            return begin;
        else
            return end;
    }
        
    return woods < M ? getWood(begin, mid) : getWood(mid ,end);
}

void input(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        int length;
        scanf(" %d", &length);
        trees.push_back(length);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    input();
	cout << getWood(0,1000000000) << '\n';
    return 0;
}