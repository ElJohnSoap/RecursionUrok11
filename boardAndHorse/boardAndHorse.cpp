/*������� 3:
���� ��������� ����� �������� 8�8 � ��������� ����. ��������� ������ ��������� �
������������ ���������� ������ ���� � ��������� ���� ����. ������ ��������� ����� �
������� ���� ����, ��� ������� �� ������� ��� ������ �����, ��������� � ������ ������
������ ���� ���. (��� ��� ������� ��������� ���� ��� ������ ��������� ������ �����
����������, �� ������������� ������� ���������� ������ �� ���� �������� 6�6). � ���������
���������� ������������ ��������.
*/

#include <iostream>
using namespace std;

#define BS 8
int board[BS][BS];
int step[8][2] = { {1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2} };
int n;

void printBoard()
{
    for (int i = 0; i < BS; i++)
    {
        for (int j = 0; j < BS; j++)
            cout << board[i][j] <<"\t";
        cout << endl << endl;
    }

}

bool setHorse(int x, int y)
{
    //�������� ����������
    if ((x < 0) || (x >= BS) || (y < 0) || (y >= BS))
        return false;

    if (board[x][y] != 0)
        return false;

    //����. ���
    n++;
    board[x][y] = n;

    //���� ����
    if (n == BS * BS)
        return true;

    for (int i = 0; i < 8; i++)
        if (setHorse(x + step[i][0], y + step[i][1]))
            return true;
    n--;
    board[x][y] = 0;

    return false;

}

int main()
{
    setlocale(LC_ALL, "ru");

    int n = 0;
    for (int i = 0; i < BS; i++)
    {
        for (int j = 0; j < BS; j++)
            board[i][j] = 0;
    }

    int a = 0, b = 0;
    //cout << "������� ���������� ��������� ����� � - �;";
    //cin >> a >> b;
    setHorse(a, b);

    printBoard();

    system("pause");
}
