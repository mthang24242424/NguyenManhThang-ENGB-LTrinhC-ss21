#include <stdio.h>

int main() {
    FILE *fptr;
    int n;
    char word[100];

    fptr = fopen("bt05.txt", "w");
    if (fptr == NULL) {
        printf("Khong the mo file bt05.txt!\n");
        return 1;
    }

    printf("Nhap so dong: ");
    scanf("%d", &n);
    fflush(stdin); 

    for (int i = 0; i < n; i++) {
        printf("Nhap noi dung dong %d: ", i + 1);
        fgets(word, 100, stdin);
        fputs(word, fptr);
    }

    fclose(fptr);

    fptr = fopen("bt05.txt", "r");
    if (fptr == NULL) {
        printf("Khong the mo file bt05.txt!\n");
        return 1;
    }

    printf("\nNoi dung trong file bt05.txt:\n");
    while (fgets(word,100, fptr) != NULL) {
        printf("%s", word);
    }

    fclose(fptr);
    return 0;
}
