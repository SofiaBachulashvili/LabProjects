// Лабораторная работа 2
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>

#include <locale.h>

#include <cstdlib>
#include <ctime>

using namespace std;

void num1() {
	int n;
	cout << "Введите длину массива: ";
	cin >> n;
	cout << endl;
	float* m = new float[n];
	srand(time(NULL));

	cout << "Массив m = { ";

	for (int i = 0; i < n; i++)
	{
		m[i] = rand();
		cout << m[i] << " ";
	}
	cout << "}" << endl;

	cout << "Массив, элементы которого умножены на 2:  { ";
	for (int i = 0; i < 5; ++i) {
		cout << m[i] * 2 << " ";
	}
	cout << "}" << endl;


	int a;
	cout << "Введите число а: ";
	cin >> a;
	cout << "Массив, элементы которого уменьшены на число а: { ";
	for (int i = 0; i < 5; ++i) {
		cout << m[i] - a << " ";
	}
	cout << "}" << endl;

	cout << "Массив, элементы которго разделены на первый элемент массива: {";
	if (m[0] != 0) {
		for (int i = 0; i < 5; ++i) {
			cout << m[i] / m[0] << " ";
		}
	}
	else cout << "Первый элемент массива равен 0, невозмонжно разделить на m[0]!!!" << endl;
	cout << "" << endl;
	delete[]m;
	return;
}

/* Задание 2.
Определить:
	1) sum = сумму всех элементов массива;
	2) sumsq = сумму квадратов всех элементов массива;
	3) sum6 = сумму шести первых элементов массива;
	4) sumk1k2 = сумму элементов массива с k1-го по k2й;
	5) sum/n = среднее арифметическое всех элементов массива;
	6) sums1s2 / (s2-s1+1) = среднее арифметическое элементов массива с s1-го по s2-й.*/
void num2()
{
	int n;
	cout << "Введите длину массива: ";
	cin >> n;
	cout << endl;
	float* m = new float[n];
	srand(time(NULL));

	cout << "Массив m = { ";
	for (int i = 0; i < n; i++) {
		m[i] = rand();
		cout << m[i] << " ";
	}
	cout << "}" << endl;
	//int n = 7;
	//long double m[] = {233, 29352, 22953, 3868, 4562, 14644, 48};

	float sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += m[i];
	}
	cout << "1) Сумма элементов массива: " << sum << endl;
	cout << endl;

	long long int sumsq = 0;
	for (int i = 0; i < n; ++i) {
		sumsq += pow(m[i], 2);
	}
	cout << "2) Сумма квадратов элементов массива: " << sumsq << endl;
	cout << endl;

	//int sum6 = 0;
	long double sum6 = 0;
	if (n >= 6) {
		for (int i = 0; i < 7; ++i) {
			sum6 += m[i];
		}
		cout << "3) Сумма первых 6 элементов массива: " << sum6 << endl;
	}
	else {
		cout << "В массиве меньше 6 элементов!!! Невозможно определить сумму первых 6 элементов массива!!!" << endl;
	}
	cout << endl;

	int k1, k2, sumk1k2 = 0;
	cout << "Введите число k1: ";
	cin >> k1;
	//cout << endl;
	cout << "Введите число k2: ";
	cin >> k2;
	//cout << endl;
	for (int i = k1 - 1; i < k2; ++i) {
		sumk1k2 += m[i];
	}
	cout << "4) Сумма элементов с k1-го по k2-й : " << sumk1k2 << endl;
	cout << endl;

	cout << "5) Среднее арифметическое элементов массива: " << sum / n << endl;
	cout << endl;

	int s1, s2;
	float sums1s2 = 0;
	cout << "Введите число s1: ";
	cin >> s1;
	//cout << endl;
	cout << "Введите число s2: ";
	cin >> s2;

	for (int i = s1 - 1; i < s2; ++i) {
		sums1s2 += m[i];
	}
	cout << "6) Среднее арифметическое элементов массива с s1-го по s2-й равно " << sums1s2 / (s2 - s1 + 1) << endl;

	delete[]m;
	return;
}

