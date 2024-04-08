/*
* ������� �2. ����������� � ����������� ��������; �� ���� ��������� ���� �������� ������ ���� �����������: 
* ��������������  � ���������������� �����������, ����������� �����������, ����-�����, �������������� � ������. 
*
* ������� 14. ������� ����� string ��� ������ �� ��������, ������������ ������� Turbo Pascal
* (������ �������������� ��� ������ 255 ������, ����� � � ������ �����). ������������ ������ ������
* ������ ����������. ����������� ������ ���� �����������: ����� ������, ����� ��������� � ������,
* �������� ��������� �� ������, ������� ��������� � ������, ��������� ���� �����.
*/

#include <iostream>

using namespace std;

// ����������� ������ String ��� ������ �� �������� ���������� Turbo Pascal
class String {
private:
    static const int MAX_SIZE = 256; // ������������ ������ ������, ������� ���� �����
    char data[MAX_SIZE]; // ������ ��������, ��� data[0] - ��� ����� ������

    // ������� ��� ���������� ����� ������
    static int strLength(const char* str) {
        int length = 0; // ����� ������
        // ���������� �� ������ �� ��� ���, ���� �� �������� ������� ������ ��� �� ��������� ������������� �������
        while (str[length] != '\0' && length < MAX_SIZE - 1) ++length;
        return length;
    }

    // ������� ��� ����������� ������
    static void strCopy(char* dest, const char* src, int length) {
        // �������� ������� �� �������� ������ � �������
        for (int i = 0; i < length; ++i) {
            dest[i] = src[i]; // �������� ������
        }
    }

public:
    // ����������� �� ���������
    String() {
        data[0] = 0; // �������������� ����� ������ ��� 0
    }

    // ���������������� �����������
    String(const char* str) {
        int length = strLength(str); // ��������� ����� ������
        length = (length < MAX_SIZE - 1) ? length : MAX_SIZE - 1; // ������������ ����� ������
        data[0] = static_cast<char>(length); // ���������� ����� ������
        strCopy(data + 1, str, length); // �������� ������� ������
    }

    // ����������� �����������
    String(const String& other) {
        strCopy(this->data, other.data, other.data[0] + 1); // �������� ������ �� ������ ������
    }

    // ����� ��� ������ ������
    void print() const {
        cout.write(data + 1, data[0]); // ������� ������� ������
        cout << endl; 
    }

    // �������������� � ������ C++
    string toString() const {
        return string(data + 1, data[0]); // ������ ������ C++ �� �������� ������
    }

    // ��������� ����� ������
    int length() const {
        return static_cast<unsigned char>(data[0]); // ���������� ����� ������
    }

    // ����� ��������� � ������
    int find(const String& substring) const {
        // ���������� ��� ��������� ��������� ������� ��� ���������
        for (int i = 1; i <= this->length() - substring.length() + 1; ++i) {
            bool found = true; // ����, ��� ��������� �������
            // ���������, ��������� �� ������ ������ ��������� � �������� �������� ������
            for (int j = 0; j < substring.length(); ++j) {
                if (data[i + j] != substring.data[j + 1]) {
                    found = false; // ���������� ����
                    break; // ������� �� �����
                }
            }
            if (found) {
                return i - 1; // ���������� ������� ������ ���������
            }
        }
        return -1; // ��������� �� �������
    }

    // ������� ��������� � ������
    void insert(const String& substring, int position) {
        int thisLen = this->length(); // ����� ������� ������
        int subLen = substring.length(); // ����� ����������� ���������
        // �������� �� ���������� ������� � ��������� ������������ ������
        if (position > thisLen || position < 0 || thisLen + subLen >= 255) return;

        // �������� ������������ �������, ����� ���������� ����� ��� ���������
        for (int i = thisLen; i >= position; --i) {
            data[i + subLen + 1] = data[i + 1]; // �������� �������
        }

        // ��������� ���������
        for (int i = 0; i < subLen; ++i) {
            data[position + i + 1] = substring.data[i + 1]; // ��������� �������
        }

        data[0] += static_cast<char>(subLen); // ��������� ����� ������
        data[thisLen + subLen + 1] = '\0'; // ����������� ������� �������� ������� � �����
    }

    // �������� ��������� �� ������
    void remove(int position, int length) {
        int thisLen = this->length(); // ����� ������� ������

        // �������� �� ���������� ������� � ����� ���������
        if (position < 0 || position + length >= thisLen) return;

        // �������� ������� �� ����� �������� ���������
        for (int i = position + length; i < thisLen; ++i) {
            data[i - length + 1] = data[i + 1]; // �������� �������
        }

        data[0] -= static_cast<char>(length); // ��������� ����� ������
        data[thisLen - length + 1] = '\0'; // ����������� ������� �������� ������� � �����
    }

    // ��������� ���� �����
    String operator+(const String& other) const {
        String result; // �������������� ������
        int thisLen = this->length(); // ����� ������� ������
        int otherLen = other.length(); // ����� ������ ������
        
        // ��������� ����� ����� ������
        int newLength = (thisLen + otherLen <= 255) ? (thisLen + otherLen) : 255;
        
        // ���������� ����� ����� ������
        result.data[0] = static_cast<char>(newLength);

        strCopy(result.data + 1, this->data + 1, thisLen); // �������� ������� ������� ������
        strCopy(result.data + thisLen + 1, other.data + 1, newLength - thisLen); // �������� ������� ������ ������

        return result; // ���������� ���������
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    String hello("������, ");
    String world("���!");
    String greetings = hello + world;
    greetings.print();

    String phrase("��� �������� ���������������!");
    phrase.insert(String("�� "), 4);
    phrase.print();

    phrase.remove(4, 3);
    phrase.print();

    cout << "������� '��������': " << phrase.find(String("��������")) << endl;

    return 0;
}


