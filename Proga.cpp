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
bool GetRightCoefficients(double* a, double* b, double* c);
void GetAnswer(double* x1, double* x2, int roots_count);
int SolveLinerEquation(double b, double c, double* x1);
int SolveSquareEquation(double a, double b, double c, double* x1, double* x2);
int SolveCountDependingDisc(double* d, double a, double b, double c);
bool ComparisonWithZero(double n);


const double SMALL_CONST = 0.000001;
const long long INF = -1;

enum solves {
    ZERO_SOLVE,
    ONE_SOLVE,
    TWO_SOLVE,
};


int main(void){


    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    if (!GetRightCoefficients(&a,&b,&c))
        printf("The program cannot be executed");
    else {
        int roots_count = solvesquare(a,b,c,&x1,&x2);//возвращает количество корней
        GetAnswer(&x1,&x2,roots_count);  //выводит корни, в зависимости от ситуации
    }

    return 0;


}
int solvesquare(double a, double b, double c,
                    double* x1, double* x2){

    assert(x1 != NULL);
    assert(x2 != NULL);

    if (ComparisonWithZero(a))
        return SolveLinerEquation(b,c,x1);
    else
        return SolveSquareEquation(a,b,c,x1,x2);

}

bool GetRightCoefficients(double* a, double* b, double* c){

    assert(a!=NULL);
    assert(b!=NULL);
    assert(c!=NULL);

    printf("Please, enter cofficients: \n");
    return (scanf("%lg %lg %lg",a,b,c) == 3);

}

void GetAnswer(double* x1, double* x2,
                         int roots_count){

        assert(x1!=NULL);
        assert(x2!=NULL);

        switch (roots_count){
        case ZERO_SOLVE: printf("No real roots\n");
                break;
        case ONE_SOLVE: printf("Answer: x = %lg",*x1);
                break;
        case TWO_SOLVE: printf("Answer: x1 = %lg, x2 = %lg",*x1,*x2);
                break;
        case INF: printf("Infinity roots");
                       break;
        }

}
int SolveLinerEquation(double b, double c,
                            double* x1){

        assert(x1 != NULL);

        if (ComparisonWithZero(b)){
            return (ComparisonWithZero(c)) ? INF : ZERO_SOLVE;
        } else{
             *x1 = -c/b;
             return ONE_SOLVE;
        }

}

int SolveSquareEquation(double a, double b, double c,
                                double* x1, double* x2){

        assert(x1!=NULL);
        assert(x2!=NULL);

        double d=0;
        switch(SolveCountDependingDisc(&d,a,b,c)){
            case ZERO_SOLVE: return ZERO_SOLVE;
                    break;
            case ONE_SOLVE:*x1 = *x2 = -b/(2*a);
                    return ONE_SOLVE;
                    break;
            case TWO_SOLVE: *x1 = (-b + sqrt(d))/(2*a);
                    *x2 = (-b - sqrt(d))/(2*a);
                    return TWO_SOLVE;
                    break;
        }

}

int SolveCountDependingDisc(double* d,
                        double a, double b, double c ){

    assert(d != NULL);

    *d = b*b - 4*a*c;
    if  (ComparisonWithZero(*d))
        return ONE_SOLVE;
    else if (*d<0)
        return ZERO_SOLVE;
    else
        return TWO_SOLVE;

}

bool ComparisonWithZero(double n){
    return (fabs(n)<=SMALL_CONST);
}


