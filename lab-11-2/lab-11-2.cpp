/*
* С помощью динамических переменных реализуйте вещественную матрицу размером 100×200. 
* Каждому элементу матрицы присвойте случайное значение из заданного диапазона. 
* Отсортируйте элементы массива по сквозному порядку их размещения в матрице как в одномерном массиве. 
* Выдайте на экран первую подматрицу размером 10×20. Для сортировки используйте метод пузырька.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int rows = 100;
    const int cols = 200;
    vector<vector<float>> matrix(rows, vector<float>(cols));
    vector<float> flatMatrix(rows * cols);

    srand(static_cast<unsigned>(time(0)));

    // Заполнение матрицы и одномерного массива
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            float value = static_cast<float>(rand()) / RAND_MAX * 100; // Примерный диапазон [0, 100)
            matrix[i][j] = value;
            flatMatrix[i * cols + j] = value;
        }
    }

    // Сортировка
    for (size_t i = 0; i < flatMatrix.size(); i++) {
        for (size_t j = 0; j < flatMatrix.size() - i - 1; j++) {
            if (flatMatrix[j] > flatMatrix[j + 1]) {
                swap(flatMatrix[j], flatMatrix[j + 1]);
            }
        }
    }

    cout << "Первая подматрица 10x20:" << endl; 

    // Вывод первой подматрицы 10x20
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 20; ++j) {
            cout << fixed << setprecision(4) << flatMatrix[i * 20 + j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
