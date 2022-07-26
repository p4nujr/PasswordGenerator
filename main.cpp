#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>



//brief presentation of the tool + options
int presentationOptions()
{
	std::cout << "--------------------------------------\nThis tool creates strong passwords\n--------------------------------------\n\n";
	std::cout << "1) Create only one password: \n2) Create multiple passwords: \n3) Exit\n\n> ";
	int option{};
	std::cin >> option;
	std::cout << '\n';

	return option;
}

//request for the length of the password
int requestLengthPass()
{
	int length{};
	std::cout << "Please enter the length of the password(recommended min.16)\n> ";
	std::cin >> length;
	std::cout << '\n';

	if (length < 1)
	{
		std::cout << "--------------------------------------\n";
		std::cout << "Invalid option :)\n";
		std::cout << "--------------------------------------\n";
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	return length;
}

//request of the number of characters of the password
int requestNumofPass()
{
	std::cout << "\nHow many passwords do you want to create?\n> ";
	int howmany{};
	std::cin >> howmany;

	if (howmany < 1)
	{
		std::cout << "--------------------------------------\n";
		std::cout << "Invalid option :)\n";
		std::cout << "--------------------------------------\n";
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	return howmany;
}

//request, how would the password create?
int whichOption()
{
	std::cout << "\n-Which option do you prefer?\n1) Easy to say (avoid numbers and special characters) -> not recommended\n2) Easy to read (avoid ambiguous characters like O,0,l,|,I...)\n3) All characters\n> ";
	int typePassword{};
	std::cin >> typePassword;
	std::cout << '\n';

	if (typePassword != 1 && typePassword != 2 && typePassword != 3)
	{
		std::cout << "--------------------------------------\n";
		std::cout << "Invalid option :)\n";
		std::cout << "--------------------------------------\n";
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	return typePassword;
}

//generate random characters for the password
char GenRand(int typePassword)
{
	//if user enter 1, then avoid numbers and special characters, so that it is easy to spell the password
	if (typePassword == 1)
	{
		constexpr char onlyAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
		int strLen{ sizeof(onlyAlphabet) - 1 };
		return onlyAlphabet[rand() % strLen];
	}
	
	//if user enter 2, then avoid ambigous characters like O,0,l,|,I...
	if (typePassword == 2)
	{
		constexpr char easy2read[] = "23456789" "@#$%^&*" "ABCDEFGHJKLMNLOPQRSTUVWXYZ" "abcdefghijkmnopqrstuvwxyz";
		int strLen{ sizeof(easy2read) - 1 };
		return easy2read[rand() % strLen];
	}
	
	//if user enter 3, then pick all characters
	if (typePassword == 3)
	{
		constexpr char allCharacters[] = "0123456789" "~!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
		int strLen{ sizeof(allCharacters) - 1 };
		
		return allCharacters[rand() % strLen];

	}
}

//call Genrand() function and print password
void printPassword(int length, int typePassword)
{
	
	for (int count = 0; count < length; count++)
	{
		char character{ GenRand(typePassword) };
		std::cout << character;
	}
	std::cout << '\n';
}

//execute option 1 (create only one password with the length that the user specified)
void option1()
{
	system("cls");
	int typePassword{ whichOption() };
	int length{ requestLengthPass() };
	system("cls");
	std::cout << "\n-> Your Password is: \n";
	std::cout << "--------------------------------------\n";
	printPassword(length, typePassword);
	std::cout << "--------------------------------------\n";
}

//execute option 2 (create multiple passwords with the length that the user specified )
void option2()
{
	system("cls");
	int howmany{ requestNumofPass() };
	int typePassword{ whichOption() };
	int length{ requestLengthPass() };
	system("cls");
	std::cout << "\n-> Your Passwords are: \n" << '\n';
	std::cout << "--------------------------------------\n";
	for (int count = 0; count < howmany; count++)
	{
		printPassword(length, typePassword);
	}
	std::cout << "--------------------------------------\n";
}
 
int main()
{
	system("color 0C");
	int option{ presentationOptions() };	//create variable for the option that the user prefer and use if-sentences

	srand(time(NULL));

	if (option == 1)
		option1();

	if (option == 2)
		option2();

	if (option == 3)
	{
		std::cout << "Exiting...\n";
		exit;
	}

	if (option != 1 && option != 2 && option != 3)
	{
		std::cout << "--------------------------------------\n";
		std::cout << "Invalid option :)\n";
		std::cout << "--------------------------------------\n";
		exit;
	}
	system("PAUSE");

	return 0;
}

