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
void GetCoefficients(double* a, double* b, double* c);
void GetAnswer(double* x1, double* x2, int roots_count);
int SolveLinerEquation(double b, double c, double* x1);
int SolveSquareEquation(double a, double b, double c, double* x1, double* x2);
int SolveCountDependingDisc(double* d, double a, double b, double c);

const double SMALL_CONST = 0.000001;
const long long INF = -1;
bool CorrectEnter = true;

int main(void){

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    GetCoefficients(&a,&b,&c);//получение коффициентов от пользователя
    if (!CorrectEnter)
        printf("the program cannot be executed");
    else {
        int roots_count = solvesquare(a,b,c,&x1,&x2);//возвращает количество корней
        GetAnswer(&x1,&x2,roots_count);  //выводит корни, в зависимости от ситуации
    }

    return 0;


}
int solvesquare(double a, double b, double c,
                    double* x1, double* x2){

    if (fabs(a) <= SMALL_CONST)
        return SolveLinerEquation(b,c,x1);
    else
        return SolveSquareEquation(a,b,c,x1,x2);

}

void GetCoefficients(double* a, double* b, double* c){

    printf("Please, enter cofficients: \n");
    if (scanf("%lg %lg %lg",a,b,c) != 3){
        printf("invalid values\n");
        CorrectEnter = false;
    }

}

void GetAnswer(double* x1, double* x2,
                        int roots_count){

        switch (roots_count){
        case 0: printf("No real roots\n");
                break;
        case 1: printf("Answer: x = %lg",*x1);
                break;
        case 2: printf("Answer: x1 = %lg, x2 = %lg",*x1,*x2);
                break;
        case INF: printf("Infinity roots");
                       break;
        }

}
int SolveLinerEquation(double b, double c,
                            double* x1){
        if (fabs(b)<=SMALL_CONST){
            return (fabs(c) <= SMALL_CONST) ? INF : 0;
        } else{
             *x1 = -c/b;
             return 1;
        }

}

int SolveSquareEquation(double a, double b, double c,
                                double* x1, double* x2){

        double d=0;
        switch(SolveCountDependingDisc(&d,a,b,c)){
            case 0: return 0;
                    break;
            case 1:*x1 = *x2 = -b/(2*a);
                    return 1;
                    break;
            case 2: *x1 = (-b + sqrt(d))/(2*a);
                    *x2 = (-b - sqrt(d))/(2*a);
                    return 2;
                    break;
        }

}

int SolveCountDependingDisc(double* d,
                        double a, double b, double c ){
    *d = b*b - 4*a*c;
    if  (fabs(*d)<=SMALL_CONST)
        return 1;
    else if (*d<0)
        return 0;
    else
        return 2;

}


