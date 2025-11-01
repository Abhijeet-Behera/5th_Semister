#include <stdio.h>

int main() {
int a[10][10], t[10][10];
int r, c, i, j;
printf("rows & col: ");
scanf("%d %d", &r, &c);
printf("Enter matrix:\n");
for (i = 0; i < r; i++) {
for (j = 0; j < c; j++) {
scanf("%d", (*(a + i) + j));  // pointer form of a[i][j]
}} 
for (i = 0; i < r; i++) {
for (j = 0; j < c; j++) {
*(*(t + j) + i) = *(*(a + i) + j);
}}


printf("\nOriginal matrix:\n");
for (i = 0; i < r; i++) {
for (j = 0; j < c; j++) {
printf("%d ", *(*(a + i) + j));
}
printf("\n");
}
printf("\nTranspose:\n");
for (i = 0; i < c; i++) {
for (j = 0; j < r; j++) {
printf("%d ", *(*(t + i) + j));
}
printf("\n");
}
 return 0;
}

