#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "--------------------------"
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//////////Constructors/////////
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denomenator)
	{
		this->integer = 0;
		this->numerator = numerator ;
		this->denominator = denomenator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denomenator)
	{
		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denomenator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	/////////Operators/////////
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigmnent:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{		
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	//////////Icrement/Decrement////
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this; //CopyConstructor
		integer++;
		return old;

	}
	////////////Type-cast operators///////
	explicit operator int()const
	{
		return integer;
	}
	Fraction(double  decimal)
	{
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}
		/////////Nethods///////////
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		Fraction inverted(denominator, numerator);
		return inverted;
	}
	Fraction& reduce()
	{
		if (numerator == 0)
		{
			denominator = 1;
			return *this;
		}
		int more, less;
		int rest; //остаток от деления
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()
	{
		if (integer)cout << integer;
		if (integer && numerator)cout << "(";
		if (numerator)cout << numerator << "/" << denominator;
		if (integer && numerator)cout << ")";
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
	//friend istream& operator>>(istream& is, Fraction& obj);
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denomenator (left.get_denominator() * right.get_denominator());
	result.to_proper();
	return result;*/
	return Fraction //Явно вызываем конструктор и передаем в него параметры
	(		//Этот конструктор создает временный безымянный объект, который сразу же отправляется return-у
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	Fraction result(
		left.get_numerator() * right.get_numerator(),
		right.get_denominator() * left.get_denominator()
	);
		return result;*/
	return left * right.inverted();

}
Fraction operator+(Fraction left,Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
		(left.get_numerator() + right.get_numerator(),
			left.get_denominator() + right.get_denominator()
		).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(left.get_numerator() - right.get_numerator(),
		left.get_denominator() - right.get_denominator()
	).to_proper();
}
bool operator==(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
	}
bool operator!=(Fraction left, Fraction right)
{
	return !(left == right);
}
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())cout << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator())cout << "(";
	if (obj.get_numerator())cout << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator())cout << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)cout << 0;
	return os;
}
istream& operator>>(istream& is,  Fraction& obj)
{
	char str[256]{};
	char* number[5]{};
	int integer, numerator, denominator;
	is.getline(str, 256);
	const char* delimetrs = " (/)";
	int i = 0;
	for (char* pch = strtok(str, delimetrs); pch; pch = strtok(NULL, delimetrs), i++)
	{
		number[i] = pch;
	}
	//for (int i = 0; i < 5; i++)cout << number[i] << tab; cout << endl;
	switch (i)
	{
	case 1: integer = atoi(number[0]); break;
	case 2:
		numerator = atoi(number[0]),
		denominator = atoi(number[1]);
		break;
	case 3:
		integer = atoi(number[0]);
		numerator = atoi(number[1]);
		denominator  = atoi(number[2]);
		break;
	default: cout << "Что-то пошло не так";
	}
	
//	is >> integer >> numerator >>denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;

}


//#define CONSTRUCTORS_CHECK
//#define ARITHMETHICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS_CHECK


void main()
{
	setlocale(LC_ALL, "rus");
#ifdef CONSTRUCTORS_CHECK
	double a = 5; cout << a << endl;
	Fraction A = 5;
	A.print();
	Fraction B(2, 3, 4);
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D;
	D.print();
#endif // CONSTRUCTORS_CHECK
#ifdef ARITHMETHICAL_OPERATORS_CHECK

	Fraction A(1, 2, 3);
	Fraction B(19, 5);
	Fraction C = A * B;	C.print();
	Fraction D = A / B; D.print();

	A *= B;
	A.print();
	A /= B;
	A.print();
#endif // ARITHMETHICAL_OPERATORS_CHECK
#ifdef INCREMENT_CHECK

	for (double i = .25; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	//for(Counter;Condition;Expression);
	for (Fraction i(1, 4); i.get_integer() < 10; ++i)
	{
		cout << i << "\t";
	}
#endif // INCREMENT_CHECK
#ifdef COMPARISON_OPERATORS_CHECK

	Fraction A(1, 2);
	Fraction B(5, 10);
	cout << (A != B) << endl;

#endif // COMPARISON_OPERATORS_CHECK
	
	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = A;
	cout <<"a= "<< a << endl;
	double b = A;
	cout <<"b= "<< b<<endl;
	Fraction C = 2.5;
	cout << C << endl;
	
}