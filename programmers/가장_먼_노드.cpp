#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> conInfo(n+1);
    vector<unsigned char> visited(n+1, false);
    vector<int> distance(n+1, 0);
    queue<int> q;


    for(int i = 0 ; i < edge.size(); i++) {
        int start = edge[i][0];
        int end = edge[i][1];

        conInfo[start].push_back(end);
        conInfo[end].push_back(start);
    }

    q.push(1);
    visited[1] = true;

    //BFS
    while(!q.empty()) {
        int startNode = q.front();
        q.pop();

        for(int i = 0; i < conInfo[startNode].size(); i++) {
            int endNode = conInfo[startNode][i];
            if (!visited[endNode]) {
                visited[endNode] = true;
                distance[endNode] = distance[startNode] + 1;
                q.push(endNode);
            }
        }
    }

    sort(distance.begin(), distance.end(), compare);

    for(auto d : distance) {
        if(d == distance[0])
            answer++;
    }


    return answer;
}

int main() {
    int n = 6;
    vector<vector<int>> vertex = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    cout << solution(n, vertex) << endl;

}