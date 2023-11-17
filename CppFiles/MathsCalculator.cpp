#include <iostream>
#include <sstream>
#include <locale.h>
#include <cmath>
#include <stack>
#include <string>

using namespace std;

const double Pie = acos(-1); // число Пи
const double E = exp(1); //число E

//Обработка выражений с унарными минусами после скобок
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

//Структура для  описания любого числа или операции
struct Descripe_el
{
    char type; // "+", "-", "/", "*", "^" - для операций, для чисел - 0
    double value; //Значение соответстует числу, для операторов 0
};

bool Math(stack <Descripe_el>& Stack_of_numbers, stack <Descripe_el>& Stack_of_operators, Descripe_el& item) {
    double a, b, c;
    a = Stack_of_numbers.top().value; // a присваивается значение верхнего числа из стека с числами
    Stack_of_numbers.pop(); //Удаляется верхнее число из стека с числами
    switch (Stack_of_operators.top().type) {

    case '+':
        b = Stack_of_numbers.top().value;
        Stack_of_numbers.pop();
        c = a + b;
        item.type = '0';
        item.value = c;
        Stack_of_numbers.push(item); //Результат операции кладется в стек с числами
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
            cerr << "Ошибка: деление на ноль!" << "\n";
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
        cerr << "\n" << "ОШИБКА!!!" << "\n";
        return false;
        break;
    }
    return true;
}

int getRang(char el) { // Приоритет операции
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

        cout << "  ОБОЗНАЧЕНИЯ : \n    число Пи - 'p'\n    число E - 'e' \n    перед 'p' и 'e' обязательно писать операцию\n\n  Введите пример: ";

        string str;
        getline(cin, str);
        str = Unary_minus(str);
        stringstream expression{ str };

        char el; // текущий символ
        double value;
        bool minus = true; // унарный минус в начале строки
        stack <Descripe_el> Stack_of_numbers; //Стек с числами
        stack <Descripe_el> Stack_of_operators; //Стек с операциями
        Descripe_el item;
        while (true) {
            el = expression.peek();
            if (el == '\377')break; //Восьмеричная Escape последовательность  - конец строки

            if (el == ' ') { //Игнорирование пробелов
                expression.ignore();
                continue;
            }

            if (el == 'p') { // число Пи
                item.type = '0';
                item.value = Pie;
                Stack_of_numbers.push(item); //Число кладется в стек с числами
                minus = 0;
                expression.ignore();
                continue;
            }

            if (el == 'e') { // число E
                item.type = '0';
                item.value = E;
                Stack_of_numbers.push(item);
                minus = 0;
                expression.ignore();
                continue;
            }

            if (el >= '0' && el <= '9' || el == '-' && minus == 1) { // Прочитано число
                expression >> value;
                item.type = '0';
                item.value = value;
                Stack_of_numbers.push(item);
                minus = 0;
                continue;
            }

            if (el == '+' || el == '-' && minus == 0 || el == '*' || el == '/' || el == '^') { // Прочитана операция
                if (Stack_of_operators.size() == 0) { // Если стек с операциями пуст
                    item.type = el;
                    item.value = 0;
                    Stack_of_operators.push(item); // Операция кладется в стек с операциями
                    expression.ignore();
                    continue;
                }

                //Если стек с операциями НЕ пуст, но приоритет текущей операции выше верхней в стеке с операциями
                if (Stack_of_operators.size() != 0 && getRang(el) > getRang(Stack_of_operators.top().type)) {
                    item.type = el;
                    item.value = 0;
                    Stack_of_operators.push(item); // Операция кладется в стек с операциями
                    expression.ignore();
                    continue;
                }

                // Если стек с операциями НЕ пуст, и приоритет текущей операции ниже или равен верхней в стеке с операциями
                if (Stack_of_operators.size() != 0 && getRang(el) <= getRang(Stack_of_operators.top().type)) {
                    if (Math(Stack_of_numbers, Stack_of_operators, item) == false) { // Если функция вернет "false", то прекращаем работу
                        system("pause");
                        return 0;
                    }
                    continue;
                }
            }
            if (el == '(') { // открывающаяся скобка
                item.type = el;
                item.value = 0;
                Stack_of_operators.push(item); //Операция кладется в стек с операциями
                expression.ignore();
                continue;
            }
            if (el == ')') { // закрывающаяся скобка
                while (Stack_of_operators.top().type != '(') {
                    if (Math(Stack_of_numbers, Stack_of_operators, item) == false) { //Если функция вернет "false", то прекращаем работу
                        system("pause");
                        return 0;
                    }
                    else continue;
                }
                Stack_of_operators.pop();
                expression.ignore();
                continue;
            }
            else { //введен посторонний символ
                cout << "\n	Пример введен некорректно!\n";
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
        std::cout << "  Результат: " << Stack_of_numbers.top().value << "\n";
        system("pause");
    }
    return 0;
}