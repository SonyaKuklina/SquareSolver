# Решение квадратного уравнения

## Описание проекта
>Данная программа решает квадратное уравнение ax² + bx + c = 0 , получая на вход
коэффициенты
a, b и c. В основную функцию SolveSquare передаются коэффициенты и указатели на
предполагаемые корни уравнения x1 и x2

## Файловое разделение программы
![](blob:https://app.gram.ax/aa07e970-8c74-4ee2-a884-e3ed5756d18c)
## Работа с командной строкой
>С помощью параметров функции main(int **argc**, char* **argv**) осуществляется работа с
командной строкой. При запуске файла с расширением **.exe** происходит
считывание введённого после него текста. Если введено *—tests* , то программа
тестируется на Unite Tests, в противном случае она сразу переходит к выполнению
основной программе

## Unite Tests
>С помощью массива структур для программы создаются тесты, которые содержат
коэффициенты a,b,c, а также правильное количество корней и сами корни. В
случае несовпадения результата работы программы с тестовыми данными,
программа выдаёт ошибку и прерывается.

## Компиляция программы
```
g++ Proga.cpp Solves.cpp RightCheck.cpp auxiliary.cpp -Wshadow -Winit-self -
Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code
-Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -
Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -
Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignoredqualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -
Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrictaliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -
D_DEBUG -D_EJUDGE_CLIENT_SIDE--i

```
