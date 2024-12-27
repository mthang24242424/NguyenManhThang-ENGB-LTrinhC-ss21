#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2;
    char a;
    file1 = fopen("bt01.txt", "r");
    if (file1 == NULL) {
        puts("mo file ko thanh cong");
        return 1;
    }
    file2 = fopen("bt06.txt", "w");
    if (file2 == NULL) {
        puts("mo file ko thanh cong");
        fclose(file1);
        return 1; 
    }
    while ((a = fgetc(file1)) != EOF) {
        fputc(a, file2);
    }
    printf("sao chep thanh cong\n");
    fclose(file1);
    fclose(file2);

    return 0;
}
