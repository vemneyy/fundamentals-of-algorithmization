/* 
   1) Создать в файле последовательность N вещественных чисел. Вывести разность первого и последнего элемента.
   2) Данный файл Assort, содержащий строки с информацией о товарах: название товара, его стоимость, минимальный и максимальный возраст
   (например, товар может подходить для детей от двух до пяти лет).
   Вывести названия товаров, подходящих для детей в возрасте от 4 до 10 лет включительно.
   3) Данный файл, содержащий слова на русском языке и некоторые символы. Подсчитать, сколько слов начинается с заданной буквы.
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <windows.h>
#include <string>
#include <iomanip>

using namespace std;

struct Toy {
    string name;
    float cost;
    int min_age;
    int max_age;
};

int first_exercise() {
    cout << "\nЗадание 1" << endl;

    ofstream file_f("first_ex.txt");
    if (!file_f.is_open())
    {
        cout << "Файл не может быть открыт!" << endl;
        return 1;
    }
    else
    {
        cout << "Файл открыт для записи!" << endl;
    }

    int input_number;
    cout << "\nВведите количество вещественных чисел: ";
    cin >> input_number;

    double first_number, last_number;

    for (int i = 0; i < input_number; i++)
    {
        double number;
        cout << "Введите число " << i + 1 << ": ";
        if (i == 0) {
            cin >> number;
            first_number = number;
            file_f << fixed << setprecision(8) << number << " ";
        }
        else if (i == input_number - 1) {
            cin >> number;
            last_number = number;

            double result = first_number - last_number;
            file_f << number << " " << endl << "Разность первого и последнего элемента: " << result << endl;
            cout << "Разность первого и последнего элемента: " << fixed << setprecision(8) << result << endl;
        }
        else {
            cin >> number;
            file_f << fixed << setprecision(8) << number << " ";
        }
    }

    file_f.close();
    cout << "\nЗавершено. Файл закрыт.\n" << endl;

    return 0;
}

int second_exercise() {
    cout << "\nЗадание 2" << endl;

    ifstream file_s("Assort.txt");
    if (!file_s.is_open())
    {
        cout << "Файл не может быть открыт!\n" << endl;
        return 1;
    }
    else
    {
        cout << "Файл открыт для чтения!\n" << endl;
    }

    Toy toy;
    while (file_s >> toy.name >> toy.cost >> toy.min_age >> toy.max_age) {
        if (toy.min_age <= 4 && toy.max_age >= 10) {
            cout << toy.name << endl;
        }
    }

    file_s.close();
    cout << "\nФайл закрыт.\n" << endl;

    return 0;
}

int third_exercise() {
    cout << "\nЗадание 3" << endl;
    string filename = "third_ex.txt";

    char target_letter;
    cout << "Введите букву для подсчета слов: ";
    cin >> target_letter;

    ifstream file_t(filename);
    if (!file_t.is_open()) {
        cout << "Файл не может быть открыт!\n" << endl;
        return -1;
    }
    else
    {
        cout << "Файл открыт для чтения!\n" << endl;
    }

    char letter;
    int count = 0;
    string word;

    while (file_t >> word) {
        letter = word[0];
        if (tolower(letter) == tolower(target_letter)) {
            count++;
        }
    }

    if (count != -1) {
        cout << "Количество слов, начинающихся с буквы '" << target_letter << "': " << count << endl;
    }

    file_t.close();
    cout << "\nФайл закрыт." << endl << endl;

    return 0;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Лабораторная работа №10" << endl;
    int exercise;
    do {
        cout << "Введите номер задания (1-3, 0 - для выхода): ";
        cin >> exercise;

        switch (exercise)
        {
        case 1:
            first_exercise();
            break;
        case 2:
            second_exercise();
            break;
        case 3:
            third_exercise();
            break;
        case 0:
            return 0;
        default:
            cout << "Такого задания нет." << endl;
            break;
        }
    } while (exercise != 0);

    return 0;
}
