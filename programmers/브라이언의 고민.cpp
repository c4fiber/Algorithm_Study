#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<string> splitSentenceToWordsByLetter(string sentence, char c){
    vector<string> words;
    istringstream ss(sentence);
    string stringBuffer;

    while(getline(ss, stringBuffer, c)) {
        words.push_back(stringBuffer);
    }

    return words;
}

int checkRuleNumber(string sentence){
    char a, b = sentence[0], sentence[1];
    for(char c : sentence){
        if ()
    }
}

string solution(string sentence) {
    string answer = "";
    // rule 1 check

    // rule 2 check
    return answer;
}

int main() {
    string input1 = "HaEaLaLaObWORLDb";
    string answer1 = "HELLO WORLD";
    string input2 = "SpIpGpOpNpGJqOqA";
    string answer2 = "SIGONG JOA";
    string input3 = "AxAxAxAoBoBoB";
    string answer3 = "invalid";

    if (solution(input1).compare(answer1) == 0) {
        cout << "input 1 success!" << endl;
    }
    if (solution(input2).compare(answer2) == 0) {
        cout << "input 1 success!" << endl;
    }
    if (solution(input3).compare(answer3) == 0) {
        cout << "input 1 success!" << endl;
    }

    vector<string> v = splitSentenceToWordsByLetter(answer1, ' ');
    for (string s : v){
        cout << s << endl;
    }
}