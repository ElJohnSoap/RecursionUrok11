/*Напишите рекурсивную функцию, которая принимает
одномерный массив из 100 целых чисел, заполненных
случайным образом, и находит позицию, с которой
начинается последовательность из  10 чисел, сумма
которых минимальна.*/

#include <iostream>
using namespace std;
int p;
int min10Arr(int a[100], int n) {
    int sum = 0;
    for (int i = n; i < n + 10; ++i)
        sum += a[i];
    //cout << "n: " << n << "; s: " << sum << endl;
    if (100 - n == 10)
    {
        ::p = n;
        return sum;
    }
    else
    {
        int sum1 = min10Arr(a, n + 1);
        if (sum <= sum1)
        {
            ::p = n;
            return sum;
        }
        else return sum1;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    const int size = 100;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 50;
        cout << arr[i] << "\t";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
    cout << "Минимальная сумма - " << min10Arr(arr, 0);
    cout << "\nПозиция - " << ::p;
    cout << endl;
    cout << endl;

    //проверка
    int sum1 = 0, sum2 = 0, p2;
    for (int i = 0; i < 90; i++)
    {
        sum1 = 0;
        for (int j = i; j < i + 10; j++)
        {
            sum1 += arr[j];            
        }
        if (sum1 < sum2 || i == 0)
        {
            sum2 = sum1;
            p2 = i;
        }
        //cout << sum1 << "\t"<< i << "\n";
    }
    cout << "Проверка - " << sum2 << "\t" << p2;
    return 0;
}



/*int min10Arr(int arr[100], int n = 0)
{
    if (n == 89)
    {
        return n;
    }
    int sum10_1 = 0, sum10_2 = 0;
    int p = min10Arr(arr, n + 1);
    for (int i = n; i <= n + 10; i++)
        sum10_1 += arr[i];
    for (int i = p; i <= p + 10; i++)
        sum10_2 += arr[i];
    if (sum10_1 < sum10_2)
    {
        p = n;
        return p;
    }
    return n;
}*/