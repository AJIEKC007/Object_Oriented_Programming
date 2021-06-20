#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "---------------------------------------"

class String
{
	unsigned int size;  //Размер строки в байтах
	char* str;         // Указатель на строку в динамической памяти
public:
	unsigned int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//          Constructors;
	explicit String(unsigned int size = 80) :size(size), str(new char[size] {})
	{
		/*this->size = size;
		this->str = new char[size] {};*/
		cout << "SizeConstructor:" << this << endl;
	}
	String(const char str[]):String(strlen(str)+1)
	{
	
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;

	}
	String(const String& other):String(other.str)
	{
		//this->size = other.size;
		////this->str = other.str; //Нельзя так делать  с указателями!! //Shallow copy
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];//Побитовое(поэлементное) копирование
		//                                                           // Deep copy.
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other)
	{
		//MoveConstructor должен работать так, как недолжен работать CopyConstructor
		//Копиконструктор должен выполнять DeepCopy
		//MoveConstructor должен выполнять ShallowCopy
		//то есть копировать только адрес на уже выделенную память
		//MoveConstructor НЕ ДОЛЖЕН ВЫДЕЛЯТЬ ДИНАМИЧЕСКУЮ ПАМЯТЬ!!
		//он берет память временного безымянного объекта, и передает ее создаваемому объекту
		//при этом временный объект жлджен потерять доступ к своему значению
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//         Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		//this->str = other.str; //Нельзя так делать  с указателями!! //Shallow copy
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];//Побитовое(поэлементное) копирование
																   // Deep copy.
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignmen:\t" << this << endl;
		return *this;
	}
	const char& operator[](unsigned int i) const
	{
		return str[i];
	}
	char& operator[](unsigned int i)
	{
		return str[i];
	}
	//     Methods:
	void print()const
	{
		cout << "Size: " << size << endl;
		cout << "Str: " << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
//std::istream& operator>>(std::istream& is, String& obj)
//{
//	return is >> obj.get_str();
//}

//#define CONSTRUCTORS_CHECK
//#define INPUT_CHECK
#define OPERATOR_PLUSE_CHECK
//#define HOW_CAN_WE_CALL_CONSTRUCTORS
void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();
	cout << str1 << endl;
	String str2 = str1;
	str2.print();
	String str3;
	str3 = str2;
	cout << str3 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef INPUT_CHECK
	String str;
	cout << "Введите строку: "; cin >> str;
	cout << str << endl;

#endif // INPUT_CHECK
#ifdef OPERATOR_PLUSE_CHECK
	String str1 = "Hello";
	String str2 = "World";
	//cout << delimiter << endl;
	//String str3;         //Default constructor
	//str3 = str1 + str2;   //moveAssignment
	////MoveMethods - метод переноса
	////относят MoveConstructor (конструктор), MoveAssignment оператор переноса
	////методы переноса неявно вызываются в том случае когда объект нужно проинициализировать или присвоить ему значение временного безимянного объекта
	//cout << delimiter << endl;
	//cout << str3 << endl;
	////str1 += str2;
	cout << str1 << endl;
	cout << delimiter << endl;
	String str3 = str1;
	cout << delimiter << endl;
	cout << str3 << endl;
#endif // OPERATOR_PLUSE_CHECK
#ifdef HOW_CAN_WE_CALL_CONSTRUCTORS

	String str1;              //Default constructor
	String str2 = "Hello";    //Single-argument constructor
	String str3 = str2;      // Copy constructor
	String str4;
	str4 = str3;             //Copy assignment
	String str5();
	String str6{};         //Явный вызов конструктора по умолчания

#endif // HOW_CAN_WE_CALL_CONSTRUCTORS


}