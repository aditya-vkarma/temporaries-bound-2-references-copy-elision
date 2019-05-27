// temporaries bound 2 references.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<conio.h>
using namespace std;
/*
class A
{
public:
	A(){cout<<"DEF CONS\n";}
	~A(){cout<<"DES called\n";}
};

int func(A &ref)
{
	cout<<"Inside func's body\n";
	return 8;
}

void func1(int a)
{
	cout<<"Inside func1's body\n";
}

int main()
{
	func1(func(A()));	//Here, A() is valid coz of VS bug.

	_getch();
	return 0;
}*/


//__________________________________________________________


/*
class xclass
{
	public:
	int i;
	char ch;
	char *sptr;

	xclass(int a = 12, char ch = 'H', char *p = "Hack")
	{
		i = a;
		this->ch = ch;
		sptr = p;
	}

	xclass(const xclass &ref)
	{
		i = ref.i;
		this->ch = ref.ch;
		sptr = ref.sptr;
		cout<<"Inside CC\n";
	}

};
int main()
{
	xclass obj = 15;			//These both do the
	xclass obj1 = xclass(15);	// same thing. And you very well know why.

	cout<<"obj.i = "<<obj.i<<endl;
	cout<<"obj.ch = "<<obj.ch<<endl;
	cout<<"obj.sptr = "<<obj.sptr<<endl<<endl;

	cout<<"obj1.i = "<<obj1.i<<endl;
	cout<<"obj1.ch = "<<obj1.ch<<endl;
	cout<<"obj1.sptr = "<<obj1.sptr<<endl<<endl;

	_getch();
	return 0;
}*/

//________________________________________________

/*
class A
{
public:
	int a;
	A(){cout<<"DEF cons, this-> "<<this<<endl;}
	A(const A &ref){cout<<"CC, this-> "<<this<<", &ref-> "<<&ref<<endl;}
	~A(){cout<<"DES, this-> "<<this<<endl;}
	A operator=(const A &ref){cout<<"Inside operator=, this-> "<<this<<", &ref-> "<<&ref<<endl; return *this;}
};
int main()
{
	A obj[5];
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		obj[i] = A();
		cout<<endl;
	}
	cout<<"Hello\n";
	_getch();
	return 0;
}
*/

//________________________________________________________________________


class A
{
public:
	int a;
	A(){cout<<"DEF cons, this-> "<<this<<endl;}
	A(const A &ref){cout<<"CC, this-> "<<this<<", &ref-> "<<&ref<<endl;}
	~A(){cout<<"DES, this-> "<<this<<endl;}
	A operator=(const A &ref){cout<<"Inside operator=, this-> "<<this<<", &ref-> "<<&ref<<endl; return *this;}

	
};

A* func()
{
	//___________
	//	A temp = A();
	//___________	
							//Just try 2 understand these both.
	//_________
	/* A temp;
	   temp = A(); */
	//_________
	
	cout<< &temp <<endl;
	return &temp;
	//return &A();
}

int main()
{
	A *ref = func();
	cout<<"Hello\n";
	//ref.a = 45;
	//cout<<ref.a<<endl;
	cout<< ref <<endl;
	ref->a = 90;
	cout<<ref->a<<endl;
	_getch();
	return 0;
}