/*4. �������� ����������� �������, ������� ���������
����� ���� ����� � ��������� �� a �� b. ������������ 
������ a �  b. ���������������� ������ �������
��������.*/

#include <iostream>
using namespace std;

int sumFun(int a, int b)
{
	if (a==b) return b; 
	return sumFun(a + 1, b) + a;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << sumFun(a, b);
}
