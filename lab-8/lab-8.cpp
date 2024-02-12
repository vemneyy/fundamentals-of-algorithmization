/* ���� ������. ������ ������ ��������� ����� ������������������ ���� ����������
��������; ����� ��������� ������� - �� ����� ������ �������, �� ��������� ������ �
�����. ����� � ��������� � ������ �� ����� ������������������, ������� ������� ��
���������� ����� � ������������� ���������� ��������: ����� ��������� � ���������
�������� ���������� �������� (a, ab, abc, abcd,�). ��� ��������� ����� �������. */

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    do {
        cout << "������� ������: ";
        getline(cin, input);
    } while (input.empty());

    for (char& letter : input) {
        letter = tolower(letter);
    }

    cout << "\n�������� ������: " << input << endl;

    // ���� ������ �� ������ � ��������� ������ �������� �����
    if (!input.empty() && input.back() == '.') {
        // �������� ���������� �������� �� ������
        input.pop_back();
    }

    int j = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != ' ' || (i > 0 && input[i - 1] != ' ')) {
            input[j++] = input[i];
        }
    }

    input.resize(j);

    cout << "\n������ ����� �������� ��������: " << input << endl;


    // ������� ������ ���������� �����
    // ��������� ����� � ������� ������ ����� � �� ����� ������
    string last_word = input.substr(input.find_last_of(' ') + 1);

    int read_index = 0, write_index = 0, word_start = 0;

    // ���� ������ ������ ������ ������� ������
    while (read_index < input.size()) {
        // ���� ������� � �������� ������ �������� �������� ��� �������� ��������� �������� � ������
        if (input[read_index] == ' ') {
            // ��������� ����� ���� � ������� ������ ����� �� ������� read_index - wordStart
            string current_word = input.substr(word_start, read_index - word_start);
            // ����� �������� ��� �������
            bool valid_word = true;

            // ���� i ������ ������ ���������� �����
            for (int i = 0; i < current_word.length(); i++) {

                // ���� ������ ���������� ����� �� ��������� � 'a' + i, �� ����� ��������� �� �������������� �������
                if (current_word[i] != 'a' + i) {
                    valid_word = false;
                    break;
                }
            }

            // ���� ����� ������������ ������� � ��������� ����� �� �������� ���������
            if (valid_word && current_word != last_word) {

                // ���� ������ ������ ������ 0
                if (write_index > 0) {
                    input[write_index++] = ' '; // ��������� ������ ����� ������, ���� ��� �� ������ �����
                }

                // ��� ������ ��������� ���������� � ����� ��������� �������� ���������� ��������
                for (char symbol_of_current_word : current_word) {
                    input[write_index++] = symbol_of_current_word;
                }
            }

            // ������ ����� ����� ������� ������ + 1
            word_start = read_index + 1;
        }

        // ��������� read_index
        read_index++;
    }

    input.resize(write_index); // �������� ������ �� ������ �������

    if (input.empty()) {
        cout << "\n������������ ������ �����." << endl;
    }

    else {
        cout << "\n������������ ������: " << input << endl;
    }

    return 0;
}