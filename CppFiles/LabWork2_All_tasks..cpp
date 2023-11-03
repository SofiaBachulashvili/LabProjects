// Лабораторная работа 2
#include <iostream>
#include <cmath>
using namespace std;

/* Задание 1
С клавиатуры вводятся числа X, Y, Z. Необходимо записать условие, которое является истинным, когда:
"	Каждое из чисел X и Y нечетное;
"	Только одно из чисел X и Y меньше 20;
"	Хотя бы одно из чисел X и Y равно нулю;
"	Каждое из чисел X, Y, Z отрицательное;
"	Только одно из чисел X, Y и Z кратно пяти;
"	Хотя бы одно из чисел X, Y, Z больше 100.
В случае, если условие выполняется вывести на экран - Condition is true, иначе Condition is false. */

void num1() {
	int x, y, z;
	cout<<"Введите значение x, y, z: ";
	cin >> x >> y >> z;
	
	cout<<"Каждое из чисел X и Y нечетное? ";
	if (x % 2 != 0 && y % 2 != 0){                                     //    && - "and"    || - "or"     
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	cout<<"Только одно из чисел X и Y меньше 20? ";
	if ((x >= 20 && y < 20)||(x < 20 && y >= 20)){             // (x > 20 and y < 20) or (x < 20 and y > 20)
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	cout<<"Каждое из чисел X, Y, Z отрицательное? ";
	if ((x < 0) && (y < 0) && (z < 0)) {      
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	cout<<"Только одно из чисел X, Y и Z кратно пяти? ";     //    && - "and"    || - "or"
	if ( ((x % 5 == 0) && (y % 5 != 0) && (z % 5 != 0)) || ((x % 5 != 0) && (y % 5 == 0) && (z % 5 != 0)) || ((x % 5 != 0) && (y % 5 != 0) && (z % 5 == 0)) ) {     
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	cout<<"Хотя бы одно из чисел X, Y, Z больше 100? "; 
	if ( ((x > 100) && (y <= 100) && (z <= 100)) || ((x <= 100) && (y > 100) && (z <= 100)) || ((x <= 100) && (y <= 100) && (z > 100)) ) {
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	return;
}
/*Задание 2.
Клетка на шахматной доски определяется парой натуральных чисел, каждое из которых не превосходит 8: первое число - номер вертикали (при счете слева направо),
 второе - номер горизонтали (при счете снизу вверх). 
 Для пары удобно использовать тип std::pair, чтобы обратиться к первому элементу пары, нужно указать к переменной приписать .first, 
 чтобы обратиться ко второму элементу - .second.

Продемонстрируем как считать с клавиатуры данные и записать их в пару:

			using byte = unsigned char;
			std::pair<byte, byte> position;
			std::cin >> position.first >> position.second;

Продемонстрируем, как задать значения пары при инициализации и выведем их на экран.

			using byte = unsigned char;
			std::pair<byte, byte> position(0, 4);
                              std::cout << position.first << " " << position.second;

Даны две координаты шахматных фигур positionA(a, b) и positionB(c, d). Числа a, b, c, d не превосходят 8. Требуется:

"	На поле positionA(a, b) расположена ладья. Записать условие, при котором она угрожает полю positionB(c, d).
"	На поле positionA(a, b) расположен слон. Записать условие, при котором он угрожает полю positionB(c, d).
"	На поле positionA(a, b) расположен король. Записать условие, при котором он может одним ходом попасть на поле positionB(c, d).
"	На поле positionA(a, b) расположен ферзь. Записать условие, при котором он угрожает полю positionB(c, d).
"	На поле positionA(a, b) расположена белая пешка. Записать условие, при котором она может одним ходом попасть на поле positionB(c, d):
        			при обычном ходе;
        			когда она "бьет" фигуру или пешку соперника.
*/
void num2(){
	pair<int, int> positionA, positionB;
	
	cout << "Введите координаты positionA: ";
	cin>>positionA.first>>positionA.second; // don't need ">>endl;"
	
	cout << "Введите координаты positionB: ";
	cin >> positionB.first >> positionB.second; // don't need ">>endl;"
	
	if ((positionA.first > 0 && positionA.first < 9) && (positionA.second > 0 && positionA.second < 9) && 
	   (positionB.first > 0 && positionB.first < 9) && (positionB.second > 0 && positionB.second < 9) ){

		if (positionA.first == positionB.first || positionA.second == positionB.second){
			cout << "Ладья угрожает полю positionB." << endl;
		}
		
		if (abs(positionA.first-positionB.first) == abs(positionA.second-positionB.second)) { 
			cout << "Слон угрожает полю positionB." << endl;
		}
		
		if (abs(positionA.first-positionB.first) <=1 && abs(positionA.second-positionB.second) <=1){
			cout << "Король может попасть на поле positionB." << endl;
			}
			
		if (positionA.first == positionB.first || positionA.second == positionB.second || 
		abs(positionA.first-positionB.first) == abs(positionA.second-positionB.second)) {
			cout << "Ферзь угрожает полю positionB." << endl;
		}
		
		
		if ((positionA.first == positionB.first && positionB.second == positionA.second + 1) ) {
	        	cout << "Белая пешка может попасть на поле positionB." << endl;
	        }
	        
	    else if (abs(positionB.first - positionA.first) == 1 && positionB.second - positionA.second == 1) {
		cout << "Белая пешка бьет поле positionB." << endl;	
		}
		
		else if((positionA.second == 2) && positionA.first == positionB.first && (positionB.second == positionA.second + 2)){
			cout<<"Белая пешка идет через 2 поля."<<endl;
		}
		else{
			cout<<"Не идет!"<<endl;
		}
	}
	
	else cout << "Не подходят координаты.";
    return;		
}

/* Задание 3
(с помощью цикла for)

Напечатать таблицу умножения на N, которое вводится с клавиатуры:

					1 х N = 1*N
					2 х N = 2*N
					...
					9 х N = 9*N
*/
void num3(){
	
	for (int a = 1; a <= 9; ++a){
		cout << a << " x " << 7 << " = " << a * 7 << endl;
	}
	
	int N;
	do{
	cout << "Введите число N от 1 до 9: ";
	cin >> N;
	
	if (N<=0 || N>9){
		cout << "Некоррекный ввод.";
	}
}while (N<=0 || N>9);

	cout << "Таблица умножени на "<< N << " : "<< endl;
	
	for (int i = 1; i <= 9; ++i){
		cout << i << " x " << N << " = " << i * N << endl;
	}
	return;
}

/*Задание 4

Найти и вывести на экран:

"	произведение всех целых чисел от 8 до 15;
"	произведение всех целых чисел от a до 20 (значение a вводится с клавиатуры; 1 < a < 20);
"	произведение всех целых чисел от 1 до b (значение b вводится с клавиатуры; 1 < b < 20);
"	произведение всех целых чисел от a до b (значения a и b вводятся с клавиатуры; b >= a).
*/

void num4(){
	long long int N , a, b, i;
	N=1;
	for (int i = 8; i <=15; ++i){
		N*=i;
	}
	cout<<"Произведение всех целых чисел от 8 до 15: "<< N <<endl;
	
	N = 1;
	do{
	cout << "Введите число a: ";
	cin >> a ;
	
	if (a > 20 || a < 1 ){
		cout<<"Некорректный ввод. ";
	}
} while(a > 20 || a < 1);
	cout<<"Произведение всех целых чисел от "<< a << " до 20: ";
	for (int i = a; i <= 20; ++i){
	N*=i;}
	cout << N << endl;
	
	N = 1;
	do{
	cout << "Введите число b: ";
	cin >> b;
	if (b > 20 || b < 1 || a > b ){
		cout<<"Некорректный ввод.";
	}
}while(b > 20 || b < 1 || a > b);
	cout<<"Произведение всех целых чисел от 1 до "<< b <<" : ";
	for (int i = 1; i <= b; ++i){
	N*=i;}
	cout << N << endl;
	
	N = 1;
	do{
	if (a > 20 || a < 1 || b > 20 || b < 1 || a > b);
	
}while(a > 20 || a < 1 || b > 20 || b < 1 || a > b);

	cout<<"Произведение всех целых чисел от "<< a << " до " << b << " : ";
	for (int i = a; i <= b; ++i){
	N*=i;
	}
	cout << N << endl;
	
	return;
}

int main(){
	int task_N;
	cout<<"Введите номер задачи: ";
	cin>>task_N;
	switch (task_N){
		case 1: num1(); return 0;
		case 2: num2(); return 0;
		case 3: num3(); return 0;
		case 4: num4(); return 0;
		default:
		cout <<"Задачи, под номером "<<task_N<<"нет."<<endl;
		return 0;
	}
}
