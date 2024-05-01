/*
* Задание №1. Реализуется без перегрузки операций, и без реализации конструкторов. 
* Обязательно должны быть реализованы ввод с клавиатуры и вывод на экран.
* Операции реализуются в двух вариантах: как элементы класса и как дружественные функции.
* 
* Вариант 14. Создать класс string для работы со строками, аналогичными строкам Turbo Pascal 
* (строка представляется как массив 255 байтов, длина – в первом байте). Максимальный размер строки 
* должен задаваться. Обязательно должны быть реализованы: длина строки, поиск подстроки в строке, 
* удаление подстроки из строки, вставка подстроки в строку, сцепление двух строк.
*/

#include <iostream>
#include <windows.h>

using namespace std;

class String {
private:
    static const int MAX_SIZE = 256; // Максимальный размер, включая длину
    unsigned char data[MAX_SIZE]; // Данные строки, где data[0] - длина

public:
    // Метод ввода строки с клавиатуры
    void input() {
        char temp[MAX_SIZE - 1];
        cin.getline(temp, MAX_SIZE - 1);
        int len = 0;  // Вычисляем длину строки вручную
        while (temp[len] != '\0' && len < MAX_SIZE - 1) {
            len++;
        }
        data[0] = static_cast<unsigned char>(len);
        for (int i = 0; i < len; ++i) {
            data[i + 1] = temp[i];  // Копируем данные вручную
        }
    }

    // Метод для вывода строки на экран
    void print() const {
        for (int i = 1; i <= data[0]; ++i) {
            cout << data[i];
        }
        cout << endl;
    }

    // Дружественные функции
    friend int length(const String& str);
    friend int find(const String& str, const String& substr);
    friend void remove(String& str, int position, int length);
    friend void insert(String& str, const String& substr, int position);
    friend void concat(String& str, const String& other);
};

// Длина строки
int length(const String& str) {
    return str.data[0];
}

// Поиск подстроки в строке
int find(const String& str, const String& substr) {
    for (int i = 1; i <= str.data[0] - substr.data[0] + 1; ++i) {
        bool match = true;
        for (int j = 1; j <= substr.data[0]; ++j) {
            if (str.data[i + j - 1] != substr.data[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}

// Удаление подстроки из строки
void remove(String& str, int position, int length) {
    if (position < 1 || position > str.data[0] || length < 0 || position + length - 1 > str.data[0]) return;
    for (int i = position; i <= str.data[0] - length; ++i) {
        str.data[i] = str.data[i + length];
    }
    str.data[0] -= length;
}

// Вставка подстроки в строку
void insert(String& str, const String& substr, int position) {
    if (position < 1 || position > str.data[0] + 1 || str.data[0] + substr.data[0] >= String::MAX_SIZE) return;
    for (int i = str.data[0]; i >= position; --i) {
        str.data[i + substr.data[0]] = str.data[i];
    }
    for (int i = 0; i < substr.data[0]; ++i) {
        str.data[position + i] = substr.data[i + 1];
    }
    str.data[0] += substr.data[0];
}

// Сцепление двух строк
void concat(String& str, const String& other) {
    if (str.data[0] + other.data[0] >= String::MAX_SIZE) return;
    for (int i = 1; i <= other.data[0]; ++i) {
        str.data[str.data[0] + i] = other.data[i];
    }
    str.data[0] += other.data[0];
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    String str1, str2, substr;
    cout << "Введите строку 1: ";
    str1.input();
    cout << "Введите строку 2: ";
    str2.input();
    cout << "Введите подстроку для поиска, вставки и удаления: ";
    substr.input();

    cout << "Строка 1: ";
    str1.print();
    cout << "Строка 2: ";
    str2.print();

    cout << "Длина строки 1: " << length(str1) << endl;
    cout << "Длина строки 2: " << length(str2) << endl;

    int position = find(str1, substr);
    if (position != -1) {
        cout << "Подстрока найдена в строке 1 на позиции: " << position << endl;
        remove(str1, position, length(substr));
        cout << "После удаления подстроки строка 1: ";
        str1.print();
    }
    else {
        cout << "Подстрока не найдена в строке 1." << endl;
    }

    position = find(str2, substr);
    if (position != -1) {
        cout << "Подстрока найдена в строке 2 на позиции: " << position << endl;
        insert(str2, substr, position);
        cout << "После вставки подстроки строка 2: ";
        str2.print();
    }
    else {
        cout << "Подстрока не найдена в строке 2." << endl;
    }

    concat(str1, str2);
    cout << "После сцепления строк: ";
    str1.print();

    return 0;
}
