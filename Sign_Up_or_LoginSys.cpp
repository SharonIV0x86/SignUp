#include <iostream>
#include <string>
// A sign up or login system with human verification created in C++
void inline clear_screen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

class Login
{
private:
    std::string PIN_main;
    std::string PASSWORD_main;
    std::string NAME[10];
    std::string pin_change_array[10], password_change_array[10];

public:
    void check_CREDENTIALS()
    {
        clear_screen();
        std::string name, password, pin;
        do
        {
            clear_screen();
            std::cout << "\n\n\tEnter your name: " << std::endl;
            std::getline(std::cin, name);
            check_for_empty_input(name);
            std::cout << "\n\n\tEnter your pin: " << std::endl;
            std::getline(std::cin, pin);
            check_for_empty_input(pin);
            std::cout << "\n\n\tEnter your password: " << std::endl;
            std::getline(std::cin, password);
            check_for_empty_input(password);
            std::cout << "\n\n\tPLEASE WAIT WHILE CREDENTIALS ARE BEING VERIFIED!" << std::endl;
            if (name != NAME[1] || password != password_change_array[1] || pin != pin_change_array[1])
            {
                clear_screen();
                std::cout << "\n\n\tWRONG CREDENTIALS PRESS ANY KEY TO LOGIN AGAIN! " << std::endl;
                std::cin.ignore();
                check_CREDENTIALS();
            }
        } while (name != NAME[1] || password != password_change_array[1] || pin != pin_change_array[1]);
        clear_screen();
        std::cout << "\n\n\tWELCOME!!" << NAME[1] << std::endl;
        std::cout << "\n\n\tLOGIN SUCCESS! " << std::endl;
        exit(EXIT_SUCCESS);
    }
    void inline check_for_empty_input(std::string field)
    {
        if (field.empty())
        {
            clear_screen();
            std::cout << "\n\n\tTHESE FIELD CANNOT BE EMPTY!! PLEASE ENTER YOUR DESIRED INFO" << std::endl;
            take_CREDENTIALS();
        }
    }

    void take_CREDENTIALS()
    {

        std::cout << "\n\n\tENTER YOUR CREDENTIALS TO CREATE A ACCOUNT AND THEN LOGIN" << std::endl;
        std::cout << "\n\n\tEnter Your name: " << std::endl;
        std::getline(std::cin, NAME[1]);
        check_for_empty_input(NAME[1]);
        std::cout << "\n\n\tEnter Your PIN: " << std::endl;
        std::getline(std::cin, pin_change_array[1]);
        check_for_empty_input(pin_change_array[1]);
        int pin = std::stoi(pin_change_array[1]);
        std::cout << "\n\n\tEnter Your Password: " << std::endl;
        std::getline(std::cin, password_change_array[1]);
        check_for_empty_input(password_change_array[1]);
        std::cout << "\n\n\tRemember the credentials!" << std::endl;
        std::cout << "\n\n\tPress any key to move to login screen" << std::endl;
        std::cin.ignore();
        check_CREDENTIALS();
    }
    void Human_Verification()
    {
        // clear_screen();
        std::string alphabets_uppercase = "ABCDEFGHIJKLMNOPQRS12345678abcdefghijklmnopqrstuvwxyz910TUVWXYZ";
        int random_number_for_string = (rand() % 58);
        int random_number = rand() % 9999;
        std::string verify = std::to_string(random_number) + alphabets_uppercase[random_number_for_string] + alphabets_uppercase[random_number_for_string] + alphabets_uppercase[random_number_for_string] + std::to_string(random_number);
        std::string input;
        std::cout << "\n\t\t|--------------------------------------------|"
                  << "\n\t\t|                                            |"
                  << "\n\t\t|VERIFICATION NUMBER----->" << verify << "\t     |"
                  << "\n\t\t|Enter the number on screen for verification:|"
                  << "\n\t\t|--------------------------------------------|" << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~>";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "\n\n\tBAD_INPUT_ retry! the verification field cannot be empty!!" << std::endl;
            Human_Verification();
        }
        while (input != verify)
        {
            std::cout << "\n\n\tWRONG VERIFICATION PLEASE TRY AGAIN!" << std::endl;
            Human_Verification();
        }
        std::cout << "\n\n\tVERIFICATION SUCCESS!" << std::endl;
        take_CREDENTIALS();
    }
};
int main()
{
    Login Sessiob1b;
    Sessiob1b.Human_Verification();

    return 0;
}
