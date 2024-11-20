
#include <iostream>
#include <ostream>

using namespace std;
class SomeError
{
public:
	virtual void print() { cerr << "Some error" << endl; }
};

class NotZero : public SomeError {
public:
	NotZero(){}
	void print() { cerr << "Error[418]: Price and weight can't be <=0" << endl; }

};

class DateBroken : public SomeError{
public:
	DateBroken(){}
	void print() { cerr << "Error[418]: Date of manufacture can't be 0.0.0"  << endl; }
};

class DeleteFromEmptyList : public SomeError {
public:
	DeleteFromEmptyList() {}
	void print() { cerr << "Error: This List empty and this elem can't be deleted" << endl; }
};
