#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const int numX = 8; // ���������� �������� (x)
    const int numY = 10; // ���������� ����� (y)
    const int number = 94; // ���������� �������� ��� �����
    const int precision = 2;
    const char symbol = '-'; // ������ ��� �����
    string repeated(number, symbol); // ������� ������, ��������� �� ������������� ��������

    // ����� ��������� ��� �������� x
    cout << "y/x  |";
    for (int col = 0; col <= numY; col++)
    {
        double x = -1.0 + col * 0.2; // ��������� �������� x
        cout << setw(8) << fixed << setprecision(1) << x; // ������� x � �������� ���������������
        Sleep(5);
    }
    cout << endl; // ������� �� ����� ������

    // ����� �������������� �����
    cout << repeated << endl;

    // ������� ���� ��� ���������� � ������ �����������
    for (int i = 0; i <= numX; i++)
    {
        double y = -2.0 + i * 0.5; // ��������� �������� y

        // ����� �������� y, � ������ ��������������
        if (y < 0)
        {
            cout << setprecision(1) << y << setw(2) << "|"; // ������� y � ���������������
        }
        else
        {
            cout << " " << setprecision(1) << y << setw(2) << "|"; // ������� y � ���������������
        }

        Sleep(5);

        // ��������� ���� ��� ���������� ����������� ��� ������� x
        for (int j = 0; j <= numY; j++)
        {
            double x = -1.0 + j * 0.2; // ��������� �������� x
            double up = pow(x, 2) + pow(y, 2); // ��������� ���������
            double down = pow(x, 3) - pow(y, 3); // ��������� �����������

            // ��������� ������� �� ����
            if (down == 0)
            {
                cout << setw(8) << "ERROR"; // ������� ��������� �� ������, ���� ������� �� ����
            }
            else
            {
                double result = up / down; // ��������� ��������� �������
                cout << setw(8) << setprecision(precision) << result; // ������� ��������� � ������ ��������������
            }

            Sleep(5);
        }
        cout << endl; // ������� �� ����� ������ ����� ������ �������� y
    }
    cout << "\n\n*ERROR - ������ ����������� ��� ������� �� ����" << endl; // ����� ��������� �� ������, ���� ������� �� ����
}