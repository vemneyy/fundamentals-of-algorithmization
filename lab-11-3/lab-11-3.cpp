#include <iostream>
#include <stdlib.h>

using namespace std;

struct elem {
    float number; // Вещественное число
    char symbol; // Символ
    elem* next; // Указатель на следующий элемент
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем начало списка
    elem* beginElem = nullptr;

    // Добавляем элементы в список
    // Первый элемент
    beginElem = new elem{ 34.5, 'a', nullptr };
    elem* endElem = beginElem;

    // Второй элемент
    endElem -> next = new elem{ 1826.1f, 'b', nullptr };
    endElem = endElem -> next;

    // Третий элемент
    endElem -> next = new elem{ -38.2f, 'c', nullptr };
    endElem = endElem -> next;

    // Четвертый элемент (со случайными значениями для примера)
    endElem -> next = new elem{ 8.9f, 'd', nullptr };

    // Печатаем список до удаления
    cout << "Список до удаления второго элемента:\n";
    for (elem* current = beginElem; current != nullptr; current = current -> next) {
        cout << current -> number << " " << current -> symbol  << "\n";
    }

    // Удаляем второй элемент, если он существует
    if (beginElem != nullptr && beginElem -> next != nullptr) {
        elem* temp = beginElem -> next;
        beginElem -> next = temp -> next; // Перенаправляем указатель
        delete temp; // Удаляем второй элемент
    }

    // Печатаем список после удаления
    cout << "\nСписок после удаления второго элемента:\n";
    for (elem* current = beginElem; current != nullptr; current = current->next) {
        cout << current -> number << " " << current -> symbol << "\n";
    }

    // Освобождаем память
    while (beginElem != nullptr) {
        elem* temp = beginElem;
        beginElem = beginElem -> next;
        delete temp;
    }

    return 0;
}
