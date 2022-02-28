/*Напишите рекурсивную функцию, которая принимает
одномерный массив из 100 целых чисел, заполненных
случайным образом, и находит позицию, с которой
начинается последовательность из  10 чисел, сумма
которых минимальна.*/

#include <iostream>
using namespace std;

int min10Arr(int arr[100], int n = 0)
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
}

int main()
{
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
    cout << min10Arr(arr);
    cout << endl;
    cout << endl;

    //проверка
    int sum1 = 0, sum2 = 0, p;
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
            p = i;
        }
        cout << sum1 << "\t"<< i << "\n";
    }
    cout << p << "\t" << sum2;
    return 0;
}

/*(int a[100], int n, int& p) {
    int s = 0;
    for (int i = n; i < n + 10; ++i) s += a[i];
    cout << "n: " << n << "; s: " << s << endl;
    if (100 - n == 10)
    {
        p = n;
        return s;
    }
    else
    {
        int s1 = min10(a, n + 1, p);
        if (s <= s1)
        {
            p = n;
            return s;
        }
        else return s1;
    }
}
int main() {
    int a[100];
    int p;

    

    for (int i = 0; i < 100; ++i) a[i] = rnd​(​generator​)​;
    for (int i = 0; i < 100; ++i) cout << a[i] << '\t';
    cout << endl << endl;

    min10(a, 0, p);

    cout << "Minimum position: " << p << endl << endl;

    system​(​"pause"​)​; ​
}

int min10(int a[100], bestIndex = 0, bestSum = 0, currentSum = 0, currentIndex = 0) {
if (currentIndex == 100)
return bestIndex;

int newSum = currentSum + a[currentIndex];

if (currentIndex < 10)
return min10(a, bestIndex, newSum, newSum, currentIndex + 1);

newSum = newSum - a[currentIndex - 10];
if (newSum > bestSum)
return min10(a, currentIndex - 10, newSum, newSum, currentIndex + 1);
else
return min10(a, bestIndex, bestSum, newSum, currentIndex + 1);
}*/