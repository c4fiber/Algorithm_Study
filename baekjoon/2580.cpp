// dfs
// check함수를 반복적으로 사용해서 성능이 매우 좋지 않다.

#include <cstdio>
using namespace std;
#include <stack>

struct target{
    int row;
    int col;
};

bool sudoku[9][9];
bool row[9][9];
bool col[9][9];
bool square[9][9];
stack<target> s;

bool squareCheck(int row, int col, int value){
    int startR = row - (row % 3);
    int startC = col - (col % 3);
    for(int i=startR; i<startR+3; i++){
        for(int j=startC; j<startC+3; j++){
            if(sudoku[i][j] == value) return false;
        }
    }
    return true;
}

bool colCheck(int col, int value){
    for(int i=0; i<9; i++)
        if(sudoku[i][col] == value) return false;
    return true;
}

bool rowCheck(int row, int value){
    for(int i=0; i<9; i++)
        if(sudoku[row][i] == value) return false;
    return true;
}

void dfs(){
    if(s.empty()) return;

    int r = s.top().row;
    int c = s.top().col;
    for(int i=1; i<=9; i++){
        if(colCheck(c, i) && rowCheck(r, i) && squareCheck(r, c, i)){
            sudoku[r][c] = i;
            s.pop();
            dfs();

            if(!s.empty()){
                s.push({r,c});
                sudoku[r][c] = 0;
            }
        }
    }
}


void input(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] == 0) s.push({i,j});
        }
    }
}

void output(){
    for(int i=0; i<9-1; i++){
        for(int j=0; j<9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<9; i++)
        printf("%d ", sudoku[8][i]);
}

int main() {
    input();
	dfs();
    output();
    return 0;
}