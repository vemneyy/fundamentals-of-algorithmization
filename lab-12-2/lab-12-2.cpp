#include <iostream>
#include <cstring> // Для использования strlen и memcpy

using namespace std;

class String {
private:
    static const int MAX_SIZE = 256; // Включая байт длины
    char data[MAX_SIZE];

public:
    // Конструктор по умолчанию
    String() : data{ 0 } {}

    // Инициализирующий конструктор
    String(const char* str) {
        int length = strlen(str);
        data[0] = static_cast<char>((length >= MAX_SIZE - 1) ? MAX_SIZE - 1 : length);
        memcpy(data + 1, str, data[0]);
    }

    // Конструктор копирования
    String(const String& other) : String(other.data + 1) {}

    // Вывод строки
    void print() const {
        cout.write(data + 1, data[0]);
        cout << endl;
    }

    // Преобразование в строку C++
    string toString() const {
        return string(data + 1, data[0]);
    }

    // Длина строки
    int length() const {
        return static_cast<unsigned char>(data[0]);
    }

    // Поиск подстроки
    int find(const String& substring) const {
        for (int i = 1; i <= length() - substring.length() + 1; ++i) {
            bool found = true;
            for (int j = 0; j < substring.length(); ++j) {
                if (data[i + j] != substring.data[j + 1]) {
                    found = false;
                    break;
                }
            }
            if (found) return i - 1;
        }
        return -1; // Подстрока не найдена
    }

    // Вставка подстроки
    void insert(const String& substring, int position) {
        int thisLen = length(), subLen = substring.length();
        if (position > thisLen || position < 0 || thisLen + subLen > MAX_SIZE - 2) return;

        // Сдвигаем существующие символы
        for (int i = thisLen; i >= position; --i) {
            data[i + subLen + 1] = data[i + 1];
        }

        // Копируем подстроку
        memcpy(data + position + 1, substring.data + 1, subLen);
        data[0] += static_cast<char>(subLen);
    }

    // Удаление подстроки
    void remove(int position, int length) {
        int thisLen = this->length();
        if (position < 0 || position + length > thisLen) return;

        // Сдвигаем символы
        memcpy(data + position + 1, data + position + length + 1, thisLen - position - length);
        data[0] -= static_cast<char>(length);
    }

    // Сцепление строк
    String operator+(const String& other) const {
        String result;
        int thisLen = length(), otherLen = other.length();
        int newLength = thisLen + otherLen;
        newLength = (newLength >= MAX_SIZE - 1) ? MAX_SIZE - 1 : newLength;

        result.data[0] = static_cast<char>(newLength);
        memcpy(result.data + 1, this->data + 1, thisLen);
        memcpy(result.data + thisLen + 1, other.data + 1, otherLen);

        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    String hello("Привет, ");
    String world("мир!");
    String greetings = hello + world;
    greetings.print();

    String phrase("Мне нравится программировать!");
    phrase.insert(String("не "), 4);
    phrase.print();

    phrase.remove(4, 3);
    phrase.print();

    cout << "Позиция 'нравится': " << phrase.find(String("нравится")) << endl;

    return 0;
}
