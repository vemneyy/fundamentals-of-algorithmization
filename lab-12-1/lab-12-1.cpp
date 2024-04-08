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

/*
* Класс для работы со строками аналогичными строкам Turbo Pascal
* Функции в классе:
* - ввод строки с клавиатуры
* - вывод строки на экран
* - получение длины строки
* - поиск подстроки в строке
* - удаление подстроки из строки
* - вставка подстроки в строку
* - сцепление двух строк
*/

class String {
private:
    static const int MAX_SIZE = 256; // Максимальный размер, включая длину
    unsigned char data[MAX_SIZE]; // Данные строки, где data[0] - длина

public:
    String() { 
        data[0] = 0; 
    } // Конструктор по умолчанию

    // Метод ввода строки с клавиатуры
    void input() {
        char temp[MAX_SIZE - 1]; // Временный буфер для ввода строки
        cin.getline(temp, MAX_SIZE - 1); // Вводим строку
        size_t len = strlen(temp); // Длина строки
        data[0] = static_cast<unsigned char>((len < MAX_SIZE - 1) ? len : MAX_SIZE - 1); // Записываем длину строки
        memcpy(data + 1, temp, data[0]); // Копируем символы строки
    }

    // Метод для вывода строки на экран
    void print() const {
        // Выводим символы строки
        for (int i = 1; i <= data[0]; ++i) {
            cout << data[i];
        }
        cout << endl;
    }

    // Метод для получения длины строки
    int length() const { return data[0]; }

    // Поиск подстроки в строке
    int find(const String& substr) const {
        // Если длина подстроки больше длины строки, то подстрока не найдена
        for (int i = 1; i <= data[0] - substr.data[0] + 1; ++i) {
            bool match = true; // Флаг совпадения
            for (int j = 1; j <= substr.data[0]; ++j) {
                // Если символы не совпадают, то выходим из цикла
                if (data[i + j - 1] != substr.data[j]) {
                    match = false; // Сбрасываем флаг
                    break;
                }
            }
            if (match) return i; // Возвращаем позицию начала подстроки
        }
        return -1; // Подстрока не найдена
    }

    // Удаление подстроки из строки
    void remove(int position, int length) {
        // Если позиция или длина некорректны, то выходим
        if (position < 1 || position > data[0] || length < 0 || position + length - 1 > data[0]) return; // Позиция и длина некорректны
        // Сдвигаем символы влево
        for (int i = position; i <= data[0] - length; ++i) {
            data[i] = data[i + length]; // Сдвигаем символы
        }
        data[0] -= length; // Уменьшаем длину строки

        // Заполняем оставшуюся часть нулями
    }

    // Вставка подстроки в строку
    void insert(const String& substr, int position) {
        // Если позиция некорректна, то выходим
        if (position < 1 || position > data[0] + 1 || data[0] + substr.data[0] >= MAX_SIZE) return;
        // Сдвигаем символы вправо
        for (int i = data[0]; i >= position; --i) {
            data[i + substr.data[0]] = data[i]; // Сдвигаем символы
        }
        // Вставляем подстроку
        for (int i = 0; i < substr.data[0]; ++i) {
            data[position + i] = substr.data[i + 1]; // Вставляем символы
        }
        data[0] += substr.data[0]; // Увеличиваем длину строки
    }

    // Сцепление двух строк
    void concat(const String& other) {
        // Если длина строки превышает максимальный размер, то выходим
        if (data[0] + other.data[0] >= MAX_SIZE) return;
        // Добавляем символы второй строки в конец первой
        for (int i = 1; i <= other.data[0]; ++i) {
            data[data[0] + i] = other.data[i]; // Добавляем символы
        }
        data[0] += other.data[0]; // Увеличиваем длину строки
    }
};

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

    // Вывод строк
    cout << "Строка 1: ";
    str1.print();
    cout << "Строка 2: ";
    str2.print();

    // Длина строк
    cout << "Длина строки 1: " << str1.length() << endl;
    cout << "Длина строки 2: " << str2.length() << endl;

    // Поиск подстроки в строке 1
    int position = str1.find(substr);
    if (position != -1) {
        cout << "Подстрока найдена в строке 1 на позиции: " << position << endl;
    }
    else {
        cout << "Подстрока не найдена в строке 1." << endl;
    }

    // Удаление подстроки из строки 1
    if (position != -1) {
        str1.remove(position, substr.length());
        cout << "После удаления подстроки строка 1: ";
        str1.print();
    }

    // Поиск подстроки в строке 2
    int position_2 = str2.find(substr);
    if (position_2 != -1) {
        cout << "Подстрока найдена в строке 2 на позиции: " << position_2 << endl;
    }
    else {
        cout << "Подстрока не найдена в строке 2." << endl;
    }

    // Вставка подстроки в строку 2
    str2.insert(substr, position_2);
    cout << "После вставки подстроки строка 2: ";
    str2.print();

    // Сцепление строк 1 и 2
    str1.concat(str2);
    cout << "После сцепления строк: ";
    str1.print();

    return 0;
}