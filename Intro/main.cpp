#include<iostream>
#include <math.h>
using namespace std;

#define tab "\t"
#define delimetr "-----------------------------------------------\n"

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

	//              operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: \t" << this << endl;
		return *this;
	}
	//Point operator+(const Point& other)const
	//{
	//	Point result;
	//	result.x = this->x + other.x;
	//	result.y = this->y + other.y;
	//	cout << "Operator+: \t" << this << endl;
	//	return result;
	//}

	Point& operator++() //prefix increment
	{
		this->x++;
		this->y++;
		cout << "Increment:\t" << this << endl;
		return *this;

	}
	Point operator++(int) //postfix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		cout << "Suffix increment" << endl;
		return old;
	}

	//				Methods:
	void print()
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}

	double distance(const Point& other)const
	{
		double distance_x = this->x - other.x;
		double distance_y = this->y - other.y;
		double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
			return distance;
		//return sqrt((B.x - this->x) * (B.x - this->x) + (B.y - this->y) * (B.y - this->y));
	}

};
double distance(const Point& A, const Point& B)
{
	double distance_x = B.get_x() - A.get_x();
	double distance_y = B.get_y()- A.get_y();
	double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
	return distance;
}
//После того, как мы создали структуру можно создавать ее объекты.
//Создавая структуру или класс мы создаем новый тип данных.

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global Plus" << endl;
	return result;
}
//#define STRUCT
//#define CLASSROOM
//#define DISTANCE_AND_CONSTRUCTORS
//#define ASSIGNMENT_CHECK
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
#ifdef CLASSROOM

	Point A(2.3, 4.5);	//Constructor
	/*A.set_x(2);
	A.set_y(3);*/
	cout << sizeof(A) << endl;
	cout << A.get_x() << tab << A.get_y() << endl;

	Point B;		//DefaultConstructor
	B.print();

	Point C = A;	//CopyConstructor  
#endif // CLASSROOM
#ifdef DISTANCE_AND_CONSTRUCTORS
	Point A(2.3, 4.5);
	Point B(6.7, 8.3);
	cout << "\nРасстояние между точками А и В: " << A.distance(B) << endl << endl;
	cout << "\nРасстояние между точками В и А: " << B.distance(A) << endl << endl;
	cout << "\nРасстояние между точками А и В:" << distance(A, B) << endl << endl;
	cout << "\nРасстояние между точками В и А: " << distance(B, A) << endl << endl;
	A = B;
	cout << "-------------------------------------------------------------------------" << endl;
	Point E = A;
	Point F;
	F = B;
	cout << "-------------------------------------------------------------------------" << endl;
#endif // DISTANCE_AND_CONSTRUCTORS
#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;
	cout << delimetr;
	Point A, B, C;
	A = B = C = Point(2.3, 4.5);  //Point(2.3, 4.5) - явный вызов конструктора.
						   // создается временный безимянный объект 
						   //который существует только в пределах этого выражения
	cout << delimetr;
	//l-value = r -value
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2.3, 4.5);
	Point B(2.7, 3.14);
	cout << delimetr;
	Point C = A + B;
	C.print();
	++C;
	C.print();
	C++;
	C.print();
    
}
