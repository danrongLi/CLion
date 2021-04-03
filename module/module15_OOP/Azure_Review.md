# Module 15 Review Session

## Table of Contents
- [Module 15 Review Session](#module-15-review-session)
	- [Table of Contents](#table-of-contents)
	- [Object Oriented Programming](#object-oriented-programming)
	- [Classes & Objects](#classes--objects)
	- [Encapsulation](#encapsulation)
		- [Protection and Access](#protection-and-access)
		- [Accessor and Mutators](#accessor-and-mutators)
			- [Const keyword](#const-keyword)
	- [Operators](#operators)
	- [Dynamic Memory](#dynamic-memory)
		- [Big 3](#big-3)
	- [Inheritance](#inheritance)
	- [Polymorphism](#polymorphism)
	- [Virtual function](#virtual-function)
		- [Dynamic Binding](#dynamic-binding)

## Object Oriented Programming
Object oriented programming (OOP) is essentially the concept of breaking down a program into a series of objects that are relatively self contained. Objects are created using blueprints, in our case, called classes. 

Benefits of OOP are:
- Easy way to model complex items in simpler structures.
- Enabling class specific behaviour.
- Debugging becomes easier since many classses are self contained and contain all relevant information to them.
- Secure information and prevent wrongful access to items.
- Allows for ease of reuse across programs, just copy paste the class over and make an object and you're good to go.

## Classes & Objects

Think of classes as a blueprint that can be used to create something, and the object is the thing that is created from said blueprint.

> Show example syntax/talk through it, member functions, variables, initialization list, constructors, etc, the 'this' keyword.

## Encapsulation

You bundle a set of attributes that store the current state of the object with a set of methods using these attributes. Thus encapsulating all the functionality into one single location.

### Protection and Access

> Talk about how the keywords work:
> - Private
> - Public
> - Protected (Touched upon during inheritance).

### Accessor and Mutators

> - Accessor: Member function used to retrieve the data of protected members.
> - Mutators: Member function used to edit the data of protected members.

#### Const keyword
> - Both variables and functions can be a const. 
> - Const variables cannot be changed. Const functions cannot change the value of any variable/piece of data, it can only read it.
> - The mutable keyword, touch on that.

## Operators
> - What is an operator?
> - Member vs non-member functions.
> - All the different operators.
> - Can't overload: . :: *. sizeof ?:
> - Can overload as member = []
> - Can overload as friend >> <<
> - Can't make new operators.
> - Friend functions can access private!
> - Object& operator++() vs Object operator++(int) (pre/post) increments.
> - Prefer returning by reference for operator overloaded functions when possible.

Note to self to show examples of some operator overloading.

## Dynamic Memory
Shallow vs Deep Copies

### Big 3
- Destructor
- Copy Constructor
- Copy Assignment Operator
  
Copy data! Not values/pointers only!

Show an example implementation of the above!

## Inheritance

Show examples of a class, and how to override/make a function with the same name, and use the base class function.

## Polymorphism 

- Copy data from a derived class into a base class, but only base items copy over. (Slicing)
- Overloading assignment operator allows to copy from a base class into a derived object.
- Base pointers can point to a derived object. (Polymorphism)
- Derived pointer can never point to base object!!

```cpp
int main() {
	Base b;
	Base* b_ptr;
	Derived d;
	Derived* d_ptr;
	b = d; // Allowed
	d = b; // Define operator=(const Base&)
	b_ptr = &d; // Allowed
	d_ptr = &b; // Never allowed!
}
```

## Virtual function
### Dynamic Binding
Version of function called is dependant on the object, not the pointer.

Virtual functions result in the derived classes version taking precedence instead of the same level as the object called. Non-virtual functions do not follow this example.

Pure virtual functions must be implemented by the derived class. Purity is defined by adding a `= 0;` at the end of the function.
