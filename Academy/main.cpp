#include<iostream>
#include<string>
using namespace std;

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
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age=age;
	}
	//     Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	void print()
	{
		cout << last_name << " " << first_name << " " << age << " лет.\n";
	}
};
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
	double get_rating()
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
		this->rating = rating;
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
	// Methods
	void print()
	{
		Human::print();
		cout << "специальность: " << speciality << ",группа: " << group << ", успеваемость: " << rating << endl;
	}
};
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
		this->experiance=experiance;
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

void main()
{
	setlocale(LC_ALL, "rus");
	/*Human human("Тупенко", "Василий", 18);
	human.print();*/
	Student stud("Тупенко", "Василий", 18, "РПО", "BV_123", 43.4);
	stud.print();
	Teacher Albert("Einstein", "Albert", 150, "Astrophisics", 120);
	Albert.print();
	
}