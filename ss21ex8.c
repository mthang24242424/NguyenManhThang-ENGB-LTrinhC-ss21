#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[100];
    int age;
} sinhVien;

int main() {
    FILE *fptr;
    sinhVien danhSach[100]; 
    int n = 0;
    fptr = fopen("students.txt", "r");
    if (fptr == NULL) {
        printf("Khong the mo file students.txt!\n");
        return 1;
    }
    while (fscanf(fptr, "%d,%99[^,],%d\n", &danhSach[n].id, danhSach[n].name, &danhSach[n].age) == 3) {
        n++;
        if (n >= 100) break; 
    }
    fclose(fptr);
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("Sinh vien %d: ID = %d, Ten = %s, Tuoi = %d\n", i + 1, danhSach[i].id, danhSach[i].name, danhSach[i].age);
    }

    return 0;
}
