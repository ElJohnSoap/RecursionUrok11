/*Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий
должен угадать его. После ввода пользователем числа программа сообщает, сколько цифр числа
угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы). После отгадывания
числа на экран необходимо вывести количество сделанных пользователем попыток. В
программе необходимо использовать рекурсию.*/

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
        cout << "\nВведите число из 4 цифр: ";
        cin >> digit;
        while (digit <1000||digit>9999)
        {
            cout << "\nМеньше 4 цифр! Повторите ввод\n\n";
            cout << "\nВведите число из 4 цифр: ";
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
        cout << "\nЧисло угадано!\n\n";
        cout << "Попыток - " << ::count << endl;
        return;

    }
    else 
    {
        ::count++;
        cout << "\nЦифр угадано - " << bulls;
        cout << "\nНа своём месте - " << cows << endl;
        game(arrPC, arrUser);
    }
    
}



int main()
{
    setlocale(LC_ALL, "ru");
    cout << "   Угадай число!\n";
    //cout << "Введите четырёхзначное число:";
    int arrPC[4], arrUser[4];
    srand(time(0));
    initArrPC(arrPC);
    cout << endl;
    //initArrUser(arrUser);
    game(arrPC, arrUser);


    return 0;    
}