/* Дан одномерный массив из 20 элементов.
Переставить первые три и последние три элемента, сохранив порядок их следования. */
void num3() {
	int n = 20;
	vector <int> vector1(n);
	srand(time(NULL));

	cout << "Массив m = " << endl;
	cout << "{ ";

	for (int i = 0; i < n; i++)
	{
		vector1[i] = rand();
		cout << vector1[i] << " ";
	}
	cout << "}" << endl;
	cout << endl;

	/*for (int i = 0; i < n; ++i) {
		vector1[i] = rand();
		cout << vector1[i] << " ";
	}
	cout << endl;*/
	int a1, b1, c1, a2, b2, c2;
	a1 = vector1[0];
	b1 = vector1[1];
	c1 = vector1[2];
	a2 = vector1[17];
	b2 = vector1[18];
	c2 = vector1[19];
	vector1.erase(vector1.begin());
	vector1.erase(vector1.begin());
	vector1.erase(vector1.begin());
	vector1.insert(vector1.begin(), c2);
	vector1.insert(vector1.begin(), b2);
	vector1.insert(vector1.begin(), a2);
	vector1.pop_back();
	vector1.pop_back();
	vector1.pop_back();
	vector1.insert(vector1.end(), a1);
	vector1.insert(vector1.end(), b1);
	vector1.insert(vector1.end(), c1);

	cout << "Массив с переставленными элементами :" << endl;
	cout << "{";
	for (int i = 0; i < n; ++i) {
		cout << vector1[i] << " ";
	}
	cout << "}" << endl;
	return;
}

/*4.	Удалить из массива:
	первый отрицательный элемент (если отрицательные элементы в массиве есть);
	удалить последний четный элемент (если четные элементы в массиве есть). */
void num4() {
	int n;
	int k = 1;
	int u = 1;
	cout << "Введите длину массива: ";
	cin >> n;
	cout << endl;

	vector <int> vector1(n);
	vector <int> vector2(n);

	srand(time(NULL));

	cout << "Массив m = " << endl;
	cout << "{ ";
	for (int i = 0; i < n; i++) {
		vector1[i] = rand();
		cout << vector1[i] << " ";
	}
	cout << "}" << endl;
	cout << endl;

	for (int i = 0; i < n; ++i) {
		vector2[i] = vector1[n - 1 - i];
	}

	for (int i = 0; i < vector1.size(); ++i) {
		if (vector1[i] < 0) {
			vector1.erase(vector1.begin() + i);
			k *= 0;
			break;
		}
	}

	if (k == 0) {
		cout << "Массив без 1-го отрицательного числа: " << endl;
		cout << "{ ";
		for (int i = 0; i < vector1.size(); ++i) {
			cout << vector1[i] << " ";
		}
		cout << "}" << endl;
	}
	else {
		cout << "В массиве нет отрицательных чисел!!!" << endl;
	}


	for (int i = 0; vector1.size(); ++i) {
		if (vector2[i] % 2 == 0) {
			vector2.erase(vector2.begin() + i);
			u *= 0;
			break;
		}
	}

	//reverse(vector2.begin(), vector2.end());

	if (u == 0) {
		cout << "Массив без последнего чётного числа: ";

		for (int i = 0; i < vector1.size(); ++i) {
			cout << vector2[i] << " ";
		}
		cout << endl;
	}

	else {
		cout << "В массиве нет чётных чисел!!!" << endl;
	}

	return;
}

/*Дано название города.
Определить, четно или нет количество символов в нем.*/
void num5() {
	string city;
	cout << "Введите название города: ";
	cin >> city;
	cout << endl;
	if (city.length() % 2 == 0) {
		cout << "Количество букв в названии города чётно." << endl;
	}
	else {
		cout << "Количество букв в названии города нечётно." << endl;
	}
	return;
}

/*Даны две фамилии. Верните true, если первая длинее.*/
void num6() {
	string surname1, surname2;
	cout << "Введите фамилию 1: ";
	cin >> surname1;
	cout << endl;
	cout << "Введите фамилию 2: ";
	cin >> surname2;
	cout << endl;
	int a = surname1.length();
	int b = surname2.length();
	if (a > b) {
		cout << "True" << endl;
	}
	return;
}

