#include <iostream>
#include <random>
#include <chrono>

void invalidOption()
{
    std::cout << "--------------------------------------\n";
    std::cout << "Invalid option :)\n";
    std::cout << "--------------------------------------\n";
}

void ignoreLine()
{
    std::cin.ignore(10000, '\n');
}

// Brief presentation of the tool options and user input
int presentationOptions()
{
    while (true)
    {
        std::cout << "1) Create only one password: \n2) Create multiple passwords: \n3) Exit:\n\n> ";
        int option{};
        std::cin >> option;
        std::cout << '\n';

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            invalidOption();
        }
        else if (option != 1 && option != 2 && option != 3)
        {
            ignoreLine();
            invalidOption();
        }
        else
        {
            ignoreLine();
            return option;
        }
    }
}

// Password lengthening request
int requestLengthPass()
{
    while (true)
    {
        int length{};
        std::cout << "Please enter the length of the password (recommended min.16)\n> ";
        std::cin >> length;
        std::cout << '\n';

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            invalidOption();
        }
        else if (length < 1)
        {
            ignoreLine();
            invalidOption();
        }
        else
        {
            ignoreLine();
            return length;
        }
    }
}

// Request for the number of passwords
int requestNumofPass()
{
    while (true)
    {
        int howmany{};
        std::cout << "\nHow many passwords do you want to create?\n> ";
        std::cin >> howmany;

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            invalidOption();
        }
        else if (howmany < 1)
        {
            ignoreLine();
            invalidOption();
        }
        else
        {
            ignoreLine();
            return howmany;
        }
    }
}

// Format that the password must meet
int whichOption()
{
    while (true)
    {
        int typePassword{};
        std::cout << "\n-Which option do you prefer?\n1) Easy to say (avoid numbers and special characters) -> not recommended\n2) Easy to read (avoid ambiguous characters like O,0,l,|,I...)\n3) All characters\n> ";
        std::cin >> typePassword;
        std::cout << '\n';

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            invalidOption();
        }
        else if (typePassword != 1 && typePassword != 2 && typePassword != 3)
        {
            ignoreLine();
            invalidOption();
        }
        else
        {
            ignoreLine();
            return typePassword;
        }
    }
}

// Generate random characters for password
char GenRand(int typePassword, std::mt19937& mt)
{
    switch (typePassword)
    {
        // If user enter 1, then avoid numbers and special characters, so that it is easy to spell
        case 1:
        {
            constexpr char onlyAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
            std::uniform_int_distribution<> number{ 0 , 51 };
            return onlyAlphabet[number(mt)];
        }
        // If user enter 2, then avoid ambiguous characters like O,0,l,|,I...
        case 2:
        {
            constexpr char easy2read[] = "23456789" "@#$%^&*" "ABCDEFGHJKLMNPQRSTUVWXYZ" "abcdefghijkmnopqrstuvwxyz";
            std::uniform_int_distribution<> number{ 0 , 65 };
            return easy2read[number(mt)];
        }
        // If user enter 3, then pick all characters
        case 3:
        {
            constexpr char allCharacters[] = "0123456789" "~!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
            std::uniform_int_distribution<> number{ 0 , 71 };
            return allCharacters[number(mt)];
        }
    }
    return 0;
}

// Call GenRand() function and print password
void printPassword(int length, int typePassword, std::mt19937& mt)
{
    for (int count = 0; count < length; count++)
    {
        char character{ GenRand(typePassword, mt) };
        std::cout << character;
    }
    std::cout << '\n';
}

// Execute option 1 (create only one password with the length that the user specified)
void option1()
{
    system("clear");
    int typePassword{ whichOption() };
    int length{ requestLengthPass() };
    system("clear");

    std::mt19937 mt{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };

    std::cout << "\n-> Your Password is: \n";
    std::cout << "--------------------------------------\n";
    printPassword(length, typePassword, mt);
    std::cout << "--------------------------------------\n";
}

// Execute option 2 (create multiple passwords with the length that the user specified)
void option2()
{
    system("clear");
    int howmany{ requestNumofPass() };
    int typePassword{ whichOption() };
    int length{ requestLengthPass() };
    system("clear");

    std::mt19937 mt{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };

    std::cout << "\n-> Your Passwords are: \n" << '\n';
    std::cout << "--------------------------------------\n";
    for (int count = 0; count < howmany; count++)
    {
        printPassword(length, typePassword, mt);
    }
    std::cout << "--------------------------------------\n";
}

int main()
{
    system("clear");
    std::cout << "-----------------------------------------\nThis tool creates strong passwords\n-----------------------------------------|by p4nujr|\n\n";
    int option{ presentationOptions() };

    switch (option)
    {
        case 1:
        {
            option1();
            break;
        }

        case 2:
        {
            option2();
            break;
        }

        case 3:
        {
            std::cout << "Exiting...\n";
            system("exit");
        }
    }
    getchar();

    return 0;
}
