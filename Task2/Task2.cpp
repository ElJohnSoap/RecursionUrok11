/*Написать рекурсивную функцию нахождения степени
числа.*/

#include <iostream>
using namespace std;

int mult(int digit, int step) {

	if (step == 0)
		return 1;
	if (step > 0)
		return digit * mult(digit, step - 1);
}

int main()
{
	int digit, step;
	cin >> digit >> step;
	cout << mult(digit, step);
	return 0;
}

//return A * Power(A, N - 1);