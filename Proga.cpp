///brief Решение квадратного уравнения
#include <stdio.h>
#include <TXLib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

enum Solves {
    INF = -1,
    ZERO_SOLVE,
    ONE_SOLVE,
    TWO_SOLVE,
};

/*!SolveSquare
  /param [in] a-коэффициент
  /param [in] b-коэффициент
  /param [in] c-коэффициент
  /param [out] x1-первый возможный корень уравнения
  /param [out] x2-второй возможный корень уравнения
  \return Вызывает функции SolveLinerEquation (при a == 0) и SolveSquareEquation (при a != 0)
*/
int SolveSquare(double a, double b, double c, double* x1, double* x2);

/*!  GetRightCoefficients
  \return Корректность введённых коэффициентов
*/
void GetRightCoefficients(double* a, double* b, double* c);
/*!GetAnswer
  /param[out] x1 - первый корень уравнения
  /param[out] x2 - второй корень уравнения
  /param[in] roots_count - количество корней
  \return Выводит окончательный ответ
*/
void GetAnswer(double* x1, double* x2, int roots_count);
/*!  SolveLinerEquation
  /param[in] b-коэффициент
  /param[in] c-коэффициент
  /param[out] x1-единственный корень
  \return  Количесвто корней (1, 0 или INF), при a = 0
*/
Solves SolveLinerEquation(double b, double c, double* x1);
/*!  SolveSquareEquation
  /param [in] a-коэффициент
  /param [in] b-коэффициент
  /param [in] c-коэффициент
  /param [out] x1-первый возможный корень уравнения
  /param [out] x2-второй возможный корень уравнения
  \return Количество корней уравнения, передает полученные значения в переменные x1 и x2
*/
Solves SolveSquareEquation(double a, double b, double c, double* x1, double* x2);
/*!  SolveCountDependingDisc
  /param [in] a-коэффициент
  /param [in] b-коэффициент
  /param [in] c-коэффициент
  /param [out] d - переменная для хранения значения дискриминанта
  \return Количество решений уравнения, в зависимости от значения дискриминанта
*/
Solves SolveCountDependingDisc(double* d, double a, double b, double c);
bool ComparisonWithZero(double n);
void ClearBuffer(void);


const double SMALL_CONST = 0.000001;


int main(void){


    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    GetRightCoefficients(&a, &b, &c);

    int roots_count = SolveSquare(a,b,c,&x1,&x2);
    GetAnswer(&x1,&x2,roots_count);


    return 0;


}
int SolveSquare(double a, double b, double c,
                    double* x1, double* x2){

    assert(x1 != NULL);
    assert(x2 != NULL);

    if (ComparisonWithZero(a))
        return SolveLinerEquation(b,c,x1);
    else
        return SolveSquareEquation(a,b,c,x1,x2);

}

void GetRightCoefficients(double* a, double* b, double* c){

    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("Please, enter coefficients: \n");
    while (scanf("%lg %lg %lg",a,b,c) != 3){
        ClearBuffer();
        printf("Please try entering again: \n");
    }

}

void GetAnswer(double* x1, double* x2,
                         int roots_count){

        assert(x1 != NULL);
        assert(x2 != NULL);

        switch (roots_count){
        case ZERO_SOLVE: printf("No real roots\n");
                break;
        case ONE_SOLVE: printf("Answer: x = %lg",*x1);
                break;
        case TWO_SOLVE: printf("Answer: x1 = %lg, x2 = %lg",*x1,*x2);
                break;
        case INF: printf("Infinity roots");
                       break;
        default: assert(0);
                 break;
        }

}
Solves SolveLinerEquation(double b, double c,
                            double* x1){

        assert(x1 != NULL);

        if (ComparisonWithZero(b)){
            return (ComparisonWithZero(c)) ? INF : ZERO_SOLVE;
        } else{
             *x1 = -c/b;
             return ONE_SOLVE;
        }

}

Solves SolveSquareEquation(double a, double b, double c,
                                double* x1, double* x2){

        assert(x1 != NULL);
        assert(x2 != NULL);

        double d = 0;
        switch(SolveCountDependingDisc(&d,a,b,c)){
            case ZERO_SOLVE: return ZERO_SOLVE;
                    break;
            case ONE_SOLVE:*x1 = *x2 = -b / ( 2 * a );
                    return ONE_SOLVE;
                    break;
            case TWO_SOLVE: *x1 = (-b + sqrt(d)) / (2 * a);
                    *x2 = (-b - sqrt(d)) / (2 * a);
                    return TWO_SOLVE;
                    break;
            default: assert(0);
                     break;
        }

}

Solves SolveCountDependingDisc(double* d,
                        double a, double b, double c ){

    assert(d != NULL);

    *d = b * b - 4 * a * c;
    if  (ComparisonWithZero(*d))
        return ONE_SOLVE;
    else if (*d < 0)
        return ZERO_SOLVE;
    else
        return TWO_SOLVE;

}

bool ComparisonWithZero(double n){
    return (fabs(n)<=SMALL_CONST);
}
void ClearBuffer(void) {
    int c;
    c = getchar();
    while ((c != '\n') && (c != EOF)){
        c = getchar();
    }
}


