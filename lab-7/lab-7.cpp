#include <iostream>
#include <vector>
#include <algorithm>
#include <locale> // Для setlocale
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    vector<int> numbers;
    int n, a, b;


    cout << "Введите количество чисел в последовательности: ";
    cin >> n;

    if (n <= 0) {
        cout << "Некорректное количество чисел в последовательности.\n" << endl;
        return 1;
    }

    for (int i = 0, k; i < n; i++) {
        cout << "Введите значение для " << i << " элемента: ";
        cin >> k;
        numbers.push_back(k);
    }

    cout << "\nЭлементы последовательности: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i == 0) {
            cout << numbers[i];
        }
        else {
            cout << ", " << numbers[i];
        }
    }

    cout << "\n\nВведите начальное и конечное значения диапазона: ";
    cin >> a >> b;

    if (a > b) {
        cout << "Некорректно задан диапазон." << endl;
        return 1;
    }

    numbers.erase(
        remove_if(numbers.begin(), numbers.end(), [a, b](int i) {return i >= a && i <= b; }),
        numbers.end()
    );

    if (numbers.empty()) {
        cout << "\nВсе элементы последовательности удалены." << endl;
    }

    else {
        cout << "\nЭлементы последовательности после удаления элементов из заданного диапазона: ";
        for (size_t i = 0; i < numbers.size(); i++) {
            if (i == 0) {
                cout << numbers[i];
            }
            else {
                cout << ", " << numbers[i];
            }
        }

        int min_value = *min_element(numbers.begin(), numbers.end());

        cout << "\nИндексы элементов с минимальным значением: ";
        for (size_t i = 0; i < numbers.size(); i++) {
            if (numbers[i] == min_value) {
                cout << i << ", ";
            }
        }

        sort(numbers.begin(), numbers.end());

        cout << "\n\nЭлементы последовательности после сортировки: ";
        for (size_t i = 0; i < numbers.size(); i++) {
            if (i == 0) {
                cout << numbers[i];
            }
            else {
                cout << ", " << numbers[i];
            }
        }

        cout << "\nИндексы элементов с минимальным значением после сортировки: ";
        for (size_t i = 0; i < numbers.size(); i++) {
            if (numbers[i] == min_value) {
                cout << i << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
