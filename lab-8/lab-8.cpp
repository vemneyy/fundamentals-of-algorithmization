/* Дана строка. Словом текста считается любая последовательность букв латинского
алфавита; между соседними словами - не менее одного пробела, за последним словом –
точка. Найти и сохранить в строке те слова последовательности, которые отличны от
последнего слова и удовлетворяют следующему свойству: слово совпадает с начальным
отрезком латинского алфавита (a, ab, abc, abcd,…). Все остальные слова удалить. */

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    do {
        cout << "Введите строку: ";
        getline(cin, input);
    } while (input.empty());

    for (char& letter : input) {
        letter = tolower(letter);
    }

    cout << "\nВведённая строка: " << input << endl;

    // Если строка не пустая и последний символ является точно
    if (!input.empty() && input.back() == '.') {
        // Удаление последнего элемента из строки
        input.pop_back();
    }

    int j = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != ' ' || (i > 0 && input[i - 1] != ' ')) {
            input[j++] = input[i];
        }
    }

    input.resize(j);

    cout << "\nСтрока после удаления пробелов: " << input << endl;


    // Находим начало последнего слова
    // Последнее слово с индекса начала слова и до конца строки
    string last_word = input.substr(input.find_last_of(' ') + 1);

    int read_index = 0, write_index = 0, word_start = 0;

    // Пока индекс чтения меньше размера строки
    while (read_index < input.size()) {
        // Если элемент с индексом чтения является пробелом или является последним символом в строке
        if (input[read_index] == ' ') {
            // Выбранное слово берём с индекса начала слова до индекса read_index - wordStart
            string current_word = input.substr(word_start, read_index - word_start);
            // Слово подходит под условие
            bool valid_word = true;

            // Пока i меньше длинны выбранного слова
            for (int i = 0; i < current_word.length(); i++) {

                // Если индекс выбранного слова не совпадает с 'a' + i, то слова считается не соответсвующим условию
                if (current_word[i] != 'a' + i) {
                    valid_word = false;
                    break;
                }
            }

            // Если слово соответсвует условию и выбранное слово не является последним
            if (valid_word && current_word != last_word) {

                // Если индекс записи больше 0
                if (write_index > 0) {
                    input[write_index++] = ' '; // Добавляем пробел перед словом, если это не первое слово
                }

                // При каждой иттерации переменная с будет принимать значение следующего элемента
                for (char symbol_of_current_word : current_word) {
                    input[write_index++] = symbol_of_current_word;
                }
            }

            // Начало слова равно индексу чтения + 1
            word_start = read_index + 1;
        }

        // Инкремент read_index
        read_index++;
    }

    input.resize(write_index); // Обрезаем строку до нового размера

    if (input.empty()) {
        cout << "\nОбработанная строка пуста." << endl;
    }

    else {
        cout << "\nОбработанная строка: " << input << endl;
    }

    return 0;
}