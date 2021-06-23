#include <iostream>
using namespace std;

class Box
{
	double height, wigth,depth;
	string material;
public:
	Box(string material,double height, double  wigth, double  depth)
	{
		this->material = material;
		this->height = height;
		this->wigth = wigth;
		this->depth = depth;
		cout << "Bconstructor:\t" << this<<endl;
	}
	~Box()
	{
		cout << "BDestructor:\t" << this << endl;
	}
	void print()
	{
		cout << "Material:   " << material << endl;
		cout << "Dimensions: " << height << "x"<<wigth<<"x"<<depth<<endl;
		cout << "Volume:     " << height * wigth * depth << endl;
	}

};
class GiftBox :public Box
{
	string cover;
public:
	GiftBox(string material, double height, double  wigth, double  depth,string cover):
		Box(material,height,wigth,depth)
	{
		this->cover = cover;
		cout << "GBConstructor:\t" << this << endl;
	}
	~GiftBox()
	{
		cout << "GBDestructor:\t" << this << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Box box("������", 3, 4, 5);
	box.print();
	GiftBox gift_box("Cardboard", 3, 4, 5, "With roses");
	gift_box.print();

}