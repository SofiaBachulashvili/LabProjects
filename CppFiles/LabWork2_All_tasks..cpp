// ������������ ������ 2
#include <iostream>
#include <cmath>
using namespace std;

/* ������� 1
� ���������� �������� ����� X, Y, Z. ���������� �������� �������, ������� �������� ��������, �����:
"	������ �� ����� X � Y ��������;
"	������ ���� �� ����� X � Y ������ 20;
"	���� �� ���� �� ����� X � Y ����� ����;
"	������ �� ����� X, Y, Z �������������;
"	������ ���� �� ����� X, Y � Z ������ ����;
"	���� �� ���� �� ����� X, Y, Z ������ 100.
� ������, ���� ������� ����������� ������� �� ����� - Condition is true, ����� Condition is false. */

void num1() {
	int x, y, z;
	cout<<"������� �������� x, y, z: ";
	cin >> x >> y >> z;
	
	cout<<"������ �� ����� X � Y ��������? ";
	if (x % 2 != 0 && y % 2 != 0){                                     //    && - "and"    || - "or"     
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	cout<<"������ ���� �� ����� X � Y ������ 20? ";
	if ((x >= 20 && y < 20)||(x < 20 && y >= 20)){             // (x > 20 and y < 20) or (x < 20 and y > 20)
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	cout<<"������ �� ����� X, Y, Z �������������? ";
	if ((x < 0) && (y < 0) && (z < 0)) {      
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	cout<<"������ ���� �� ����� X, Y � Z ������ ����? ";     //    && - "and"    || - "or"
	if ( ((x % 5 == 0) && (y % 5 != 0) && (z % 5 != 0)) || ((x % 5 != 0) && (y % 5 == 0) && (z % 5 != 0)) || ((x % 5 != 0) && (y % 5 != 0) && (z % 5 == 0)) ) {     
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	cout<<"���� �� ���� �� ����� X, Y, Z ������ 100? "; 
	if ( ((x > 100) && (y <= 100) && (z <= 100)) || ((x <= 100) && (y > 100) && (z <= 100)) || ((x <= 100) && (y <= 100) && (z > 100)) ) {
	cout<<"Condition is true."<<endl;
	}
	else{
	cout<<"Condition is false."<<endl;
	}
	
	return;
}
/*������� 2.
������ �� ��������� ����� ������������ ����� ����������� �����, ������ �� ������� �� ����������� 8: ������ ����� - ����� ��������� (��� ����� ����� �������),
 ������ - ����� ����������� (��� ����� ����� �����). 
 ��� ���� ������ ������������ ��� std::pair, ����� ���������� � ������� �������� ����, ����� ������� � ���������� ��������� .first, 
 ����� ���������� �� ������� �������� - .second.

���������������� ��� ������� � ���������� ������ � �������� �� � ����:

			using byte = unsigned char;
			std::pair<byte, byte> position;
			std::cin >> position.first >> position.second;

����������������, ��� ������ �������� ���� ��� ������������� � ������� �� �� �����.

			using byte = unsigned char;
			std::pair<byte, byte> position(0, 4);
                              std::cout << position.first << " " << position.second;

���� ��� ���������� ��������� ����� positionA(a, b) � positionB(c, d). ����� a, b, c, d �� ����������� 8. ���������:

"	�� ���� positionA(a, b) ����������� �����. �������� �������, ��� ������� ��� �������� ���� positionB(c, d).
"	�� ���� positionA(a, b) ���������� ����. �������� �������, ��� ������� �� �������� ���� positionB(c, d).
"	�� ���� positionA(a, b) ���������� ������. �������� �������, ��� ������� �� ����� ����� ����� ������� �� ���� positionB(c, d).
"	�� ���� positionA(a, b) ���������� �����. �������� �������, ��� ������� �� �������� ���� positionB(c, d).
"	�� ���� positionA(a, b) ����������� ����� �����. �������� �������, ��� ������� ��� ����� ����� ����� ������� �� ���� positionB(c, d):
        			��� ������� ����;
        			����� ��� "����" ������ ��� ����� ���������.
*/
void num2(){
	pair<int, int> positionA, positionB;
	
	cout << "������� ���������� positionA: ";
	cin>>positionA.first>>positionA.second; // don't need ">>endl;"
	
	cout << "������� ���������� positionB: ";
	cin >> positionB.first >> positionB.second; // don't need ">>endl;"
	
	if ((positionA.first > 0 && positionA.first < 9) && (positionA.second > 0 && positionA.second < 9) && 
	   (positionB.first > 0 && positionB.first < 9) && (positionB.second > 0 && positionB.second < 9) ){

		if (positionA.first == positionB.first || positionA.second == positionB.second){
			cout << "����� �������� ���� positionB." << endl;
		}
		
		if (abs(positionA.first-positionB.first) == abs(positionA.second-positionB.second)) { 
			cout << "���� �������� ���� positionB." << endl;
		}
		
		if (abs(positionA.first-positionB.first) <=1 && abs(positionA.second-positionB.second) <=1){
			cout << "������ ����� ������� �� ���� positionB." << endl;
			}
			
		if (positionA.first == positionB.first || positionA.second == positionB.second || 
		abs(positionA.first-positionB.first) == abs(positionA.second-positionB.second)) {
			cout << "����� �������� ���� positionB." << endl;
		}
		
		
		if ((positionA.first == positionB.first && positionB.second == positionA.second + 1) ) {
	        	cout << "����� ����� ����� ������� �� ���� positionB." << endl;
	        }
	        
	    else if (abs(positionB.first - positionA.first) == 1 && positionB.second - positionA.second == 1) {
		cout << "����� ����� ���� ���� positionB." << endl;	
		}
		
		else if((positionA.second == 2) && positionA.first == positionB.first && (positionB.second == positionA.second + 2)){
			cout<<"����� ����� ���� ����� 2 ����."<<endl;
		}
		else{
			cout<<"�� ����!"<<endl;
		}
	}
	
	else cout << "�� �������� ����������.";
    return;		
}

/* ������� 3
(� ������� ����� for)

���������� ������� ��������� �� N, ������� �������� � ����������:

					1 � N = 1*N
					2 � N = 2*N
					...
					9 � N = 9*N
*/
void num3(){
	
	for (int a = 1; a <= 9; ++a){
		cout << a << " x " << 7 << " = " << a * 7 << endl;
	}
	
	int N;
	do{
	cout << "������� ����� N �� 1 �� 9: ";
	cin >> N;
	
	if (N<=0 || N>9){
		cout << "����������� ����.";
	}
}while (N<=0 || N>9);

	cout << "������� �������� �� "<< N << " : "<< endl;
	
	for (int i = 1; i <= 9; ++i){
		cout << i << " x " << N << " = " << i * N << endl;
	}
	return;
}

/*������� 4

����� � ������� �� �����:

"	������������ ���� ����� ����� �� 8 �� 15;
"	������������ ���� ����� ����� �� a �� 20 (�������� a �������� � ����������; 1 < a < 20);
"	������������ ���� ����� ����� �� 1 �� b (�������� b �������� � ����������; 1 < b < 20);
"	������������ ���� ����� ����� �� a �� b (�������� a � b �������� � ����������; b >= a).
*/

void num4(){
	long long int N , a, b, i;
	N=1;
	for (int i = 8; i <=15; ++i){
		N*=i;
	}
	cout<<"������������ ���� ����� ����� �� 8 �� 15: "<< N <<endl;
	
	N = 1;
	do{
	cout << "������� ����� a: ";
	cin >> a ;
	
	if (a > 20 || a < 1 ){
		cout<<"������������ ����. ";
	}
} while(a > 20 || a < 1);
	cout<<"������������ ���� ����� ����� �� "<< a << " �� 20: ";
	for (int i = a; i <= 20; ++i){
	N*=i;}
	cout << N << endl;
	
	N = 1;
	do{
	cout << "������� ����� b: ";
	cin >> b;
	if (b > 20 || b < 1 || a > b ){
		cout<<"������������ ����.";
	}
}while(b > 20 || b < 1 || a > b);
	cout<<"������������ ���� ����� ����� �� 1 �� "<< b <<" : ";
	for (int i = 1; i <= b; ++i){
	N*=i;}
	cout << N << endl;
	
	N = 1;
	do{
	if (a > 20 || a < 1 || b > 20 || b < 1 || a > b);
	
}while(a > 20 || a < 1 || b > 20 || b < 1 || a > b);

	cout<<"������������ ���� ����� ����� �� "<< a << " �� " << b << " : ";
	for (int i = a; i <= b; ++i){
	N*=i;
	}
	cout << N << endl;
	
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
		default:
		cout <<"������, ��� ������� "<<task_N<<"���."<<endl;
		return 0;
	}
}
