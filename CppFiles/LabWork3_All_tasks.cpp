// ������������ ������ 2
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <algorithm>
//#include <>

#include <cstdlib>
#include <ctime>

using namespace std;

void num1(){
	int n;
	cout << "������� ����� �������: ";
	cin >> n;
	cout << endl;
	float *m = new float[n];
	srand(time(NULL));
	
	cout << "������ m = { ";
	
	for (int i = 0; i < n; i++)
	{
		m[i] = rand(); 
		cout << m[i]<< " ";
	}
	cout<< "}" << endl;
	
		cout << "������, �������� �������� �������� �� 2:  { ";
	for( int i = 0; i < 5; ++i){
		cout << m[i]*2<< " ";
	}
	cout<< "}" << endl;
	

	int a;
	cout << "������� ����� �: " ;
	cin >> a;
	cout << "������, �������� �������� ��������� �� ����� �: { ";
	for(int i = 0; i < 5; ++i){
		cout << m[i] - a << " ";
	}
	cout<< "}" << endl;
	
	cout<<"������, �������� ������� ��������� �� ������ ������� �������: {";
	if (m[0] != 0) {
		for(int i = 0; i < 5; ++i){
		cout << m[i] / m[0]<< " ";
		} 
	}
	else cout << "������ ������� ������� ����� 0, ����������� ��������� �� m[0]!!!" << endl; 
	cout<< "" << endl;
	delete[]m;
	return;
}

/* ������� 2.
����������:
	1) sum = ����� ���� ��������� �������;
	2) sumsq = ����� ��������� ���� ��������� �������;
	3) sum6 = ����� ����� ������ ��������� �������;
	4) sumk1k2 = ����� ��������� ������� � k1-�� �� k2�;
	5) sum/n = ������� �������������� ���� ��������� �������;
	6) sums1s2 / (s2-s1+1) = ������� �������������� ��������� ������� � s1-�� �� s2-�.*/
void num2()
{
	int n;
	cout << "������� ����� �������: ";
	cin >> n;
	cout << endl;
	float *m = new float[n];
	srand(time(NULL));
	
	cout << "������ m = { ";
	for (int i = 0; i < n; i++){
		m[i] = rand(); 
		cout << m[i]<< " ";
	}
	cout<< "}" << endl;
	//int n = 7;
	//long double m[] = {233, 29352, 22953, 3868, 4562, 14644, 48};
	
	float sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += m[i];
	}
	cout << "1) ����� ��������� �������: " << sum << endl;
	cout << endl;
	
	long long int sumsq = 0;
	for (int i = 0; i < n; ++i) {
		sumsq += pow(m[i], 2);
	}
	cout << "2) ����� ��������� ��������� �������: " << sumsq << endl;
	cout << endl;
	
	//int sum6 = 0;
	long double sum6 = 0;
	if (n >= 6) {
		for (int i = 0; i < 7; ++i) {
			sum6 += m[i];
		}
		cout << "3) ����� ������ 6 ��������� �������: " << sum6 << endl;
	}
	else {
		cout << "� ������� ������ 6 ���������!!! ���������� ���������� ����� ������ 6 ��������� �������!!!" << endl;
	}
	cout << endl;
	
	int k1, k2, sumk1k2 = 0;
	cout << "������� ����� k1: ";
	cin >> k1;
	//cout << endl;
	cout << "������� ����� k2: ";
	cin >> k2;
	//cout << endl;
	for (int i = k1 - 1; i < k2; ++i) {
		sumk1k2 += m[i];
	}
	cout << "4) ����� ��������� � k1-�� �� k2-� : " << sumk1k2 << endl;
	cout << endl;
	
	cout << "5) ������� �������������� ��������� �������: " << sum / n << endl;
	cout << endl;
	
	int s1, s2;
	float sums1s2 = 0;
	cout << "������� ����� s1: ";
	cin >> s1;
	//cout << endl;
	cout << "������� ����� s2: ";
	cin >> s2;

	for (int i = s1 - 1; i < s2; ++i) {
		sums1s2 += m[i];
	}
	cout << "6) ������� �������������� ��������� ������� � s1-�� �� s2-� ����� " << sums1s2 / (s2 - s1 + 1) << endl;
	
	delete[]m;
	return;
}

/* ��� ���������� ������ �� 20 ���������. 
����������� ������ ��� � ��������� ��� ��������, �������� ������� �� ����������. */
void num3() {
	int n = 20;
	vector <int> vector1(n);
	srand(time(NULL));
	
	cout << "������ m = "<<endl;
	cout << "{ ";
	
	for (int i = 0; i < n; i++)
	{
		vector1[i] = rand(); 
		cout << vector1[i]<< " ";
	}
	cout<< "}" << endl;
	cout<< endl;
	
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
	
	cout<< "������ � ��������������� ���������� :"<< endl;
	cout << "{";
	for (int i = 0; i < n; ++i) {
		cout << vector1[i] << " ";
	}
	cout<< "}"<< endl;
	return;
}

/*4.	������� �� �������:
	������ ������������� ������� (���� ������������� �������� � ������� ����);
	������� ��������� ������ ������� (���� ������ �������� � ������� ����). */
