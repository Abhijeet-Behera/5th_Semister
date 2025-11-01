//for taking input from the cmd line wewill use -> fgets(S,50,stdin)
//for taking input from the user wewill use -> fgets(S,50,stdin)
\
#include <stdio.h>

int main() {
    FILE *fp;
    char str[50];

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    while (fgets(str, 50, fp) != NULL)
        printf("%s", str);

    fclose(fp);
    return 0;
}

