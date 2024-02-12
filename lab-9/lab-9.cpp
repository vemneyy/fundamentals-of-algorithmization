#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Для функции std::swap

struct Student {
    std::string name;     // Имя студента
    std::string language; // Язык, на котором говорит студент
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Student> students; // Вектор для хранения информации о студентах

    int number_of_students;
    std::cout << "Введите количество студентов в группе: ";
    std::cin >> number_of_students;
    std::cin.ignore(); // Игнорируем символ новой строки во входном потоке

    // Ввод информации о студентах
    for (int i = 0; i < number_of_students; i++) {
        std::cout << "Введите имя студента " << i + 1 << ": ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Введите язык студента " << i + 1 << ": ";
        std::string language;
        std::getline(std::cin, language);

        students.push_back({ name, language });
    }

    // Сортировка студентов по языку
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.language < b.language;
        });

    // Вывод информации о студентах, сгруппированных по языку
    for (int i = 0; i < number_of_students; i++) {
        // Проверка на изменение языка
        if (i == 0 || students[i].language != students[i - 1].language) {
            std::cout << "\n" << students[i].language << ":\n";
        }
        std::cout << students[i].name << std::endl;
    }

    return 0;
}
