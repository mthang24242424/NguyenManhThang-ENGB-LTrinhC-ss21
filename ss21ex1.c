#include <stdio.h>

int main() {
    char word[100];
    printf("nhap chuoi bat ki: ");
    fgets(word, 100, stdin);
    FILE *file = fopen("bt01.txt", "w");
    if (file == NULL) {
        printf("ko tim thay file\n");
        return 1;
    }
    fprintf(file, "%s", word);
    fclose(file);
    return 0;
}
