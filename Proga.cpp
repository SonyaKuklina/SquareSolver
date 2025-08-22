#include <stdio.h>
#include <TXLib.h>
#include <stdint.h>
#include <string.h> //для строк
#include <limits.h>//содержит информацию об ограничениях размеров целочисленных типов
#include <float.h>
#include <math.h>
#include <ctype.h> //семейство функций для работы с символами
#include <stdbool.h>//bool - псевдоним типа _Bool, введены символические константы true/false

long long fact(int n);
int main(void){
      printf("Введите число (для завершения введите любой другой символ): \n");
      int num;
      while (scanf("%d",&num) == 1){
            printf("Факториал числа %d = %u\n", num, fact(num));
            printf("Введите следующее число: \n");
      }
}
long long fact(int n){
    long long ans = 1;
    if (n>0)
        ans = n*fact(n-1);
    else
        ans = 1;
    return ans;
}