/*Даны названия трех городов. Запишите в the_longest самое длинное,
а самое короткое название в the_shortest*/
void num7() {
	string city1, city2, city3, the_longest, the_shortest;
	int k1, k2, k3;
	cout << "Введите название 3-x городов через пробел: ";
	cin >> city1 >> city2 >> city3;
	//cout<<city1<<" "<<city2<<" "<<city3;
	cout << " " << endl;
	k1 = city1.length();
	k2 = city2.length();
	k3 = city3.length();
	cout << k1 << " " << k2 << " " << k3 << endl;
	if ((k1 != k2) && (k2 != k3) && (k1 != k3)) {

		if (k1 > k2 && k1 > k3) {
			the_longest = city1;
			if (k2 > k3) {
				the_shortest = city3;
			}
			else {
				the_shortest = city2;
			}
			the_longest = city1;
		}

		else if (k2 > k1 && k2 > k3) {
			the_longest = city2;
			if (k1 > k3) {
				the_shortest = city3;
			}
			else {
				the_shortest = city1;
			}
		}

		else {
			the_longest = city3;
			if (k1 > k2) {
				the_shortest = city2;
			}
			else {
				the_shortest = city1;
			}
		}

		cout << "The longest :" << the_longest << endl;
		cout << "The shortest :" << the_shortest << endl;
	}
	else cout << "Вы ввели города одинаковой длинны!" << endl;
	cout << "" << endl;
	return;
}

/*Дано слово. Добавить к нему в начале и конце столько звездочек,
сколько букв в этом слове.*/
void num8() {
	string word;
	cout << "Введите слово: ";
	cin >> word;
	cout << endl;
	int stars = word.size();
	for (int i = 0; i < stars; ++i) {
		word = '*' + word + '*';
	}
	cout << "Cлово со звездочками: " << word << endl;
	return;
}

/*Дано предложение. Определить долю (в %) букв 'a' в нем.*/
void num9()
{
	string s, a;
	a = "a";
	cout << "Введите строку: ";
	getline(cin, s);
	cout << endl;
	int c = 0;
	int l = 0;
	l = s.length();
	for (int i = 0; i < l; ++i) {
		if (s[i] == a[0]) {
		c += 1;
		}
	}

	cout << "Кол-во букв а: " << c << endl;
	cout << "Длина строки: " << l << endl;
	cout << "Доля (в %) букв 'a' в предложении: " << (100 * c) / l << "%";
	return;
}

/*Дано предложение "Can you can a can as a canner can can a can?".
Заменить все слова can на слово new_word.*/
void num10() {
	vector <string> vector1 = { "Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can", "?" };
	string new_word, New_word;
	cout << "Введите новое слово: ";
	cin >> new_word;
	cout << endl;
	New_word = new_word;
	cout << "1New_word " << New_word << endl;
	for (int i = 0; i < New_word.length(); ++i) {
		New_word[0] = toupper(New_word[0]);
	}
	cout << "2New_word " << New_word << endl;
	/*for (int i = 0; i < vector1.size(); ++i) {
		if (vector1[i] == "can" or vector1[i] == "Can") {
			vector1[i] = new_word;
		}
		cout << vector1[i] << " ";
	}*/
	vector1[0] = New_word;
	for (int i = 0; i < vector1.size(); ++i) {
		if (vector1[i] == "can" or vector1[i] == "Can") {
			if (vector1[i] == "can") {
				vector1[i] = new_word;
			}
			else {
				vector1[i] = New_word;
			}
		}
		cout << vector1[i] << " ";
	}
	cout << endl;
	return;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int task_N;
	cout << "Введите номер задачи: ";
	cin >> task_N;
	switch (task_N) {
	case 1: num1(); return 0;
	case 2: num2(); return 0;
	case 3: num3(); return 0;
	case 4: num4(); return 0;
	case 5: num5(); return 0;
	case 6: num6(); return 0;
	case 7: num7(); return 0;
	case 8: num8(); return 0;
	case 9: num9(); return 0;
	case 10: num10(); return 0;
	default:
		cout << "Задачи, под номером " << task_N << "нет." << endl;
		return 0;
	}
}
