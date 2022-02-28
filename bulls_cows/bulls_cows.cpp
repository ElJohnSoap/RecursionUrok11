/*�������� ���� ����� � �������. ��������� "����������" ������������� ����� � ��������
������ ������� ���. ����� ����� ������������� ����� ��������� ��������, ������� ���� �����
������� (����) � ������� ���� ������� � ����� �� ������ ����� (������). ����� �����������
����� �� ����� ���������� ������� ���������� ��������� ������������� �������. �
��������� ���������� ������������ ��������.*/

#include <iostream>
using namespace std;
int count=1;

void initArrPC(int arr[4])
{
    int digitPC = rand() % 10000+1000;
    //cout << digitPC << endl;
    for (int i = 3; i >= 0; --i)
    {
        arr[i] = digitPC % 10;
        digitPC /= 10;
    }
        
}

void initArrUser(int arr[4])
{
        int digit;
        cout << "\n������� ����� �� 4 ����: ";
        cin >> digit;
        while (digit <1000||digit>9999)
        {
            cout << "\n������ 4 ����! ��������� ����\n\n";
            cout << "\n������� ����� �� 4 ����: ";
            cin >> digit;
        }       
        
        for (int i = 3; i >= 0; --i)
        {
            arr[i] = digit % 10;
            digit /= 10;
        }
        /*for (int i = 0; i < 4; i++)
        {
            cout << arr[i] <<"\t";
        }*/
}

void game(int arrPC[4], int arrUser[4])
{
    initArrUser(arrUser);
    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < 4; ++i)
    {
        if (arrPC[i] == arrUser[i]) ++cows;
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (arrPC[i] == arrUser[j])
            {
                ++bulls;
                arrUser[j] = -1;
                break;
            }
        }
    }
    if (cows == 4)
    {
        cout << "\n����� �������!\n\n";
        cout << "������� - " << ::count << endl;
        return;

    }
    else 
    {
        ::count++;
        cout << "\n���� ������� - " << bulls;
        cout << "\n�� ���� ����� - " << cows << endl;
        game(arrPC, arrUser);
    }
    
}



int main()
{
    setlocale(LC_ALL, "ru");
    cout << "   ������ �����!\n";
    //cout << "������� ������������� �����:";
    int arrPC[4], arrUser[4];
    srand(time(0));
    initArrPC(arrPC);
    cout << endl;
    //initArrUser(arrUser);
    game(arrPC, arrUser);


    return 0;    
}
