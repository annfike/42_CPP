#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


class Complex {
public:
    // Constructor with default values
    Complex(double real = 0.0, double imag = 0.0) : _real(real), _imag(imag) {}

    // Member functions to get real and imaginary parts
    double real() const { return _real; }
    double imag() const { return _imag; }

    // Member function to print the complex number
    void print(std::ostream &os) const {
        os << _real << " + " << _imag << "i";
    }

    private:
        double _real; // Real part
        double _imag; // Imaginary part
    };

    // Global operator<< function
    std::ostream &operator<<(std::ostream &os, const Complex &c) {
        c.print(os); // Use the member function to print
        return os;   // Return the stream
    }

int main()
{
    int * a = new int();
	std::cout << "a = " << *a << std::endl;
	delete a;

    Array<int> numbers(5);
    try
	{
		std::cout << numbers[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "------------------array" << std::endl;
    std::srand(time(NULL));
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = rand();
    }
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << std::endl;
    }

    std::cout << "---------------copy to array2" << std::endl;
    Array<int> numbers2 = numbers;
    for (unsigned int i = 0; i < numbers2.size(); i++)
    {
        std::cout << numbers2[i] << std::endl;
    }

    std::cout << "----------------assignment to array3" << std::endl;
    Array<int> numbers3(10);
    numbers3 = numbers;
    for (unsigned int i = 0; i < numbers3.size(); i++)
    {
        std::cout << numbers3[i] << std::endl;
    }

    std::cout << "-----------------string array" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    for (unsigned int i = 0; i < stringArray.size(); i++)
    {
        std::cout << stringArray[i] << std::endl;
    }

    std::cout << "-----------------complex array" << std::endl;
    // Create an array of Complex numbers
    Array<Complex> complexArray(3);
    
    // Assign values to the array
    complexArray[0] = Complex(1.0, 2.0);
    complexArray[1] = Complex(3.0, 4.0);
    complexArray[2] = Complex(5.0, 6.0);

    // Print the complex numbers
    for (unsigned int i = 0; i < complexArray.size(); i++) {
        std::cout << "complexArray[" << i << "] = " << complexArray[i] << std::endl;
    }

    // Test exception handling for out-of-bounds access
    try {
        std::cout << complexArray[5] << std::endl; // Should throw an exception
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl; // Output: Index out of range
    }

    std::cout << "-----------------empty array" << std::endl;
    // Create an empty Array of Complex numbers
    Array<Complex> emptyComplexArray;

    // Check the size of the empty array
    std::cout << "Size of empty array: " << emptyComplexArray.size() << std::endl; // Outputs: 0


    return 0;
}

/*
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/