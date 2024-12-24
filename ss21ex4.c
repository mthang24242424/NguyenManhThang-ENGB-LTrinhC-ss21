#include <stdio.h>
int main() {
    FILE *fptr;
    char word[100];

    fptr = fopen("bt01.txt", "r");
    if (fptr == NULL) {
        printf("Khong the mo file bt01.txt!\n");
        return 1;
    }

    if (fgets(word,100, fptr) != NULL) {
        printf("Dong dau tien trong file: %s\n", word);
    } else {
        printf("File bt01.txt rong!\n");
    }

    fclose(fptr);
    return 0;
}
