#include<iostream>
#include<string>
#include<regex>
using namespace std;
#define NAME_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
	std::string last_name="TUpemko";
	std::string first_name="Vasya";
	//cout << "¬ведите фамилию,им€: "; cin >> last_name >> first_name;
	std::regex rgx("[A-Z][a-z]{1,15}");
	if (std::regex_match(last_name.c_str(), rgx,std::regex_constants::match_any))
	{
		cout << "Surname OK:" << last_name << endl;
	}
	else
	{
		cout << "Bad surname!!!" << endl;
	}
	if (std::regex_match(first_name, rgx))
	{
		cout << "Name OK:" << first_name << endl;
	}
	else
	{
		cout << "Bad Name!!!" << endl;
	}
}
