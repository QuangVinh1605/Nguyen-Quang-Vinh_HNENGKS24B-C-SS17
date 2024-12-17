#include<stdio.h>

void MENU();
void importElement(int **arr, int *n);
void show_Array(int *arr, int n);
int Sum(int *arr, int n);
void FindMax(int *arr, int n);

int main() {
    int choice = 0;
    int *arr = NULL;
    int n = 0;

    while (choice != 6) {
        MENU();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                importElement(&arr, &n);
                break;
            }
            case 2: {
                show_Array(arr, n);
                break;
            }
            case 3: {
                printf("Do dai mang: %d\n", n);
                break;
            }
            case 4: {
                int Tong = Sum(arr, n);
                printf("Tong cac phan tu trong mang la: %d\n", Tong);
                break;
            }
            case 5: {
                FindMax(arr, n);
                break;
            }
            case 6: {
                printf("Thoat chuong trinh\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le\n");
                break;
            }
        }
    }

    if (arr != NULL) {
        free(arr);
    }

    return 0;
}

void MENU() {
    printf("\n\n---------MENU---------\n\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. Hien thi cac phan tu trong mang\n");
    printf("3. Tinh do dai mang\n");
    printf("4. Tinh tong cac phan tu trong mang\n");
    printf("5. Hien thi phan tu lon nhat\n");
    printf("6. Thoat\n\n");
}

void importElement(int **arr, int *n) {
    printf("Hay nhap so phan tu cua mang: ");
    scanf("%d", n);

    *arr = (int *)malloc((*n) * sizeof(int));
    if (*arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        printf("Phan tu thu %d = ", i + 1);
        scanf("%d", (*arr) + i);
    }
}

void show_Array(int *arr, int n) {
    printf("Mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int Sum(int *arr, int n) {
    int Tong = 0;
    for (int i = 0; i < n; i++) {
        Tong += *(arr + i);
    }
    return Tong;
}

void FindMax(int *arr, int n) {
    int Max = *(arr + 0);
    for (int i = 0; i < n; i++) {
        if (*(arr + i) > Max) {
            Max = *(arr + i);
        }
    }
    printf("Phan tu lon nhat trong mang la: %d\n", Max);
}

 
	  
