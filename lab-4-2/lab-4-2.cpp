#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const int numX = 8; // Количество столбцов (x)
    const int numY = 10; // Количество строк (y)
    const int number = 94; // Количество символов для линии
    const int precision = 2;
    const char symbol = '-'; // Символ для линии
    string repeated(number, symbol); // Создаем строку, состоящую из повторяющихся символов


    // Вывод заголовка для столбцов x
    cout << "y/x  |";
    for (int col = 0; col <= numY; col++)
    {
        double x = -1.0 + col * 0.2; // Вычисляем значение x
        cout << setw(8) << fixed << setprecision(1) << x; // Выводим x с заданным форматированием
        Sleep(5);
    }
    cout << endl; // Переход на новую строку

    // Вывод разделительной линии
    cout << repeated << endl;

    // Главный цикл для вычислений и вывода результатов
    for (int i = 0; i <= numX; i++)
    {
        double y = -2.0 + i * 0.5; // Вычисляем значение y

        // Вывод значения y, с учетом форматирования
        if (y < 0)
        {
            cout << setprecision(1) << y << setw(2) << "|"; // Выводим y с форматированием
        }
        else
        {
            cout << " " << setprecision(1) << y << setw(2) << "|"; // Выводим y с форматированием
        }

        Sleep(5);

        // Вложенный цикл для вычисления результатов для каждого x
        for (int j = 0; j <= numY; j++)
        {
            double x = -1.0 + j * 0.2; // Вычисляем значение x
            double up = pow(x, 2) + pow(y, 2); // Вычисляем числитель
            double down = pow(x, 3) - pow(y, 3); // Вычисляем знаменатель

            // Проверяем деление на ноль
            if (down == 0)
            {
                cout << setw(8) << "ERROR"; // Выводим сообщение об ошибке, если деление на ноль
            }
            else
            {
                double result = up / down; // Вычисляем результат деления
                cout << setw(8) << setprecision(precision) << result; // Выводим результат с учетом форматирования
            }

            Sleep(5);
        }
        cout << endl; // Переход на новую строку после каждой итерации y
    }
    cout << "\n\n*ERROR - Ошибка возникающая при делении на ноль" << endl; // Вывод сообщения об ошибке, если деление на ноль
}