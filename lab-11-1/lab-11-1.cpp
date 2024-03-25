/*
* �������� ������������ ����������, ������� �������� ���������� � ������: �������, ��� ��������, ���� � ��� ��������. 
* �������������� ������� �������� �����: ������, 1939, 174, 72. ����� �������� ���������� ���� ������ �� ����� �������
*/

#include <iostream>
#include <string>

using namespace std;

struct Person {
    string surname;
    int yearOfBirth;
    int height;
    int weight;
};

int main() {
    setlocale(LC_ALL, "Russian");
    // ������� ������������ ��������� ��������� Person
    Person* personPtr = new Person{ "������", 1939, 174, 72 };

    // �������� ������ �� ��������� ���������, ����� ������������ ��������� � ������
    Person& person = *personPtr;

    // ������� ���������� � ��������, ��������� ��������� � ������
    cout << "�������: " << person.surname << endl;
    cout << "��� ��������: " << person.yearOfBirth << endl;
    cout << "����: " << person.height << " ��" << endl;
    cout << "���: " << person.weight << " ��" << endl;

    // ����������� ���������� ��� ��������� ������
    delete personPtr;

    return 0;
}
