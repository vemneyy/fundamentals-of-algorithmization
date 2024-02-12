#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // ��� ������� std::swap

struct Student {
    std::string name;     // ��� ��������
    std::string language; // ����, �� ������� ������� �������
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Student> students; // ������ ��� �������� ���������� � ���������

    int number_of_students;
    std::cout << "������� ���������� ��������� � ������: ";
    std::cin >> number_of_students;
    std::cin.ignore(); // ���������� ������ ����� ������ �� ������� ������

    // ���� ���������� � ���������
    for (int i = 0; i < number_of_students; i++) {
        std::cout << "������� ��� �������� " << i + 1 << ": ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "������� ���� �������� " << i + 1 << ": ";
        std::string language;
        std::getline(std::cin, language);

        students.push_back({ name, language });
    }

    // ���������� ��������� �� �����
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.language < b.language;
        });

    // ����� ���������� � ���������, ��������������� �� �����
    for (int i = 0; i < number_of_students; i++) {
        // �������� �� ��������� �����
        if (i == 0 || students[i].language != students[i - 1].language) {
            std::cout << "\n" << students[i].language << ":\n";
        }
        std::cout << students[i].name << std::endl;
    }

    return 0;
}
