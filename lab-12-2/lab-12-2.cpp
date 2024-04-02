/*
* Задание №2. Реализуется с перегрузкой операций; во всех указанных ниже заданиях должны быть реализованы: 
* безаргументный  и инициализирующий конструктор, конструктор копирования, ввод-вывод, преобразование в строку. 
*
* Вариант 14. Создать класс string для работы со строками, аналогичными строкам Turbo Pascal
* (строка представляется как массив 255 байтов, длина – в первом байте). Максимальный размер строки
* должен задаваться. Обязательно должны быть реализованы: длина строки, поиск подстроки в строке,
* удаление подстроки из строки, вставка подстроки в строку, сцепление двух строк.
*/

#include <iostream>

using namespace std;

// Определение класса String для работы со строками аналогично Turbo Pascal
class String {
private:
    static const int MAX_SIZE = 256; // Максимальный размер строки, включая байт длины
    char data[MAX_SIZE]; // Массив символов, где data[0] - это длина строки

    // Функция для вычисления длины строки
    static int strLength(const char* str) {
        int length = 0; // Длина строки
        // Проходимся по строке до тех пор, пока не встретим нулевой символ или не достигнем максимального размера
        while (str[length] != '\0' && length < MAX_SIZE - 1) ++length;
        return length;
    }

    // Функция для копирования строки
    static void strCopy(char* dest, const char* src, int length) {
        // Копируем символы из исходной строки в целевую
        for (int i = 0; i < length; ++i) {
            dest[i] = src[i]; // Копируем символ
        }
    }

public:
    // Конструктор по умолчанию
    String() {
        data[0] = 0; // Инициализируем длину строки как 0
    }

    // Инициализирующий конструктор
    String(const char* str) {
        int length = strLength(str); // Вычисляем длину строки
        length = (length < MAX_SIZE - 1) ? length : MAX_SIZE - 1; // Ограничиваем длину строки
        data[0] = static_cast<char>(length); // Записываем длину строки
        strCopy(data + 1, str, length); // Копируем символы строки
    }

    // Конструктор копирования
    String(const String& other) {
        strCopy(this->data, other.data, other.data[0] + 1); // Копируем данные из другой строки
    }

    // Метод для вывода строки
    void print() const {
        cout.write(data + 1, data[0]); // Выводим символы строки
        cout << endl; 
    }

    // Преобразование в строку C++
    string toString() const {
        return string(data + 1, data[0]); // Создаём строку C++ из символов строки
    }

    // Получение длины строки
    int length() const {
        return static_cast<unsigned char>(data[0]); // Возвращаем длину строки
    }

    // Поиск подстроки в строке
    int find(const String& substring) const {
        // Перебираем все возможные начальные позиции для подстроки
        for (int i = 1; i <= this->length() - substring.length() + 1; ++i) {
            bool found = true; // Флаг, что подстрока найдена
            // Проверяем, совпадает ли каждый символ подстроки с символом основной строки
            for (int j = 0; j < substring.length(); ++j) {
                if (data[i + j] != substring.data[j + 1]) {
                    found = false; // Сбрасываем флаг
                    break; // Выходим из цикла
                }
            }
            if (found) {
                return i - 1; // Возвращаем позицию начала подстроки
            }
        }
        return -1; // Подстрока не найдена
    }

    // Вставка подстроки в строку
    void insert(const String& substring, int position) {
        int thisLen = this->length(); // Длина текущей строки
        int subLen = substring.length(); // Длина вставляемой подстроки
        // Проверка на валидность позиции и возможное переполнение строки
        if (position > thisLen || position < 0 || thisLen + subLen >= 255) return;

        // Сдвигаем существующие символы, чтобы освободить место для подстроки
        for (int i = thisLen; i >= position; --i) {
            data[i + subLen + 1] = data[i + 1]; // Сдвигаем символы
        }

        // Вставляем подстроку
        for (int i = 0; i < subLen; ++i) {
            data[position + i + 1] = substring.data[i + 1]; // Вставляем символы
        }

        data[0] += static_cast<char>(subLen); // Обновляем длину строки
        data[thisLen + subLen + 1] = '\0'; // Гарантируем наличие нулевого символа в конце
    }

    // Удаление подстроки из строки
    void remove(int position, int length) {
        int thisLen = this->length(); // Длина текущей строки

        // Проверка на валидность позиции и длины подстроки
        if (position < 0 || position + length >= thisLen) return;

        // Сдвигаем символы на место удалённой подстроки
        for (int i = position + length; i < thisLen; ++i) {
            data[i - length + 1] = data[i + 1]; // Сдвигаем символы
        }

        data[0] -= static_cast<char>(length); // Обновляем длину строки
        data[thisLen - length + 1] = '\0'; // Гарантируем наличие нулевого символа в конце
    }

    // Сцепление двух строк
    String operator+(const String& other) const {
        String result; // Результирующая строка
        int thisLen = this->length(); // Длина текущей строки
        int otherLen = other.length(); // Длина второй строки
        
        // Вычисляем новую длину строки
        int newLength = (thisLen + otherLen <= 255) ? (thisLen + otherLen) : 255;
        
        // Записываем новую длину строки
        result.data[0] = static_cast<char>(newLength);

        strCopy(result.data + 1, this->data + 1, thisLen); // Копируем символы текущей строки
        strCopy(result.data + thisLen + 1, other.data + 1, newLength - thisLen); // Копируем символы второй строки

        return result; // Возвращаем результат
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


