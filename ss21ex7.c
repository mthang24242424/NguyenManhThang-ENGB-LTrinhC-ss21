#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[100];
    int age;
} sinhVien;
int main() {
    FILE *fptr;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); 

    sinhVien *danhSach = (sinhVien *)malloc(n * sizeof(sinhVien)); // C?p phát b? nh? cho m?ng sinh viên

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &danhSach[i].id);
        getchar(); 
        printf("Ten: ");
        fgets(danhSach[i].name, sizeof(danhSach[i].name), stdin);
        if (danhSach[i].name[strlen(danhSach[i].name) - 1] == '\n') {
            danhSach[i].name[strlen(danhSach[i].name) - 1] = '\0';
        }

        printf("Tuoi: ");
        scanf("%d", &danhSach[i].age);
        getchar(); 
    }

    fptr = fopen("students.txt", "w");
    if (fptr == NULL) {
        printf("Khong the tao file students.txt!\n");
        free(danhSach);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fptr, "%d,%s,%d\n", danhSach[i].id, danhSach[i].name, danhSach[i].age);
    }

    fclose(fptr);
    free(danhSach); 

    printf("\nThong tin sinh vien da duoc luu vao file students.txt.\n");
    return 0;
}
