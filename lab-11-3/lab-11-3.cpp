#include <iostream>
#include <stdlib.h>

using namespace std;

struct elem {
    float number; // ������������ �����
    char symbol; // ������
    elem* next; // ��������� �� ��������� �������
};

int main() {
    setlocale(LC_ALL, "Russian");

    // ������� ������ ������
    elem* beginElem = nullptr;

    // ��������� �������� � ������
    // ������ �������
    beginElem = new elem{ 34.5, 'a', nullptr };
    elem* endElem = beginElem;

    // ������ �������
    endElem -> next = new elem{ 1826.1f, 'b', nullptr };
    endElem = endElem -> next;

    // ������ �������
    endElem -> next = new elem{ -38.2f, 'c', nullptr };
    endElem = endElem -> next;

    // ��������� ������� (�� ���������� ���������� ��� �������)
    endElem -> next = new elem{ 8.9f, 'd', nullptr };

    // �������� ������ �� ��������
    cout << "������ �� �������� ������� ��������:\n";
    for (elem* current = beginElem; current != nullptr; current = current -> next) {
        cout << current -> number << " " << current -> symbol  << "\n";
    }

    // ������� ������ �������, ���� �� ����������
    if (beginElem != nullptr && beginElem -> next != nullptr) {
        elem* temp = beginElem -> next;
        beginElem -> next = temp -> next; // �������������� ���������
        delete temp; // ������� ������ �������
    }

    // �������� ������ ����� ��������
    cout << "\n������ ����� �������� ������� ��������:\n";
    for (elem* current = beginElem; current != nullptr; current = current->next) {
        cout << current -> number << " " << current -> symbol << "\n";
    }

    // ����������� ������
    while (beginElem != nullptr) {
        elem* temp = beginElem;
        beginElem = beginElem -> next;
        delete temp;
    }

    return 0;
}
