#include "Matrix.h"

Matrix::Matrix() {   //конструктор за умовчанням(без параметрів)
	size = 1;

	line = new Row[size];   //створення масива рядків квадратної матриці
	for (int i = 0; i < size; i++)
		line[i] = Row(size);
}

//конструктор потрібен для створення рядків квадратної матриці
Matrix::Matrix(int kilkist_l_c) {   //конструктор ініціалізації класу "Matrix"
	size = (kilkist_l_c < 1) ? 1 : kilkist_l_c;    //перевірка значень(щоб користувач не ввів від'ємні значення)

	line = new Row[size];   //створення масива рядків квадратної матриці
	for (int i = 0; i < size; i++)
		line[i] = Row(size);
}

Matrix::Matrix(int values_s, Row* value_l) {  //конструктор копіювання
	size = values_s;
	line = value_l;
}

Matrix::~Matrix() {  //деструктор(звільнення памяті виділеної для об'єкта-матриці)
	for (int i = 0; i < size; i++)
		if (line[i].column != nullptr)
			delete[] line[i].column;    //звільнення пам'яті виділеної для стовпців квадратної матриці

	if (line != nullptr)
		delete[] line;    //звільнення пам'яті виділеної для рядків квадратної матриці
}

Matrix& Matrix::operator =(Matrix& value) {   //перевантаження операції "присвоєння"
	size = value.size;
	line = value.line;
	return *this;
}

Matrix::Row& Matrix::operator [](int line) {   //індексація рядка квадратної матриці
	return this->line[line];
}

Matrix::operator std::string() {   //приведення типу – перетворення у літерний рядок
	std::stringstream sout;
	sout << "\n\nPeretvorennya u liternyy ryadok: ";

	sout << "\nsize: " << size;
	sout << "\nMatrix: " << std::endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			sout << "   " << (*this)[i][j];
		sout << "\n";
	}

	return sout.str();
}

std::ostream& operator << (std::ostream& out, Matrix& value) {    //вивід на екран(перевантаженння операції "виводу")
	out << "\nDisplay of matrix elements of size: " << value.size << "x" << value.size << "\n";
	for (int i = 0; i < value.size; i++) {
		for (int j = 0; j < value.size; j++)
			out << "   " << value[i][j];
		out << "\n";
	}
	return out;
}

std::istream& operator >> (std::istream& in, Matrix& value) {    //введення з клавіатури(перевантаженння операції "вводу")
	std::cout << "\nEntering the values of the elements of the matrix" << "\n";
	for (int i = 0; i < value.size; i++) {
		for (int j = 0; j < value.size; j++) {
			std::cout << "object " << "[" << i << "]" << "[" << j << "] : ";
			in >> value[i][j];
		}
	}
	return in;
}

//конструктор потрібен для створення стовпців в кожному рядку і ініціалізація елементів стовпця
Matrix::Row::Row(int kilkist_column) {   //конструктор ініціалізації класу "Row"
	column = new int[kilkist_column];   //створення масива стовпців квадратної матриці

	for (int i = 0; i < kilkist_column; i++)
		column[i] = 0;
}

int& Matrix::Row::operator [](int column) {   //індексація стовпця квадратної матриці
	return this->column[column];
}