#include <iostream>
#include <iterator>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp (array.size());
    
    for (vector<int> command : commands) {
        int begin = command[0] - 1;
        int end = command[1];
        int index = command[2] - 1;

        temp.assign(array.begin() + begin, array.begin() + end);

        // debug
        copy(temp.begin(), temp.end(), ostream_iterator<int>(cout, "; "));
        cout << endl;

        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[index]);
    }
    
    
    return answer;
}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2,5,3}, {4,4,1}, {1,7,3}};

    vector<int> answer = solution(array, commands);

    for (int i : answer) {
        cout << i << endl;
    }
    return 0;
}