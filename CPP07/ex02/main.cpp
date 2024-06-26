#include "Array.hpp"
#include <cmath>

#define MAX_VAL 10

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    for (unsigned int i = 0; i < MAX_VAL; i++)
        std::cout << "i(" << i << "): n = " << numbers[i] << "; m = " << mirror[i] << "\n";
    srand(time(NULL));
	std::cout << "\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		std::cout << "i(" << i << "): value = " << value << "\n";
    }
    //SCOPE
	std::cout << "\n\nTEST 1: copy constructor and copy assignment operator\n";
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		for (unsigned int i = 0; i < MAX_VAL; i++)
			std::cout << "i(" << i << "): tmp = " << tmp[i] << "; test = " << test[i] << '\n';
    }
	std::cout << "\n";
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
