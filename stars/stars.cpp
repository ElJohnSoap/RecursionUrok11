/*3. �������� ����������� �������, ������� ������� N
����� � ���, ����� N ������ ������������. ���������������� ������ ������� ��������.*/

#include <iostream>
using namespace std;

void stars(int n)
{
    if (!n)
    {
        cout << endl;
        return;
    }
    
        cout << "*";
        stars(n - 1);
   
}

int main()
{
    int n = 5;
    stars(n);
}

