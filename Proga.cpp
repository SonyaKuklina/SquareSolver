#include <stdio.h>
#include <TXLib.h>
#include <stdint.h>
#include <string.h> //��� �����
#include <limits.h>//�������� ���������� �� ������������ �������� ������������� �����
#include <float.h>
#include <math.h>
#include <ctype.h> //��������� ������� ��� ������ � ���������
#include <stdbool.h>//bool - ��������� ���� _Bool, ������� ������������� ��������� true/false

long long fact(int n);
int main(void){
      printf("������� ����� (��� ���������� ������� ����� ������ ������): \n");
      int num;
      while (scanf("%d",&num) == 1){
            printf("��������� ����� %d = %u\n", num, fact(num));
            printf("������� ��������� �����: \n");
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

