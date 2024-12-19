#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void inputString(char *str);
void printString(const char *str);
int countLetters(const char *str);
int countDigits(const char *str);
int countSpecialCharacters(const char *str);

int main() {
    char str[100] = "";
    int choice;

    do {
        printf("--- menu ---\n");
        printf("1. nhap vao chuoi\n");
        printf("2. in ra chuoi\n");
        printf("3. dem so luong chu cai trong chuoi va in ra\n");
        printf("4. dem so luong chu so trong chuoi va in ra\n");
        printf("5. dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. thoat\n");
        printf("lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputString(str);
                break;
            case 2:
                printString(str);
                break;
            case 3:
                printf("so luong chu cai: %d\n", countLetters(str));
                break;
            case 4:
                printf("so luong chu so: %d\n", countDigits(str));
                break;
            case 5:
                printf("so luong ky tu dac biet: %d\n", countSpecialCharacters(str));
                break;
            case 6:
                printf("thoat chuong trinh.\n");
                break;
            default:
                printf("lua chon khong hop le. vui long thu lai.\n");
        }
    } while (choice != 6);

    return 0;
}

void inputString(char *str) {
    printf("nhap vao chuoi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void printString(const char *str) {
    printf("chuoi: %s\n", str);
}

int countLetters(const char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int countDigits(const char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int countSpecialCharacters(const char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

