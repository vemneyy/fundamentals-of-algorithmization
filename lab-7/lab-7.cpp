#include <iostream>
#include <vector>
#include <algorithm>
#include <locale> // ��� setlocale
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    vector<int> numbers;
    int n, a, b;


    cout << "������� ���������� ����� � ������������������: ";
    cin >> n;

    if (n <= 0) {
        cout << "������������ ���������� ����� � ������������������.\n" << endl;
        return 1;
    }

    for (int i = 0, k; i < n; i++) {
        cout << "������� �������� ��� " << i << " ��������: ";
        cin >> k;
        numbers.push_back(k);
    }

    cout << "\n�������� ������������������: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i == 0) {
            cout << numbers[i];
        }
        else {
            cout << ", " << numbers[i];
        }
    }

    cout << "\n\n������� ��������� � �������� �������� ���������: ";
    cin >> a >> b;

    if (a > b) {
        cout << "����������� ����� ��������." << endl;
        return 1;
    }

    numbers.erase(
        remove_if(numbers.begin(), numbers.end(), [a, b](int i) {return i >= a && i <= b; }),
        numbers.end()
    );

    if (numbers.empty()) {
        cout << "\n��� �������� ������������������ �������." << endl;
    }

    else {
        cout << "\n�������� ������������������ ����� �������� ��������� �� ��������� ���������: ";
        for (size_t i = 0; i < numbers.size(); i++) {
            if (i == 0) {
                cout << numbers[i];
            }
            else {
                cout << ", " << numbers[i];
            }
        }

        int min_value = *min_element(numbers.begin(), numbers.end());

        cout << "\n������� ��������� � ����������� ���������: ";
        for (size_t i = 0; i < numbers.size(); i++) {
            if (numbers[i] == min_value) {
                cout << i << ", ";
            }
        }

        sort(numbers.begin(), numbers.end());

        cout << "\n\n�������� ������������������ ����� ����������: ";
        for (size_t i = 0; i < numbers.size(); i++) {
            if (i == 0) {
                cout << numbers[i];
            }
            else {
                cout << ", " << numbers[i];
            }
        }

        cout << "\n������� ��������� � ����������� ��������� ����� ����������: ";
        for (size_t i = 0; i < numbers.size(); i++) {
            if (numbers[i] == min_value) {
                cout << i << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
