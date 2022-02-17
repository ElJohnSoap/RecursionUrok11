#include <iostream>
using namespace std;

/*
    функция принимает три аргумента
    int in - от куда
    int to - куда
    int n - сколько
*/
void move_tower(int in, int to, int n)
{
    if (n == 1)// Если 1 диск просто переместить
    {
        cout << "Из\t"<< in << "\t" << n << " -> " << to << endl;
    }
    else //Если больше одного
    {
        int free = 6 - (in + to);//Ишем свободное место
        move_tower(in, free, n - 1); // Перемешаем все диски кроме одного на свободное место
        move_tower(in, to, 1);//Перемешаем нижний диск на нужное место
        move_tower(free, to, n - 1);//Перемешаем те диски на нижний
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