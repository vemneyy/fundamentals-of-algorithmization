#include <iostream>
#include <iomanip> 
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);

    // ���������� ����������
    int k, n;
    double overallSum = 0;
    int maxSubjectCount = 0, maxCount = 0, m = 1;

    // ��������� ����� ��� ���������� ��������� (k) � ��������� (n)
    cout << "������� k: ";
    cin >> k;
    cout << "������� n: ";
    cin >> n;

    // ������ ������ ���������� ���������
    int subjects = k * n;

    // ������������ ��������� ������ ��� ���������� ������� ��� �������� ������ ������� �������� � ��������
    int** table = new int* [k];
    for (int i = 0; i < k; i++)
    {
        table[i] = new int[n];
    }

    // �������������� ������� ��� ������������ ��������� � �������� � ���������� ����� �� ���������
    int* foolStud = new int[k]();
    int* foolCount = new int[n]();

    cout << endl;

    // ���� ������ ��� ������� �������� � ��������
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
        data:

            cout << "������� ������ ��� " << i + 1 << " ������ � " << j + 1 << " �������: ";
            cin >> table[i][j];

            // �������� ��������� ������ �� ������������
            if (table[i][j] < 2 || table[i][j] > 5)
            {
                cout << "������ ������ ���� �� ����� 2 � �� ����� 5." << endl;
                goto data;
            }

            // ���������� �������� ����� �� ���������
            if (table[i][j] == 2)
            {
                foolCount[j]++;
            }
        }
        cout << endl;
    }

    cout << endl;

    // ����������� �������� � ���������� ����������� �����
    for (int j = 0; j < n; j++)
    {
        if (foolCount[j] > maxCount)
        {
            maxCount = foolCount[j];
            maxSubjectCount = j;
        }
    }

    // ������ ������� ������ ��� ������� �������� � ������� ��������� � ����� � ����� ��������
    for (int i = 0; i < k; i++)
    {
        double sum = 0;
        int deuces = 0;

        for (int j = 0; j < n; j++)
        {
            sum += table[i][j];
            overallSum += table[i][j];

            // ������� ����� � ��������
            if (table[i][j] == 2)
            {
                deuces++;
            }
        }

        // ������ ������� ������ ��� ��������
        double average = sum / n;

        cout << "������� ������ ��� �������� ����� " << i + 1 << " �����: " << setprecision(3) << average << endl;

        // ����� ����������, ���� � �������� ��� � ����� ������
        if (deuces >= m)
        {
            cout << "� ����� �������� " << deuces << " ������(��)" << endl;
            foolStud[i] = i + 1;
        }
        cout << endl;
    }

    // ������ ����� ������� ������ ��� ���� ��������� � ���������
    double overallAverage = overallSum / subjects;
    cout << "\n����� ������� ������ ��� ���� ��������� � ���������: " << setprecision(3) << overallAverage << endl;

    // ����� ������� ��������� � ����� � ����� ��������
    cout << "\n������ ��������� � " << m << " ��� ����� ��������:";
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

    // ����� �������� � ���������� ����������� �������������������� ������
    cout << "\n\n������� " << maxSubjectCount + 1 << " � ���������� ����������� �������������������� ������: " << maxCount << endl;

    // ������������ ���������� ������
    delete[] table;
    delete[] foolStud;
    delete[] foolCount;

    return 0;
}