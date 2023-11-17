#include <iostream>
#include <sstream>
#include <locale.h>
#include <cmath>
#include <stack>
#include <string>

using namespace std;

const double Pie = acos(-1); // ����� ��
const double E = exp(1); //����� E

//��������� ��������� � �������� �������� ����� ������
string Unary_minus(string Line) {
    int a;
    string Zero = "0";
    string Bracket_minus = "(-";
    int s;
    s = Line.length() - 1;
    for (int i = 0; i < s; ++i) {
        a = i + 1;
        if (Line[i] == Bracket_minus[0] && Line[a] == Bracket_minus[1]) {
            Line.insert(a, Zero);
        }
    }
    return Line;
}

//��������� ���  �������� ������ ����� ��� ��������
struct Descripe_el
{
    char type; // "+", "-", "/", "*", "^" - ��� ��������, ��� ����� - 0
    double value; //�������� ������������ �����, ��� ���������� 0
};

bool Math(stack <Descripe_el>& Stack_of_numbers, stack <Descripe_el>& Stack_of_operators, Descripe_el& item) {
    double a, b, c;
    a = Stack_of_numbers.top().value; // a ������������� �������� �������� ����� �� ����� � �������
    Stack_of_numbers.pop(); //��������� ������� ����� �� ����� � �������
    switch (Stack_of_operators.top().type) {

    case '+':
        b = Stack_of_numbers.top().value;
        Stack_of_numbers.pop();
        c = a + b;
        item.type = '0';
        item.value = c;
        Stack_of_numbers.push(item); //��������� �������� �������� � ���� � �������
        Stack_of_operators.pop();
        break;

    case '-':
        b = Stack_of_numbers.top().value;
        Stack_of_numbers.pop();
        c = b - a;
        item.type = '0';
        item.value = c;
        Stack_of_numbers.push(item);
        Stack_of_operators.pop();
        break;

    case '^':
        b = Stack_of_numbers.top().value;
        Stack_of_numbers.pop();
        c = pow(b, a);
        item.type = '0';
        item.value = c;
        Stack_of_numbers.push(item);
        Stack_of_operators.pop();
        break;

    case '*':
        b = Stack_of_numbers.top().value;
        Stack_of_numbers.pop();
        c = a * b;
        item.type = '0';
        item.value = c;
        Stack_of_numbers.push(item);
        Stack_of_operators.pop();
        break;

    case '/':
        b = Stack_of_numbers.top().value;
        if (a == 0) {
            cerr << "������: ������� �� ����!" << "\n";
            return false;
        }
        else {
            Stack_of_numbers.pop();
            c = (b / a);
            item.type = '0';
            item.value = c;
            Stack_of_numbers.push(item);
            Stack_of_operators.pop();
            break;
        }

    default:
        cerr << "\n" << "������!!!" << "\n";
        return false;
        break;
    }
    return true;
}

int getRang(char el) { // ��������� ��������
    if (el == '+' || el == '-')return 1;
    if (el == '*' || el == '/')return 2;
    if (el == '^')return 3;
    else return 0;
}

int main()
{
    //system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    while (true) {
        system("cls");

        cout << "  ����������� : \n    ����� �� - 'p'\n    ����� E - 'e' \n    ����� 'p' � 'e' ����������� ������ ��������\n\n  ������� ������: ";

        string str;
        getline(cin, str);
        str = Unary_minus(str);
        stringstream expression{ str };

        char el; // ������� ������
        double value;
        bool minus = true; // ������� ����� � ������ ������
        stack <Descripe_el> Stack_of_numbers; //���� � �������
        stack <Descripe_el> Stack_of_operators; //���� � ����������
        Descripe_el item;
        while (true) {
            el = expression.peek();
            if (el == '\377')break; //������������ Escape ������������������  - ����� ������

            if (el == ' ') { //������������� ��������
                expression.ignore();
                continue;
            }

            if (el == 'p') { // ����� ��
                item.type = '0';
                item.value = Pie;
                Stack_of_numbers.push(item); //����� �������� � ���� � �������
                minus = 0;
                expression.ignore();
                continue;
            }

            if (el == 'e') { // ����� E
                item.type = '0';
                item.value = E;
                Stack_of_numbers.push(item);
                minus = 0;
                expression.ignore();
                continue;
            }

            if (el >= '0' && el <= '9' || el == '-' && minus == 1) { // ��������� �����
                expression >> value;
                item.type = '0';
                item.value = value;
                Stack_of_numbers.push(item);
                minus = 0;
                continue;
            }

            if (el == '+' || el == '-' && minus == 0 || el == '*' || el == '/' || el == '^') { // ��������� ��������
                if (Stack_of_operators.size() == 0) { // ���� ���� � ���������� ����
                    item.type = el;
                    item.value = 0;
                    Stack_of_operators.push(item); // �������� �������� � ���� � ����������
                    expression.ignore();
                    continue;
                }

                //���� ���� � ���������� �� ����, �� ��������� ������� �������� ���� ������� � ����� � ����������
                if (Stack_of_operators.size() != 0 && getRang(el) > getRang(Stack_of_operators.top().type)) {
                    item.type = el;
                    item.value = 0;
                    Stack_of_operators.push(item); // �������� �������� � ���� � ����������
                    expression.ignore();
                    continue;
                }

                // ���� ���� � ���������� �� ����, � ��������� ������� �������� ���� ��� ����� ������� � ����� � ����������
                if (Stack_of_operators.size() != 0 && getRang(el) <= getRang(Stack_of_operators.top().type)) {
                    if (Math(Stack_of_numbers, Stack_of_operators, item) == false) { // ���� ������� ������ "false", �� ���������� ������
                        system("pause");
                        return 0;
                    }
                    continue;
                }
            }
            if (el == '(') { // ������������� ������
                item.type = el;
                item.value = 0;
                Stack_of_operators.push(item); //�������� �������� � ���� � ����������
                expression.ignore();
                continue;
            }
            if (el == ')') { // ������������� ������
                while (Stack_of_operators.top().type != '(') {
                    if (Math(Stack_of_numbers, Stack_of_operators, item) == false) { //���� ������� ������ "false", �� ���������� ������
                        system("pause");
                        return 0;
                    }
                    else continue;
                }
                Stack_of_operators.pop();
                expression.ignore();
                continue;
            }
            else { //������ ����������� ������
                cout << "\n	������ ������ �����������!\n";
                system("pause");
                return 0;
            }
        }
        while (Stack_of_operators.size() != 0) {
            if (Math(Stack_of_numbers, Stack_of_operators, item) == false) {
                system("pause");
                return 0;
            }
            else continue;
        }
        std::cout << "  ���������: " << Stack_of_numbers.top().value << "\n";
        system("pause");
    }
    return 0;
}