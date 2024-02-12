#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, y, z;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "z = ";
	cin >> z;

	double h =
		((pow(x, y + 1) + exp(y - 1)) /
			(1 + x * abs(y - tan(z)))) *
		(1 + abs(y - x)) +
		(pow(abs(y - x), 2) / 2) -
		(pow(abs(y - x), 3) / 3);

	cout << "h = " << h << endl;

	return 0;
}