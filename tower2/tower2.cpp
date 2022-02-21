#include <iostream>
using namespace std;


void move1(char kernel1, char kernel2)
{
    cout << "Из стержня " << kernel1 << " на стержень " << kernel2 << endl;
}

void moveTower(int disk, char kernel1, char kernel2, char kernelTemp)
{
    if (disk == 0)
    {
        return;
    }
    moveTower(disk - 1, kernel1, kernelTemp, kernel2);
    move1(kernel1, kernel2);
    moveTower(disk - 1, kernelTemp, kernel2, kernel1);
}

int main()
{
    setlocale(LC_ALL, "ru");

    moveTower(10, 'A', 'B', 'C');
    return 0;
}