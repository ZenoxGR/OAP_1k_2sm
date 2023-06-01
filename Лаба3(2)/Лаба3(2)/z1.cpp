//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#pragma warning(disable : 4996)
//
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    FILE* fileA;
//
//    int x, num1, num2;
//    float average;
//
//    printf("Введите x: ");
//    scanf("%d", &x);
//    fileA = fopen("fileA.txt", "r");
//    if (fileA == NULL)
//    {
//        printf("Ошибка открытия файла.\n");
//        exit(1);
//    }
//
//    fscanf(fileA, "%d", &num1);
//    while (!feof(fileA))
//    {
//        fscanf(fileA, "%d", &num2);
//        average = (num1 + num2) / 2.0;
//        if (average == x)
//        {
//            printf("Два числа последовательности, среднее арифмитическое которых равно %d: %d и %d.\n", x, num1, num2);
//            break;
//        }
//        num1 = num2;
//    }
//
//    fclose(fileA);
//    return 0;
//}