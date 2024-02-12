/* Число с является средним арифметическим чисел a и b */

#include <iostream>
using namespace std;

int main()
{
	double a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	cout << boolalpha << (c == (a + b) / 2) << endl;

	return 0;
}