#include<iostream>
#include<string>
#include<regex>
using namespace std;

#define delimiter "\n-----------------------------------------------------------\n"
class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		std::regex en_rgx("[A-Z][a-z]{1,15}");
		std::regex ru_rgx("[А-Я][а-я]{1,15}");
		std::regex ru_double_rgx("([А-Я][а-я]{1,15}[ -]{0,1}){1,2}");
		//std::regex ru_double_rgx("[А-Я][а-я]{1,15}[ -]{0,1}[А-Я]{0,1}[а-я]{0,15}");
		//std::regex ru_double_rgx("\\(ru_rgx)[ -](ru_rgx){0,1}");
			if (std::regex_match(last_name, en_rgx)|| 
				std::regex_match(last_name, ru_rgx)||
				std::regex_match(last_name, ru_double_rgx)
				)this->last_name = last_name;
			else this->last_name = "Bad name";
	}
	void set_first_name(const string& first_name)
	{
		std::regex en_rgx("[A-Z][a-z]{1,15}");
		std::regex ru_rgx("[А-Я][а-я]{1,15}");
		if (std::regex_match(first_name, en_rgx)|| std::regex_match(first_name, ru_rgx))this->first_name = first_name;
		else this->first_name = "Bad name";
	}
	void set_age(unsigned int age)
	{
		if (age >= 18 && age <= 150)this->age = age;
		else this->age=0;
	}
	//     Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	virtual void print()
	{
		cout << last_name << " " << first_name << " " << age << " лет.\n";
	}
};
 ostream& operator<<(ostream& os, const Human& obj)
{
	os << obj.get_last_name() << " " << obj.get_first_name() << "," << obj.get_age() << "лет.";
	return os;
}
class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating() const
	{
		return rating;
	}
	void set_spetiality(const string& spetiality)
	{
		this->speciality = spetiality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		if (rating >= 0 && rating <= 100)this->rating = rating;
		else this->rating = 0;
	}
	//Constructor
	Student(
		const string& last_name, const string& first_name, unsigned int age,
		const string& spetiality, const string& group, double rating
	) :Human(last_name, first_name, age)
	{
		set_spetiality(spetiality);
		set_group(group);
			set_rating(rating);

	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	// Methods
	void print()
	{
		Human::print();
		cout << "специальность: " << speciality << ",группа: " << group << ", успеваемость: " << rating << endl;
	}
};
ostream& operator<<(ostream& os, const Student& obj)
{
	os << (Human&)obj << " ";
	os<<"специальность: "<<obj.get_speciality() << ",группа: " << obj.get_group() << ", успеваемость: " <<obj.get_rating() <<endl;
	return os;
}
class Teacher :public Human
{
	string speciality;
	unsigned int experiance;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experiance()const
	{
		return experiance;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experiance(unsigned int experiance)
	{
		if (experiance >= 0 && experiance <= 130)this->experiance = experiance;
		else experiance = 0;
	}
	//constructors
	Teacher(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experiance
	) :Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->experiance = experiance;
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//methods:
	void print()
	{
		Human::print();
		cout << "специальность: " << speciality << ", опыт преподавания: " << experiance <<" лет."<< endl;
	}

	
};
ostream& operator<<(ostream& os, const Teacher& obj)
{
	os << (Human&)obj << " ";
	os << "специальность: " << obj.get_speciality()
		<< ",опыт преподавания " << obj.get_experiance() << ", лет" << endl;
	return os;
}

class Graduate :public Student
{
	string subject;
	//Teacher instructor;
public:
	const string& get_subject()const
	{
		return subject;
	}
	void set_subject(const string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(const string& last_name, const string& first_name, unsigned int age,
		const string& spetiality, const string& group, double rating,
		const string& subject
	) : Student(last_name, first_name, age, spetiality, group, rating)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void print()
	{
		Student::print();
		cout << "Тема дипломного проекта: " << subject << endl;
	}
};
ostream& operator<<(ostream& os, const Graduate& obj)
{
	os << (Student&)obj;
	return os <<"Тема диплома: "<< obj.get_subject();
}

//#define INHERITANCE_BASICS
void main()
{
	setlocale(LC_ALL, "rus");
#ifdef INHERITANCE_BASICS
	setlocale(LC_ALL, "rus");
	Human human("Тупенко", "Василий", 18);
	human.print();
	Student stud("Тупенко", "Василий", 18, "РПО", "BV_123", 43.4);
	stud.print();
	Teacher Albert("Einstein", "Albert", 150, "Astrophisics", 120);
	Albert.print();
#endif // INHERITANCE_BASICS

	//                  POINTERS TO BASE CLASS

	Human* group[] =
	{
		new Student("Василььев","Александр",23,"РПО","ПВ011",90),
		new Student("Васильева"," Маргарита",23,"РПО","ПВ011",90),
		new Teacher("Петров Сидоров", "Олег",36,"Разработка приложений на С++",6),
		new Student("Ивлев","Александр",25,"РПО","ПВ011",95),
		new Graduate("Рахманин","Николай",28,"РПО","ПВ011",98,"Разработка кросплатформенной обучающей игры"),
		new Teacher("Романов", "Андрей",36,"HardWarePC",6),
		new Student("Нусс","Дмитрий",28,"РПО","ПВ011",100),
		new Student("Борн","Евгений",35,"РПО","ПВ011",99),

	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		//cout << *group[i];
		//cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		//cout << delimiter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}