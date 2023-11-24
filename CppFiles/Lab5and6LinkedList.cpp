#include <vector>
#include <iostream>
#include <locale.h>
using namespace std;

struct Node { //Структура, описывающая список
	int data;
	Node* next; //Указатель на адрес следующего элемента списка
};

class LinkedList {
	public:
		LinkedList();
		LinkedList(int data);
		~LinkedList(); //деструктор списка

		bool add_element(int data);
		bool find_element(int data);
		bool insert_element(int data, int position);
		bool delete_element(int value);
		void Write_list();//Функция вывода списка в консоль


	private: //Указатели на адреса начала списка и его конца
		Node* first;
		Node* last;
};

LinkedList::LinkedList() {
	first = nullptr;
	last = nullptr;
};

LinkedList::LinkedList(int data) {
	Node* nd = new Node{ data }; //Выделение памяти под новый элемент структуры
	first = nd;
	last = nd;
	last->next = nullptr;
};

bool LinkedList::add_element(int data) {
	Node* nd = new Node{ data, nullptr }; 
	if (last == nullptr) {
		first = nd;
		last = nd;
		return true;
	}
	else {
		last->next = nd;
		last = nd;
	}
	return true;
};


bool LinkedList::find_element(int data) {
	if (last != nullptr) {
		Node* current_el = first;
		while (current_el != nullptr){
			if (current_el->data == data) return true;
			current_el = current_el->next;
		}
	} 
	return false;
};

bool LinkedList::insert_element(int data, int position) {
	if (last != nullptr) {
		Node* current_el = first;
		size_t i = 0;
		while (current_el != nullptr) {
			if (i == position - 1) {
				Node* nd = new Node{ data, current_el->next }; // связь между data и current_el->next
				current_el->next = nd;
				return true;
			}
		current_el = current_el->next;
		i += 1;
		}
	}
	return false;
};

void LinkedList::Write_list() {
	Node* current_el = first;
	cout << "\tLIST\t";
	while (current_el != NULL) {
		cout << current_el->data << " ";
		current_el = current_el->next;
	}
	cout << "\n\n";
	return;
}

bool LinkedList::delete_element(int position) {
	if (position == 0) {
		Node* el = first->next;
		delete first;
		first = el;
		return true;
	}
	else {
		Node* el = nullptr;
		size_t i = 0;
		Node* current_el = first;
		while (i != position-1) {
			++i;
			current_el = current_el->next;
		}
		el = (current_el->next)->next;
		delete current_el->next;
		current_el->next = el;
		return true;
	}
	return false;
}

LinkedList::~LinkedList() {
	if (last != nullptr) {
		Node* current_el = first;
		while (current_el != nullptr) {
			Node* nd = new Node{ 0, current_el->next };
			delete current_el;
			first = first->next; //Смена адреса начала на адрес следующего элемента 
			current_el = first;
		}
	}
}



int main() {
	setlocale(LC_ALL, "rus");
	LinkedList LIST;
	LIST.add_element(18);
	LIST.add_element(30);
	LIST.add_element(343);
	LIST.add_element(2);
	LIST.add_element(1);
	cout << "Initial";
	LIST.Write_list();

	cout << " LIST.find_element(1) : " << LIST.find_element(1) << "\n\n";

	cout << " LIST.insert_list(22, 3) : " << LIST.insert_element(22, 3) << "\n";
	LIST.Write_list();

	cout << " delete element position = 0 : " << LIST.delete_element(0) << "\n";
	LIST.Write_list();

	cout<<" delete element position = 3 : " <<LIST.delete_element(3)<< "\n";
	LIST.Write_list();
	
	LIST.~LinkedList();
	return 0;
}
