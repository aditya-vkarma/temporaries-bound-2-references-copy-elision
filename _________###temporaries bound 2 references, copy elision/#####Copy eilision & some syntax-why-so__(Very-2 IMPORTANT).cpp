class A
{
	int i;
	double d;
public:
	A(){cout<<"A's DEF\n";}
	A(int a, double b)
	{
		i = a;
		d = b;
		cout<<"A's prmtrzd\n";
	}
	A(const A &ref){i = ref.i; d = ref.d; cout<<"A's CC\n";}
};

class B
{
	A a;	// A a(12, 24.36)	causes error. Error : constant. May be, constant values are not allowed in a
			// class's member variable declarations.
			//So whenever we create an object of B, B::a will be constructed by
			//A's Def. cons. A::A(), So what if we wanted to initialize a by A's prmtrzd ctors
			// whenever we created an object of B?
			// Solution is below.
public:
	B() : a(A(5, 7.8)) {cout<<"B's DEF\n";}		//Here, a(A(5, 7.8)) is undergoing copy elision.
	
	
												//B() : a(5, 7.8) also does the same thing.
												//Now, whenever we create an object of B, B::a
												//will be constructed first by A::A(int, double)
												//and not by A's Def. cons A::A().

	//1 more thing: Suppose we create an object of B as:
	//B b;	the compiler first goes to the constructor with which b will be
			//constructed (B's DEF. cons B::B() in this case), and there, after seeing the colon
			//and the statement a(A(5, 7.8)) , it will come to know that B::a is to be constructed using A's prmtrzd cons
			// A::A(int, double). Once it constructs A::a using this, then it'll construct B
			//by executing B::B().
	
	//	B() : a(5, 7.8), a(A(8, 2.5)){}		These two statements
	//	B() : a(5, 7.8), a(A(5, 7.8)){}		are invalid.
	//	The first initializer after the colon initizlizes a and the second one
	//after the comma causes this error. Error : a is already initialized
};

void a(int a, double e){cout<<"Function called\n";}

int main()
{
	B b;
	_getch();
	return 0;
}

	//_______________________________________________________
	/*
	#1 Write this first just as two liner.
	
	//A a(4, 3.66);	//Standard syntax for initializing object on it's declaration
	//A a(A(3, 8.88));	//That's the alternate way to the above standard method.
	*/

//Remember,
// int i;
// i(); or i(24);	// These are not at all valid. Senseless. Coz, i is of type int and not a
					// function name.

// i();		//Error : term does not evaluate to a function taking 0 arguments
// i(24);	//Error : term does not evaluate to a function taking 1 arguments
	
//look at a similar case below:


	
//1.		A a;
//2.		//a(12, 35.63);		//These two are totally
//3.		//a(A(12, 35.63));	//senseless here. Coz, a is of type A and not a function name
								//Error : term does not evaluate to a function taking 2 arguments

		
	//I think, Since, in 1, You were free to contruct a with any prmtrzd ctor of A as:
	// A a(23, 52.51);	or	a(A(17, 23.84));
	// So 2, 3 are totally senseless. 
	
	
	//Object creation and it's construction happen together as a unit. For Ex.
	// A a;	//Doesn't mean that we've only created but not constructed a and
	// a(4, 43.63); or a(A(9, 2.53);	//doesn't mean that we've 
										//constructed that (created only) a.
	


	//Moreover,
	//	A a(9, 7.46);	This standard syntax says: create a and construct it using A's
	//	prmtrzd cons	A::A(int, double).
	
	// Conclusion
	// class_name var_name(arg1, arg2, ...) as a whole is a standard syntax so after this
	// you can't do this:
	// var_name(...)