// 26-04.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<conio.h>

using namespace std;

class A
{
public:
	A(){cout<<"DEF cons., this --> "<<this<<endl;}
	
	A(const A &ref)
	{
		cout<<"CC\n";
	}
	
	A mem_func(){return A();}
	
	~A(){cout<<"DES, this --> "<<this<<endl;}
};
A func(){return A();}

void f(const A &r){cout<<"Inside f()\n";}
int main()
{
	//Run these all statements ONE BY ONE.
	//____________________________________________________
	//const A &ref = func();			//In this segment, temp. are bound to reference.
	//const A &ref = A();

	//const A &ref = A().mem_func();
	//const A &ref = func().mem_func();
	//____________________________________________________
	
	
	//_____________________________________________________
	//This segment is a bit different.
	
	//f(func().mem_func());		//You very well know what'll happen. Just added for practice.
	//f(A().mem_func());
	//_____________________________________________________
	//cout<<"Typeid A() = "<<typeid(A()).name()<<endl;	//Try to dig deep about its output. 
	
	cout<<"Hello!\n";
	_getch();
	return 0;
}