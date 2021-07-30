#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> student1 = {1, 2, 3, 4, 5};
vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> score = {0, 0, 0, 0};
    int max = -1;

    for (int i = 0; i < answers.size(); i++) {
        // student 1
        if (student1[i % student1.size()] == answers[i]) {
            score[1] += 1;

            if (score[1] > max) {
                max = score[1];
            }
        }
        // student 2
        if (student2[i % student2.size()] == answers[i]) {
            score[2] += 1;

            if (score[2] > max) {
                max = score[2];
            }
        }
        // student 3
        if (student3[i % student3.size()] == answers[i]) {
            score[3] += 1;

            if (score[3] > max) {
                max = score[3];
            }
        }
    }

    vector<int> highscoreStudents;
    for (int i = 0; i < score.size(); i++) {
        if (score[i] == max) {
            highscoreStudents.push_back(i);
        }
    }

    return highscoreStudents;
}

int main() {
    vector<int> answers = {1, 2, 3, 4, 5};
    answers = solution(answers);

    for (int i : answers) {
        cout << i << endl;
    }
}