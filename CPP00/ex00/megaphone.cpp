#include <iostream>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for (i = 1; i < argc; i++)
        {
            for (j = 0; argv[i][j]; j++)
                std::cout << (char) std::toupper(argv[i][j]);
        }
        std::cout << std::endl;
    }
	return (0);
}

/*
#include <iostream>              
using namespace std;
int main()                          
{                          
    cout << "Hello world";    
    return 0;                      
}
*/

