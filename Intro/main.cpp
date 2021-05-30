#include<iostream>
using namespace std;

#define tab "\t"

class Point	//Описывает точку на плоскости
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//				Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)//Принимает другой существующий объект по константной ссылке
	{
		//other - это просто имя принимаемого параметра (имя другого объекта)
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Methods:
	void print()
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
};
//После того, как мы создали структуру можно создавать ее объекты.
//Создавая структуру или класс мы создаем новый тип данных.

//#define STRUCT

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT
	int a;		//Объявление (создание) переменной 'a' типа 'int'
	Point A;	//Объявление (создание) переменной 'a' типа 'Point'
				//Создание объекта стуктуры Point
				//Объявление объекта структуры Point
	//Объект - это самая обычная переменная, но не примитивного типа (char, int, double....),
	//а пользовательского.
	//Объект - это переменная нашего типа.
	//Объекты еще называют экземплярами класса или структуры.
	//Структуры и классы еще называют пользоватильскими типами данных.

	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT

	Point A(2.3, 4.5);	//Constructor
	/*A.set_x(2);
	A.set_y(3);*/
	cout << sizeof(A) << endl;
	cout << A.get_x() << tab << A.get_y() << endl;

	Point B;		//DefaultConstructor
	B.print();

	Point C = A;	//CopyConstructor
}
