// Author: Sarah Lakos
//
// second change
//
#include <iostream>
#include <cassert>
using namespace std;

const bool verbose = true;
bool trace = false;
static int depth = -1;


void Indent(int level, const char* s = " . ")
{
    for (int i = 0; i < level; ++i)
    {
        cout << s;
    }
}

int globalcount = 0;

int Factorial(int number)
{
    ++depth;
    int result;
    
    if (trace == true)
    {
        Indent(depth);
        cout << "Factorial(" << number << ")" << endl;
    }
	if (0 == number)
	{
		result = 1;
	}
	else
    {
	    result = Factorial(number - 1) * number;
    }
    
    Indent(depth);
    
    cout << "returns (" << result << ")" << endl;
    --depth;
    return result;
}

void TestFactorial()
// Test to make sure the function 'Factorial' is working correctly.
{
    if (verbose) cout << endl << "TestFactorial" << endl;
    
    {
        if (verbose) cout << "0-4 is good????" << endl;
        
        
         assert(Factorial(0) == 1);
		assert(Factorial(1) == 1);
		assert(Factorial(2) == 2);
		assert(Factorial(3) == 6);
		assert(Factorial(4) == 24);
		if (verbose) cout << "0-4 is good" << endl;
	}
}

int GetInteger()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    return number;
}

int main()
{
	
    if (verbose == true)
    {
        cout << "Hello World ... verbose true" << endl;
    }
    
    if (verbose == true)
    {
        char ans;
        cout << "Trace y or n?" << endl;
        cin >> ans;
        if('y' == ans)
        {
            trace = true;
        }
        else if('n' == ans)
        {
            trace = false;
        }
        cout << "trace: " << trace << endl;
    }
    
	TestFactorial();
    
	cout << "factorial" << endl;
    
    int number;
        
    while ((number = GetInteger()) >= 0)
    {
        int result = Factorial(number);
        cout << "Factorial (" << number << ") is " << result << endl;
    }
    
    if (number < 0)
    {
        cout << "Bie Bie!" << endl;
        return 0;
    }
    
	return 0;
}
    
    
    
