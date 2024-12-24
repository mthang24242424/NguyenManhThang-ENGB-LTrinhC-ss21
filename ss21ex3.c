#include <stdio.h>
int main() {
    FILE *fptr;
    char word[100];
    printf("Nhap chuoi can ghi: ");
    fgets(word, 100, stdin);

    fptr = fopen("bt01.txt", "a");
    if (fptr == NULL) {
        printf("Khong the mo file bt01.txt!\n");
        return 1;
    }

    fputs(word, fptr);
    fclose(fptr);
    return 0;
}
