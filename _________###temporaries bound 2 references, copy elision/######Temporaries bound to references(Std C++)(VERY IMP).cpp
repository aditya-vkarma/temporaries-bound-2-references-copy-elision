// 26-04.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<conio.h>

using namespace std;


//This part is to tell you some concepts and lower part is for practice.

struct X
{
X& ref() { return *this; }	//Not returns temp. Returns a reference to invoking(this) object.
};
X getX() { return X();}		//Returns a temp.
void g(X &x) {}

int main()
{
	//#1. Temps. are implicitly treated as const coz they WERE NOT MEANT TO BE MODIFIED
	//so they must be bound to const references.
	
	//#2. Temps. are nameless objects(returned BY VALUE NOT by REFERENCE) so,
	//	  X(), getX() return temps.
	//	  X().ref(), getX().ref() don't.
	
	
	//const X& x = getX();		//Ok, Life Extended. Temps. can only be bound to const references
	//const X& x = X();			//Ok, Life Extended
	

	//X& x = getX();			//Error (Standard C++). Temporaries can't be bound to
	//X& x = X();				//non-const references.
	//g(getX());				//VS has bugs which makes these four statements correct!
	//g(X());					//(You better know!)
	
	

	//X& x = getX().ref();		//Both Valid but DANGEROUS: x becomes a dangling reference to
	//X& x = X().ref();			//temporary. coz temp. created by getX() and X() is destroyed
						//after MF ref() has finished execution on them. (You better know why!)
	
	
	//g(getX().ref());			//Ok, coz temp dies after g() has returned
	//g(X().ref());				//but NOT A GOOD PRACTICE and NOT RECOMMENDED (by me).
	

	//X &x = (X&) X();			//All 3 invalid (Std C++), though buggy VS allows.
	//X &x1 = (X&) getX();		//Error: invalid cast of an rvalue expression of type 'X' to type 'X&'
	//X &x2 = const_cast<X&> ( X() );

	_getch();
	return 0;
}

//______________________________________________________

//Practice.

/*

#include "stdafx.h"
#include<iostream>
#include<conio.h>

using namespace std;


struct X
{
	X(){cout<<"Def cons. "<<this<<endl;}
	X(const X &r) {cout<<"Inside CC, this obj "<<this<<" being copied from "<<&r<<endl;}
	~X(){cout<<"Inside des., this "<<this<<endl;}
	X& ref() { return *this; }	//Not returns temp. Returns a reference to invoking(this) object.

	void say(){cout<<"Hello\n";}
};
X getX() { return X();}		// Returns a temp.
X getX1() { X x; return x;}	// Returns a temp.

X& getX2() { return X();}	// Doesn't return a temp.
void g(X &x) {}

int main()
{
	//getX();			//These 4 are valid ex. of temporaries in action.
	//getX().say();
	//getX1();
	//getX1().say();
	
	//getX2().say();	//Valid, but, 1stly, it has nothing to do with temporaries, 2ndly, it's totally dangerous coz
						//it's Calling MF say() on a dangling reference of X. 

	_getch();
	return 0;
}
*/