void num4() {
	int n;
	int k = 1;
	int u = 1;
	cout << "������� ����� �������: ";
	cin >> n;
	cout << endl;
	
	vector <int> vector1(n);
	vector <int> vector2(n);
	
	srand(time(NULL));
	
	cout << "������ m = "<<endl;
	cout << "{ ";
	for (int i = 0; i < n; i++){
		vector1[i] = rand(); 
		cout << vector1[i]<< " ";
	}
	cout<< "}" << endl;
	cout<< endl;
	
	for (int i = 0; i < n; ++i) {
		vector2[i] = vector1[n-1-i];
	}

	for (int i = 0; i < vector1.size(); ++i) {
		if (vector1[i] < 0) {
			vector1.erase(vector1.begin() + i);
			k *= 0;
			break;
		}
	}
	
	if (k == 0) {
		cout << "������ ��� 1-�� �������������� �����: "<<endl;
		cout << "{ ";
		for (int i = 0; i < vector1.size(); ++i) {
			cout << vector1[i] << " ";
		}
		cout<< "}" << endl;
	}
	else {
		cout << "� ������� ��� ������������� �����!!!" << endl;
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
		cout << "������ ��� ���������� ������� �����: ";

		for (int i = 0; i < vector1.size(); ++i) {
			cout << vector2[i] << " ";
		}
		cout << endl;
	}

	else {
		cout << "� ������� ��� ������ �����!!!" << endl;
	}

	return;
}

/*���� �������� ������. 
����������, ����� ��� ��� ���������� �������� � ���.*/
void num5() {
	string city;
	cout << "������� �������� ������: ";
	cin >> city;
	cout << endl;
	if (city.length() % 2 == 0) {
		cout << "���������� ���� � �������� ������ �����." << endl;
	}
	else {
		cout << "���������� ���� � �������� ������ �������." << endl;
	}
	return;
}

/*���� ��� �������. ������� true, ���� ������ ������.*/
void num6() {
	string surname1, surname2;
	cout << "������� ������� 1: ";
	cin >> surname1;
	cout << endl;
	cout << "������� ������� 2: ";
	cin >> surname2;
	cout << endl;
	int a = surname1.length();
	int b = surname2.length();
	if (a > b) {
		cout << "True" << endl;
	}
	return;
}

/*���� �������� ���� �������. �������� � the_longest ����� �������, 
� ����� �������� �������� � the_shortest*/
void num7(){
	string city1, city2, city3, the_longest, the_shortest;
	int k1, k2, k3;
	cout<<"������� �������� 3-x ������� ����� ������: ";
	cin>>city1>>city2>>city3;
	//cout<<city1<<" "<<city2<<" "<<city3;
	cout<<" "<<endl;
	k1 = city1.length();
	k2 = city2.length();
	k3 = city3.length();
	cout <<k1 <<" " << k2<< " "<<k3<< endl;
	if ((k1 != k2) && (k2 != k3 ) && (k1 != k3)){
		
		if (k1 > k2 && k1 > k3) {
			the_longest = city1;
			if (k2 > k3){
				the_shortest = city3;
			}
			else{
				the_shortest = city2;
			}
		the_longest = city1;
		}
		
		else if (k2 > k1 && k2 > k3 ) {
			the_longest = city2;
			if (k1 > k3){
				the_shortest = city3;
			}
			else{
				the_shortest = city1;
			}
		}
		
		else {
			the_longest = city3;
			if (k1 > k2){
				the_shortest = city2;
			}
			else{
				the_shortest = city1;
			}
		}
			
	cout<< "The longest :"<<the_longest<<endl;
	cout<< "The shortest :"<<the_shortest<<endl;
	}
	else cout << "�� ����� ������ ���������� ������!" << endl; 
	cout<< "" << endl;
	return;
}

/*���� �����. �������� � ���� � ������ � ����� ������� ���������, 
������� ���� � ���� �����.*/
void num8() {
	string word;
	cout << "������� �����: ";
	cin >> word;
	cout << endl;
	int stars = word.size();
	for (int i = 0; i < stars; ++i) {
		word = '*' + word + '*';
	}
	cout << "C���� �� �����������: " << word << endl;
	return;
}

/*���� �����������. ���������� ���� (� %) ���� 'a' � ���.*/
void num9()
{
	string s, a;
	a = "a";
	cout<<"������� ������: ";
	getline(cin, s);
	cout<<endl;
	int c, l;
	l = s.length();
	for (int i = 0; i < l; ++i){
		if (s[i]==a[0]){
			++c;
		}
	}

	cout<<"���-�� ���� �: "<< c <<endl;
	cout<<"����� ������: "<<l<<endl;
	cout <<"���� (� %) ���� 'a' � �����������: "<< (100*c)/l<< "%";
	return;
}

/*���� ����������� "Can you can a can as a canner can can a can?". 
�������� ��� ����� can �� ����� new_word.*/
void num10() {
	vector <string> vector1 = { "Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can", "?" };
	string new_word, New_word;
	cout << "������� ����� �����: ";
	cin >> new_word;
	cout << endl;
	New_word = new_word;
	cout<<"1New_word "<<New_word<<endl;
	for (int i = 0; i < New_word.length(); ++i) {
		New_word[0] = toupper(New_word[0]);
	}
	cout<<"2New_word "<<New_word<<endl;
	/*for (int i = 0; i < vector1.size(); ++i) {
		if (vector1[i] == "can" or vector1[i] == "Can") {
			vector1[i] = new_word;
		}
		cout << vector1[i] << " ";
	}*/
	vector1[0] == New_word;
	for (int i = 0; i < vector1.size(); ++i) {
		if (vector1[i] == "can" or vector1[i] == "Can") {
			if (vector1[i] == "can" ) {
				vector1[i] = new_word;
			}
		else{
			vector1[i] = New_word;
			}
		}
		cout << vector1[i] << " ";
	}
	cout << endl;
	return;
}

int main(){
	int task_N;
	cout<<"������� ����� ������: ";
	cin>>task_N;
	switch (task_N){
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
		cout <<"������, ��� ������� "<<task_N<<"���."<<endl;
		return 0;
	}
}
