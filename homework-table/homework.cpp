#include <iostream>
#include <iomanip> 
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);

    // Объявление переменных
    int k, n;
    double overallSum = 0;
    int maxSubjectCount = 0, maxCount = 0, m = 1;


    // Получение ввода для количества студентов (k) и предметов (n)
    cout << "Введите k: ";
    cin >> k;
    cout << "Введите n: ";
    cin >> n;

    // Расчет общего количества предметов
    int subjects = k * n;

    // Динамическое выделение памяти для двумерного массива для хранения оценок каждого студента и предмета
    int** table = new int* [k];
    for (int i = 0; i < k; i++)
    {
        table[i] = new int[n];
    }

    // Дополнительные массивы для отслеживания студентов с двойками и количества двоек по предметам
    int* foolStud = new int[k]();
    int* foolCount = new int[n]();

    cout << endl;

    // Ввод оценок для каждого студента и предмета
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
        data:

            cout << "Введите оценку для " << i + 1 << " строки и " << j + 1 << " столбца: ";
            cin >> table[i][j];

            // Проверка введенных оценок на корректность
            if (table[i][j] < 2 || table[i][j] > 5)
            {
                cout << "Оценка должна быть не менее 2 и не более 5." << endl;
                goto data;
            }

            // Увеличение счетчика двоек по предметам
            if (table[i][j] == 2)
            {
                foolCount[j]++;
            }
        }
        cout << endl;
    }

    cout << endl;

    // Определение предмета с наибольшим количеством двоек
    for (int j = 0; j < n; j++)
    {
        if (foolCount[j] > maxCount)
        {
            maxCount = foolCount[j];
            maxSubjectCount = j;
        }
    }

    // Расчет средней оценки для каждого студента и подсчет студентов с двумя и более двойками
    for (int i = 0; i < k; i++)
    {
        double sum = 0;
        int deuces = 0;

        for (int j = 0; j < n; j++)
        {
            sum += table[i][j];
            overallSum += table[i][j];

            // Подсчет двоек у студента
            if (table[i][j] == 2)
            {
                deuces++;
            }
        }

        // Расчет средней оценки для студента
        double average = sum / n;

        cout << "Средняя оценка для студента номер " << i + 1 << " равна: " << setprecision(3) << average << endl;

        // Вывод информации, если у студента две и более двойки
        if (deuces >= m)
        {
            cout << "У этого студента " << deuces << " двойки(ок)" << endl;
            foolStud[i] = i + 1;
        }
        cout << endl;
    }

    // Расчет общей средней оценки для всех студентов и предметов
    double overallAverage = overallSum / subjects;
    cout << "\nОбщая средняя оценка для всех студентов и предметов: " << setprecision(3) << overallAverage << endl;

    // Вывод номеров студентов с двумя и более двойками
    cout << "\nНомера студентов с " << m << " или более двойками:";
    for (int z = 0, l = 0; z < k; z++)
    {
        if (foolStud[z] != 0)
            if (l == 0)
            {
                cout << setw(2) << foolStud[z];
                l++;
            }
            else
            {
                cout << "," << setw(2) << foolStud[z];
            }
    }

    // Вывод предмета с наибольшим количеством неудовлетворительных оценок
    cout << "\n\nПредмет " << maxSubjectCount + 1 << " с наибольшим количеством неудовлетворительных оценок: " << maxCount << endl;

    // Освобождение выделенной памяти
    delete[] table;
    delete[] foolStud;
    delete[] foolCount;

    return 0;
}