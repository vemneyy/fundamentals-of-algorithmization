#include <iostream>
#include <iomanip> // ��� ���������� ������� ����� � ��������� �������
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	float matrix[3][3];
	int N = 3;
	// ���� �������� �������
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "������� �������� " << i + 1 << " ������ � " << j + 1 << " �������: ";
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	// ����� �������
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	float sum = 0;
	// ���������� ������� �������� �� ���������� � �� �����
	for (int i = 0, count = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// �������� �� �������������� �������� � ���������
			if ((i + j) % 2 == 0) {
				sum += matrix[j][i];
				count++;
			}
		}
		// ����� �������� �������� ��� ������� ���������
		cout << "��� ��������� ������� " << i + 1 << " ������� �������� ��������� � ������ ������ ��������: " << fixed << setprecision(2) << float(sum / count);
		count = 0;
		sum = 0;
		cout << endl;
	}
	return 0;
}
