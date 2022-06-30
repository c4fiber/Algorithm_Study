#include <stdio.h>

int main() {
    char text[5] = "CERT";

    sprintf(text+1, "%c", 'A');

    printf("%s\n", text);


    return 0;
}