#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("data.txt", "w");//file will be saved with this name

    if (fp == NULL) // ALways check for the null pointer before writing
    { 
        printf("File not created!\n");
        return 1;
    }
    fprintf(fp, "Hello File Handling!\n");//TO write something inside the created file 
    fprintf(fp, "C Programming Example\n");
    fclose(fp);// this line is mandatory to save changes
    printf("Data written successfully.\n");
    return 0;
}

