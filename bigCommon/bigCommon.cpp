/*Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.
*/

#include <iostream>
using namespace std;

int bigCommon(int a, int b)
{
    
        if (a == 0)
            return b;
        else if (b == 0)
            return a;
        else if (a > b)
            return bigCommon(b, a % b);
        else
            return bigCommon(a, b % a);
    

}
int main()
{
    setlocale(LC_ALL, "ru");
    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "Наибольший общий делитель - "<< bigCommon(a, b);
}
