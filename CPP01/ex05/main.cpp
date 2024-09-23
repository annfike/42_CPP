#include "Harl.hpp"

/*int	main()
{
	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("test");
}
https://metanit.com/cpp/tutorial/4.8.php
*/

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		std::cout << " Missing arguments for the level. Choose from: DEBUG INFO WARNING ERROR" << std::endl;
	else
	{
		std::string level;
		level = argv[1];
		if(level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR")
            harl.complain(level);
		else
			std::cout << "Sorry, unknown level. Choose from: DEBUG INFO WARNING ERROR" << std::endl;
	}
}