#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#pragma warning(disable : 4996)
int main() {
    setlocale(LC_ALL, "rus");
    FILE* f1, * f2;
    char line[100];
    f1 = fopen("F1.txt", "r");
    f2 = fopen("F2.txt", "w");
    if (f1 == NULL || f2 == NULL) {
        printf("Ошибка открытия файлов\n");
        return 1;
    }
    while (fgets(line, sizeof(line), f1) != NULL) {
        int i, has_digits = 0;
        for (i = 0; line[i] != '\0'; i++) {
            if (isdigit(line[i])) {
                has_digits = 1;
                break;
            }
        }
        if (!has_digits) {
            fputs(line, f2);
        }
    }
    fclose(f1);
    fclose(f2);
    printf("Копирование строк без цифр из файла F1 в файл F2 завершено\n");
    return 0;
}