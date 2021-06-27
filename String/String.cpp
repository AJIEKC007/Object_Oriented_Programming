#include"String.h"
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////    CLASS DEFINITION(ОПРЕДЕЛЕНИЕ КЛАССА)    ////////////////////////////////

unsigned int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//			Constructors:
String::String(unsigned int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "SizeConstructor:" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	//this->size = other.size;
	////this->str = other.str;	//Shallow copy
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];	//Побитовое (поэлементное, побайтовое) копирование.
	//															//Deep copy.
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other)
{
	//MoveConstructor должен работать так, как НЕ должен работать CopyConstractor, то есть,
	//CopyConstructor должен выполнять DeepCopy
	//MoveConstructor должен выполнять ShallowCopy, 
	//то есть копировать только адрес на уже выделенную память
	//MoveConstructor НЕ ДОЛЖЕН ВЫДЕЛЯТЬ ДИНАМИЧЕСКУЮ ПАМЯТЬ!!!
	//он берет память временного безымянного объекта, и передает ее создаваемому объекту.
	//При этом, временный объект должен потерять доступ к своему значению.
	//C++11
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	//0) Проверяем, не является ли this и other одним и тем же объектом:
	if (this == &other)return *this;
	//1) Удаляем старое значение объекта:
	delete[] this->str;
	//2) Выполняем копирование:
	this->size = other.size;
	//this->str = other.str;	//Shallow copy
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];	//Побитовое (поэлементное, побайтовое) копирование.
																//Deep copy.
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
const char& String::operator[](unsigned int i)const
{
	return str[i];
}
char& String::operator[](unsigned int i)
{
	return str[i];
}

//			Methods:
void String::print()const
{
	cout << "Size:" << size << endl;
	cout << "Str: " << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);	//Size constructor
	//cat - локальный объект, он существует только с впределах функции operator+();
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	//cout << typeid(is.rdbuf()).name() << endl;
	return is >> obj.get_str();
}

/////////////////////    CLASS DEFINITION END(КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА)    //////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////