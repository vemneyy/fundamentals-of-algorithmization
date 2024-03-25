/*
* Создайте динамическую переменную, которая является структурой с полями: фамилия, год рождения, рост и вес человека. 
* Соответственно задайте значения полей: Иванов, 1939, 174, 72. Затем выведите содержимое этой записи на экран дисплея
*/

#include <iostream>
#include <string>

using namespace std;

struct Person {
    string surname;
    int yearOfBirth;
    int height;
    int weight;
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Создаем динамический экземпляр структуры Person
    Person* personPtr = new Person{ "Иванов", 1939, 174, 72 };

    // Получаем ссылку на созданный экземпляр, чтобы использовать синтаксис с точкой
    Person& person = *personPtr;

    // Выводим информацию о человеке, используя синтаксис с точкой
    cout << "Фамилия: " << person.surname << endl;
    cout << "Год рождения: " << person.yearOfBirth << endl;
    cout << "Рост: " << person.height << " см" << endl;
    cout << "Вес: " << person.weight << " кг" << endl;

    // Освобождаем выделенную под структуру память
    delete personPtr;

    return 0;
}
