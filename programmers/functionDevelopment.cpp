#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int completedProgressesNumber;
    int spendDays;
    int isReleased = -1;

    for (int i = 0; i < progresses.size(); i++) {
        if (progresses[i] == isReleased) continue;

        spendDays = (99 - progresses[i]) / speeds[i] + 1;
        completedProgressesNumber = 1;

        for (int j = i + 1; j < progresses.size(); j++) {  // 같은날 배포 가능한 작업 찾기
            if (progresses[j] + speeds[j] * spendDays >= 100) {
                completedProgressesNumber += 1;
                progresses[j] = isReleased;
            } else {
                break;
            }
        }

        answer.push_back(completedProgressesNumber);
    }

    return answer;
}

int main() {
    vector<int> progresses;
    vector<int> speeds;
    vector<int> answer;

    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);

    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);

    answer = solution(progresses, speeds);

    for (const auto &i : answer) {
        cout << i << endl;
    }
}