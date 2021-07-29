#include <iostream>
using namespace std;

// int: stud 'xxxyyy' 상수로 나타냄
int routeWayOut(char* map[], int xy, int openedDoors){
    

    return openedDoors + routeWayOut(map, xy + 1000, openedDoors)
        + routeWayOut(map, xy - 1000, openedDoors)
        + routeWayOut(map, xy + 1, openedDoors)
        + routeWayOut(map, xy-1, openedDoors);
}

int main() {
    int cases, height, width;
    char map[100][100] = {};
    cin >> cases;

    for (int i=0; i<cases; i++){
        cin >> height >> width;

        for (int j=0; i<height; j++){
            cin >> map[j];
        }
    }
}