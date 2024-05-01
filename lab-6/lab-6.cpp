#include <iostream>
#include <iomanip> // Для управления выводом чисел с плавающей запятой
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	float matrix[3][3];
	int N = 3;
	// Ввод значений матрицы
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "Введите значение " << i + 1 << " строки и " << j + 1 << " столбца: ";
			cin >> matrix[i][j];
		}
		cout << endl;
	}

	// Вывод матрицы
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	float sum = 0;
	// Вычисление средних значений по диагоналям и их вывод
	for (int i = 0, count = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// Проверка на принадлежность элемента к диагонали
			if ((i + j) % 2 == 0) {
				sum += matrix[j][i];
				count++;
			}
		}
		// Вывод среднего значения для текущей диагонали
		cout << "Для диагонали матрицы " << i + 1 << " среднее значение элементов с четной суммой индексов: " << fixed << setprecision(2) << float(sum / count);
		count = 0;
		sum = 0;
		cout << endl;
	}
	return 0;
}
