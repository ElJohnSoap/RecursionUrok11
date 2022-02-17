#include <iostream>
using namespace std;

/*
    ������� ��������� ��� ���������
    int in - �� ����
    int to - ����
    int n - �������
*/
void move_tower(int in, int to, int n)
{
    if (n == 1)// ���� 1 ���� ������ �����������
    {
        cout << "��\t"<< in << "\t" << n << " -> " << to << endl;
    }
    else //���� ������ ������
    {
        int free = 6 - (in + to);//���� ��������� �����
        move_tower(in, free, n - 1); // ���������� ��� ����� ����� ������ �� ��������� �����
        move_tower(in, to, 1);//���������� ������ ���� �� ������ �����
        move_tower(free, to, n - 1);//���������� �� ����� �� ������
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "n = "; cin >> n;
    move_tower(1, 3, n);
    cin.get();
    cin.get();
}