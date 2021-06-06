#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
class Fraction
{
	int integer;
	int numerator;
	int denomenator;
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
		return denomenator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denomenator(int denomenator)
	{
		if (denomenator == 0)denomenator = 1;
		this->denomenator = denomenator;
	}
	//////////Constructors/////////
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denomenator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denomenator = 1;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denomenator)
	{
		this->integer = 0;
		this->numerator = numerator ;
		this->denomenator = denomenator;
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denomenator)
	{
		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denomenator(denomenator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denomenator = other.denomenator;
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
		this->denomenator = other.denomenator;
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

	/////////Nethods///////////

	void to_improper()
	{
		numerator += integer * denomenator;
		integer = 0;
	}
	Fraction& to_proper()
	{
		integer += numerator / denomenator;
		numerator %= denomenator;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		Fraction inverted(denomenator, numerator);
		return inverted;
	}

	void print()
	{
		if (integer)cout << integer;
		if (integer && numerator)cout << "(";
		if (numerator)cout << numerator << "/" << denomenator;
		if (integer && numerator)cout << ")";
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}

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
//#define CONSTRUCTORS_CHECK
//#define ARITHMETHICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK


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

	Fraction A(1, 2);
	Fraction B(5, 10);
	cout << (A != B) << endl;

}