#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Matrix {      //клас "Matrix"(Матриця) для представлення матриці(двовимірного масиву) із NxN цілих чисел.
	class Row;  //оголошення класу "Row"

	int size;   //розмір квадратної матриці
	Row* line;  //вказівник "line" вказує на масив(певна кількість рядків матриці)

	class Row {    //клас "Row"(Рядок) для ініціалізацію елементів матриці
	public:
		int* column;   //вказівник "column" вказує на масив(певна кількість стовпців матриці)

		void Set_column(int* value) { column = value; }  //Встановлення значення поля "column"
		int* Get_column() const { return column; }       //Отримання значення поля "column"

		Row(int kilkist_column = 1);  //конструктор ініціалізації класу "Row"
		int& operator [](int);        //індексація стовпця квадратної матриці
	};
public:
	Matrix();            //конструктор за умовчанням(без параметрів)
	Matrix(int);         //конструктор ініціалізації класу "Matrix"
	Matrix(int, Row*);   //конструктор копіювання
	~Matrix();   //деструктор(звільнення памяті виділеної для об'єкта-матриці)

	void Set_size(int value) { size = value; }	  //Встановлення значення поля "size"
	void Set_line(Row* value) { line = value; }   //Встановлення значення поля "line"

	int Get_size() const { return size; }         //Отримання значення поля "size"
	Row* Get_line() const { return line; }        //Отримання значення поля "line"

	Row& operator [](int line);      //індексація рядка квадратної матриці
	Matrix& operator =(Matrix&);     //перевантаження операції "присвоєння"
	operator std::string();          //приведення типу – перетворення у літерний рядок

	friend std::ostream& operator << (std::ostream&, Matrix&);   //вивід на екран(перевантаженння операції "виводу")
	friend std::istream& operator >> (std::istream&, Matrix&);	//введення з клавіатури(перевантаженння операції "вводу")

	friend void operator -(Matrix&, Matrix&);    //віднімання матриць і отримання нової
	double Calculation_Norm_Matrices();             //обчислення норми матриці (корінь із суми квадратів елементів)

	//Операції порівняння
	friend bool operator < (Matrix&, Matrix&);    //перевантаження операції "менше" (1 спосіб)
	friend bool operator > (Matrix&, Matrix&);    //перевантаження операції "більше" (1 спосіб)

	friend bool operator <= (Matrix&, Matrix&);    //перевантаження операції "менше рівне" (2 спосіб)
	friend bool operator >= (Matrix&, Matrix&);    //перевантаження операції "більше рівне" (2 спосіб)

	friend bool operator == (Matrix&, Matrix&);    //перевантаження операції "рівне" (3 спосіб)
	friend bool operator != (Matrix&, Matrix&);    //перевантаження операції "не рівне" (3 спосіб)
};