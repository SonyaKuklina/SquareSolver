#include <stdio.h>
#include <TXLib.h>
#include <stdint.h>
#include <string.h> //для строк
#include <limits.h>//содержит информацию об ограничениях размеров целочисленных типов
#include <float.h>
#include <math.h>
#include <ctype.h> //семейство функций для работы с символами
#include <stdbool.h>//bool - псевдоним типа _Bool, введены символические константы true/false

int solvesquare(double a, double b, double c, double* x1, double* x2);

const double SMALL_CONST = 0.000001;
const long long INF = -1;

int main(void){

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf("Please, enter cofficients: \n");
    scanf("%lg %lg %lg", &a, &b, &c);

    int roots_count = solvesquare(a,b,c,&x1,&x2);//возвращает количество корней

    switch (roots_count){
        case 0: printf("No real roots\n");
                break;
        case 1: printf("Answer: x = %lg",x1);
                break;
        case 2: printf("Answer: x1 = %lg, x2 = %lg",x1,x2);
                break;
        case INF: printf("Infinity roots");
                       break;
    }
    return 0;

}
int solvesquare(double a, double b, double c,
                    double* x1, double* x2){

    if (fabs(a - 0) <= SMALL_CONST){
        if (fabs(b - 0)<=SMALL_CONST){
            return (c == 0) ? INF : 0;
        } else{
            *x1 = -c/b;
             return 1;
        }
    } else{
        double disc = b*b - 4*a*c;
        if (fabs(disc - 0)<=SMALL_CONST){
            *x1 = *x2 = -b/(2*a);
             return 1;
        } else if (disc < 0){
             return 0;
        } else{
            *x1 = (-b + sqrt(disc))/(2*a);
            *x2 = (-b - sqrt(disc))/(2*a);
            return 2;
        }
    }
}

