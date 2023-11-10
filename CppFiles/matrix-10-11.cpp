#include <iostream>
#include <locale.h>
#include <cstddef> //size_t

using namespace std;


struct Matrix {

	int** data_ = nullptr; // двумерный массив с данными.

	size_t n_ = 0u; // количество строки

	size_t m_ = 0u; // количество строк
};

//Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out,  size_t n, size_t m){
	out.n_ = n;
	out.m_ = m;
	out.data_ = new int*[n];

	for (size_t i = 0; i < n; ++i) {
		out.data_[i] = new int [m];
	}
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			out.data_[i][j] = 0;
		}
	}
	return;
}

// Освобождает выделенную память.
void Destruct(Matrix& in){
	for (size_t i = 0; i < in.n_; ++i) {
		delete in.data_[i];
	}
	return;
}

// Создает копию матрицы | matrix | .
Matrix Copy(const Matrix& matrix) {
	Matrix matrix_copy;
	Construct(matrix_copy, matrix.n_, matrix.m_);
	for (size_t i = 0; i < matrix.n_; ++i) {
		for (size_t j = 0; j < matrix.m_; ++j) {
			matrix_copy.data_[i][j] = matrix.data_[i][j];
		}
	}
	return matrix_copy;
}

// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Add(const Matrix& a, const Matrix& b) {
	if ((a.n_ == b.n_) && (a.m_ == b.m_)) {
		Matrix matrix_sum;
		Construct(matrix_sum, a.n_, a.m_);
		for (size_t i = 0; i < a.n_; ++i) {
			for (size_t j = 0; j < a.m_; ++j) {
				matrix_sum.data_[i][j] = a.data_[i][j] + b.data_[i][j];
			}
		}
		return matrix_sum;
	}
	return Matrix();
}

// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Sub(const Matrix& a, const Matrix& b) {
	if ((a.n_ == b.n_) && (a.m_ == b.m_)) {
		Matrix matrix_sub;
		Construct(matrix_sub, a.n_, a.m_);
		for (size_t i = 0; i < a.n_; ++i) {
			for (size_t j = 0; j < a.m_; ++j) {
				matrix_sub.data_[i][j] = a.data_[i][j] - b.data_[i][j];
			}
		}
		return matrix_sub;
	}
	return Matrix();
}

// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Mult(const Matrix& a, const Matrix& b) {
	if (a.n_ == b.m_) { // a.n = b.m = k
		Matrix matrix_mult;
		Construct(matrix_mult, a.n_, b.m_);
		for (size_t i = 0; i < matrix_mult.n_; ++i) {
			for (size_t j = 0; j < matrix_mult.m_; ++j) {
				for (size_t k = 0; k < b.m_; ++k)
				matrix_mult.data_[i][j] += a.data_[i][k] * b.data_[k][j];
			}
		}
		return matrix_mult;
	}
	return Matrix();
}


// Транспонирование матрицы.
void Transposition(Matrix& matrix) {
	Matrix matrix_tr;
	for (size_t i = 0; i < matrix_tr.n_; ++i) {
		for (size_t j = 0; j < matrix.m_; ++j) {
			matrix_tr.data_[i][j] = matrix.data_[j][i];
		}
	}
	matrix.n_ = matrix_tr.n_;
	matrix.m_ = matrix_tr.m_;
	
	Destruct(matrix_tr);
	return;
}
/*
// Сравнение двух матриц.
bool operator==(const Matrix& a, const Matrix& b);
*/

int main() {
	setlocale(LC_ALL, "Russian");
	Matrix m1;
	Construct(m1, 4, 7);
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 7; ++j) {
			m1.data_[i][j] = rand();
		}
	}

	Matrix m2;
	Construct(m2, 4, 7);
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 7; ++j) {
			m2.data_[i][j] = rand();
		}
	}

	Matrix m3;
	Construct(m3, 4, 7);
	m3 = Copy(m1);
	cout << "matrix_copy m1" << "\n";
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 7; ++j) {
			cout << m3.data_[i][j] << "\t";
		} cout << "\n";
	}

	cout << "\n";
	m3 = Copy(m2);
	cout << "matrix_copy m2" << "\n";
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 7; ++j) {
			cout << m3.data_[i][j] << "\t";
		} cout << "\n";
	}
	
	m3 = Add(m1, m2);
	cout << "\n";
	cout << "matrix_sum" << "\n";
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 7; ++j) {
			cout << m3.data_[i][j] << "\t";
		} cout << "\n";
	}
	
	return 0;
}

