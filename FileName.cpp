#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int get_number(std::string word, std::vector<char> alphabet) {
    
    // ���������� �������� � ��������
    int n = alphabet.size();
    // ���������� �������� � �����
    int k = word.size();

    std::cout << " n = " << n << ", k = " << k << std::endl;
    std::string formula = " ";

    int result = 0;
    for (int i = 1; i <= k; ++i) {
        char ch = word[i - 1];
        int char_index = 0;
        bool char_found = false;
        for (int j = 0; j < n; ++j) {
            if (alphabet[j] == ch) {
                char_index = j + 1;
                char_found = true;
                break;
            }
        }
        if (!char_found) {
            std::cout << "������: ������ '" << ch << "' �� ������ � ��������." << std::endl;
            return 0; // ���������� 0 � ������ ������
        }
        result += pow(n, k - i) * char_index;
        formula += std::to_string(n) + "^" + std::to_string(k - i) + " * " + std::to_string(char_index) + " + ";
    }

    formula = formula.substr(0, formula.size() - 3) + " = " + std::to_string(result);
    std::cout << formula << std::endl;  // ����������� - ����� � ���� �������

    return result;
}


int main() {
    setlocale(LC_ALL, "rus");
    std::string word;
   

    std::vector<char> alphabet;
    char ch;
    std::cout << "������� ������� (������ ����� � ����� ������), ��� ��������� ������� '.' : " << std::endl;
    while (std::cin >> ch && ch != '.') {
        alphabet.push_back(ch);
    }

    std::cout << "������� �����: " << std::endl;
    while (std::cin >> ch && ch != '.') {
        word += ch;
    }

    // �������� ������� ���� �������� ����� � ��������
    //for (char ch : word) {
    //    bool char_in_alphabet = false;
    //    for (char alpha_ch : alphabet) {
    //        if (alpha_ch == ch) {
    //            char_in_alphabet = true;
    //            break;
    //        }
    //    }
    //    if (!char_in_alphabet) {
    //        std::cerr << "������: ������ '" << ch << "' �� ������ � ��������." << std::endl;
    //        return 1; // ���������� 1 � ������ ������
    //    }
    //}

    int number = get_number(word, alphabet);
    std::cout << "Number: " << number << std::endl;
    return 0;
}
