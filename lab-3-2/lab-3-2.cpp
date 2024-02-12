#include <iostream>
using namespace std;

int main() {
    // ���������� ����������
    int elementNumber;
    double elementValue;
    // ����� ��������������� ���������
    cout << "1 - Radius\n" << "2 - Diameter\n" << "3 - Length\n" << "4 - Area of the circle" << endl;

    // ���� ������ �������� � ��� ��������
    cout << "\nEnter (1-4): ";
    cin >> elementNumber;
    cout << "Enter the value: ";
    cin >> elementValue;


    // ���������� ��������� ��������� � ����������� �� ������ ��������
    switch (elementNumber)
    {
    case 1: // ������
        cout << "\nDiameter: " << 2 * elementValue << endl;
        cout << "Length: " << 2 * 3.14 * elementValue << endl;
        cout << "Area of the circle: " << 3.14 * elementValue * elementValue << endl;
        break;
    case 2: // �������
        cout << "\nRadius: " << elementValue / 2 << endl;
        cout << "Length: " << 3.14 * elementValue << endl;
        cout << "Area of the circle: " << 3.14 * (elementValue / 2) * (elementValue / 2) << endl;
        break;
    case 3: // �����
        cout << "\nRadius: " << elementValue / (2 * 3.14) << endl;
        cout << "Diameter: " << elementValue / 3.14 << endl;
        cout << "Area of the circle: " << (elementValue / (2 * 3.14)) * (elementValue / (2 * 3.14)) * 3.14 << endl;
        break;
    case 4: // ������� �����
        cout << "\nRadius: " << sqrt(elementValue / 3.14) << endl;
        cout << "Diameter: " << 2 * sqrt(elementValue / 3.14) << endl;
        cout << "Length: " << 2 * 3.14 * sqrt(elementValue / 3.14) << endl;
        break;
    default:
        cout << "\nInvalid element number." << endl;
        break;
    }

    // �������� ���������� ���������
    return 0;
}