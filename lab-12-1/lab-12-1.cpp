/*
* ������� �1. ����������� ��� ���������� ��������, � ��� ���������� �������������. 
* ����������� ������ ���� ����������� ���� � ���������� � ����� �� �����.
* �������� ����������� � ���� ���������: ��� �������� ������ � ��� ������������� �������.
* 
* ������� 14. ������� ����� string ��� ������ �� ��������, ������������ ������� Turbo Pascal 
* (������ �������������� ��� ������ 255 ������, ����� � � ������ �����). ������������ ������ ������ 
* ������ ����������. ����������� ������ ���� �����������: ����� ������, ����� ��������� � ������, 
* �������� ��������� �� ������, ������� ��������� � ������, ��������� ���� �����.
*/

#include <iostream>
#include <windows.h>

using namespace std;

class String {
private:
    static const int MAX_SIZE = 256; // ������������ ������, ������� �����
    unsigned char data[MAX_SIZE]; // ������ ������, ��� data[0] - �����

public:
    String() { 
        data[0] = 0; 
    } // ����������� �� ���������

    // ����� ����� ������ � ����������
    void input() {
        char temp[MAX_SIZE - 1];
        cin.getline(temp, MAX_SIZE - 1);
        size_t len = strlen(temp);
        data[0] = static_cast<unsigned char>((len < MAX_SIZE - 1) ? len : MAX_SIZE - 1);
        memcpy(data + 1, temp, data[0]);
    }

    // ����� ��� ������ ������ �� �����
    void print() const {
        for (int i = 1; i <= data[0]; ++i) {
            cout << data[i];
        }
        cout << endl;
    }

    // ����� ��� ��������� ����� ������
    int length() const { return data[0]; }

    // ����� ��������� � ������
    int find(const String& substr) const {
        for (int i = 1; i <= data[0] - substr.data[0] + 1; ++i) {
            bool match = true;
            for (int j = 1; j <= substr.data[0]; ++j) {
                if (data[i + j - 1] != substr.data[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i; // ���������� ������� ������ ���������
        }
        return -1; // ��������� �� �������
    }

    // �������� ��������� �� ������
    void remove(int position, int length) {
        if (position < 1 || position > data[0] || length < 0 || position + length - 1 > data[0]) return;
        for (int i = position; i <= data[0] - length; ++i) {
            data[i] = data[i + length];
        }
        data[0] -= length;
    }

    // ������� ��������� � ������
    void insert(const String& substr, int position) {
        if (position < 1 || position > data[0] + 1 || data[0] + substr.data[0] >= MAX_SIZE) return;
        for (int i = data[0]; i >= position; --i) {
            data[i + substr.data[0]] = data[i];
        }
        for (int i = 0; i < substr.data[0]; ++i) {
            data[position + i] = substr.data[i + 1];
        }
        data[0] += substr.data[0];
    }

    // ��������� ���� �����
    void concat(const String& other) {
        if (data[0] + other.data[0] >= MAX_SIZE) return;
        for (int i = 1; i <= other.data[0]; ++i) {
            data[data[0] + i] = other.data[i];
        }
        data[0] += other.data[0];
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    String str1, str2, substr;
    cout << "������� ������ 1: ";
    str1.input();
    cout << "������� ������ 2: ";
    str2.input();
    cout << "������� ��������� ��� ������, ������� � ��������: ";
    substr.input();

    // ����� �����
    cout << "������ 1: ";
    str1.print();
    cout << "������ 2: ";
    str2.print();

    // ����� �����
    cout << "����� ������ 1: " << str1.length() << endl;
    cout << "����� ������ 2: " << str2.length() << endl;

    // ����� ��������� � ������ 1
    int position = str1.find(substr);
    if (position != -1) {
        cout << "��������� ������� � ������ 1 �� �������: " << position << endl;
    }
    else {
        cout << "��������� �� ������� � ������ 1." << endl;
    }

    // �������� ��������� �� ������ 1
    if (position != -1) {
        str1.remove(position, substr.length());
        cout << "����� �������� ��������� ������ 1: ";
        str1.print();
    }

    // ����� ��������� � ������ 2
    int position_2 = str2.find(substr);
    if (position_2 != -1) {
        cout << "��������� ������� � ������ 2 �� �������: " << position_2 << endl;
    }
    else {
        cout << "��������� �� ������� � ������ 2." << endl;
    }

    // ������� ��������� � ������ 2
    str2.insert(substr, position_2);
    cout << "����� ������� ��������� ������ 2: ";
    str2.print();

    // ��������� ����� 1 � 2
    str1.concat(str2);
    cout << "����� ��������� �����: ";
    str1.print();

    return 0;
}