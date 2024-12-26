#include <stdio.h>
#include <string.h>

typedef struct {
    char id[20];
    char name[40];
    char author[40];
    float price;
    char genre[40];
} Book;

void enter(Book book[], int *n);
void saveToFile(Book book[], int n);
void loadFromFile(Book book[], int *n);
void display(Book book[], int n);

int main() {
    int number = 0;
    int choose;
    Book book[100];

    do {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        getchar(); 

        switch (choose) {
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &number);
                getchar(); 
                enter(book, &number);
                break;
            case 2:
                saveToFile(book, number);
                break;
            case 3:
                loadFromFile(book, &number);
                break;
            case 4:
                display(book, number);
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choose != 5);

    return 0;
}
void enter(Book book[], int *n) {
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin sach thu %d\n", i + 1);
        printf("ID: ");
        fgets(book[i].id, 20, stdin);
        book[i].id[strcspn(book[i].id, "\n")] = 0;
        printf("Ten sach: ");
        fgets(book[i].name, 40, stdin);
        book[i].name[strcspn(book[i].name, "\n")] = 0;
        printf("Tac gia: ");
        fgets(book[i].author, 40, stdin);
        book[i].author[strcspn(book[i].author, "\n")] = 0;
        printf("Gia tien: ");
        scanf("%f", &book[i].price);
        getchar(); 
        printf("The loai: ");
        fgets(book[i].genre, 40, stdin);
        book[i].genre[strcspn(book[i].genre, "\n")] = 0;
        printf("------------\n");
    }
}

void saveToFile(Book book[], int n) {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s|%s|%s|%.2f|%s\n",
            book[i].id, book[i].name, book[i].author, book[i].price, book[i].genre);
    }
    fclose(file);
    printf("Da luu thong tin sach vao file.\n");
}

void loadFromFile(Book book[], int *n) {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return;
    }
    *n = 0;
    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%f|%[^\n]\n",
                  book[*n].id, book[*n].name, book[*n].author,
                  &book[*n].price, book[*n].genre) == 5) {
        (*n)++;
    }
    fclose(file);
    printf("Da lay thong tin sach tu file.\n");
}

void display(Book book[], int n) {
    printf("Danh sach thong tin sach:\n");
    for (int i = 0; i < n; i++) {
        printf("Sach thu %d:\n", i + 1);
        printf("ID: %s\n", book[i].id);
        printf("Ten sach: %s\n", book[i].name);
        printf("Tac gia: %s\n", book[i].author);
        printf("Gia tien: %.2f\n", book[i].price);
        printf("The loai: %s\n", book[i].genre);
        printf("------------\n");
    }
}
