#include<iostream>
using namespace std;

class Fraction
{
	int numerator ;
	int denumerator;
public:
	//GET,SET методы
	int get_numerator()const
	{
		return numerator;
	}
	int get_denumerator()const
	{
		return denumerator;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denumenator(int denumerator)
	{
		this->denumerator = denumerator;
	}
	//Конструктор с параметрами
	Fraction(int numerator = 1, int denumerator = 1)
	{
		this->numerator = numerator;
		this->denumerator = denumerator;
	}
	//Методы
	void Print()
	{
		cout << numerator << "/" << denumerator << endl;
	}
	//Операторы изменяющие операнды
	Fraction &operator++() 
	{
		this->numerator++;
		this->denumerator++;
		return *this;
	}
	Fraction &operator--() 
	{
		this->numerator--;
		this->denumerator--;
		return *this;
	}
	Fraction operator+=(Fraction &other)
	{
		return this->numerator += other.numerator, this->denumerator += other.denumerator;
	}
	Fraction operator-=(Fraction &other)
	{
		return this->numerator -= other.numerator, this->denumerator -= other.denumerator;
	}
	Fraction operator*=(Fraction &other)
	{
		return this->numerator *= other.numerator, this->denumerator *= other.denumerator;
	}
	Fraction operator/=(Fraction &other)
	{
		return this->numerator /= other.numerator, this->denumerator /= other.denumerator;
	}


	~Fraction()
	{
	}
	};
//Операторы не изменяющие операнды
Fraction operator+(const Fraction &a, const Fraction &b)
{
	Fraction result;
	result.set_numerator(a.get_numerator()+b.get_numerator());
	result.set_denumenator (a.get_denumerator()+b.get_denumerator());
	return result;

}Fraction operator-(const Fraction& a, const Fraction& b)
{
	Fraction result;
	result.set_numerator(a.get_numerator() - b.get_numerator());
	result.set_denumenator(a.get_denumerator() - b.get_denumerator());
	return result;
}
	
Fraction operator*(const Fraction &a, const Fraction &b)
{
	Fraction result;
	result.set_numerator(a.get_numerator() * b.get_numerator());
	result.set_denumenator (a.get_denumerator() * b.get_denumerator());
	return result;
}
Fraction operator/(const Fraction &a, const Fraction &b)
{
	Fraction result;
	result.set_numerator(a.get_numerator() / b.get_numerator());
	result.set_denumenator (a.get_denumerator() / b.get_denumerator());
	return result;
}

#define delimetr "---------------------------------\n"
void main()
{
	Fraction a(2, 5);
	Fraction b(8, 15);
	Fraction c;
	
	c = a + b;
	c.Print();
	c = b - a;
	c.Print();
	c = b * a;
	c.Print();
	c = b / a;
	c.Print();
	cout << delimetr;
	++c;
	c.Print();
	--c;
	c.Print();
	cout << delimetr;
	c += b;
	c.Print();
	c -= a;
	c.Print();
	c *= b;
	c.Print();
	c /= b;
	c.Print();



	

}