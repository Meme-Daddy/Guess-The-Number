// Guess the number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int guessing();

int main()
{
    system("CLS");
    cout << "Guess the number between 1 and 100" << endl;
    guessing();

    return 0;

}

bool play_again()
{
    string again;
    cout << "Play again? Y/N: ";
    cin >> again;
    // bool alpha_check = isalpha(again[0]);
    bool success = false;


    while (success == false)
    {

        if (again[0] == 'y' || again[0] == 'Y' && again.length() <= 3)
        {
            success = true;
            return true;
        }
        else if (again[0] == 'n' || again[0] == 'N' && again.length() <= 3)
        {
            success = true;
            return false;
        }
        else
        {
            system("CLS");
            cout << "Invalid option. Please enter Y or N: ";
            cin >> again;
            continue;
        }
    }

    return false;

}


int difficulty_text()
{
    string input;
    int tries_remaining = 0;
    bool success = false;
    while (success == false)
    {
        cout << "Type the corrisponding number for Easy Medium Hard" << endl
            << "(1) Easy" << endl
            << "(2) Medium" << endl
            << "(3) Hard" << endl
            << "Enter: ";
        cin >> input;
        if (input == "1" || input == "easy")
        {
            system("CLS");
            tries_remaining = 15;
            cout << "You've selected Easy difficulty" << endl
                << "You have " << tries_remaining << " tries remaining" << endl;
            success = true;
            return tries_remaining;
        }
        else if (input == "2" || input == "medium")
        {
            system("CLS");
            tries_remaining = 10;
            cout << "You've selected Medium difficulty" << endl
                << "You have " << tries_remaining << " tries remaining" << endl;
            success = true;
            return tries_remaining;
        }
        else if (input == "3" || input == "hard")
        {
            system("CLS");
            tries_remaining = 5;
            cout << "You've selected Hard difficulty" << endl
                << "You have " << tries_remaining << " tries remaining" << endl;
            success = true;
            return tries_remaining;
        }
        else
        {
            system("CLS");
            cout << "That is an invalid option. Please select a difficulty shown" << endl;
            continue;

        }
    }

    return tries_remaining;
}

int guessing()
{
    srand(time(0));

    int guess = 0;
    int min = 1;
    int max = 100;
    int cpu_num = rand() % max + min;
    int tries = 0;
    int tries_remaining = difficulty_text();

    do {

        cout << "Enter your guess: ";
        cin >> guess;
        while (cin.fail()) //checks if user input is integer
        {
            cin.clear(); //clears the input buffer
            cin.ignore(512, '\n'); //removes characters from streams
            system("CLS");
            cout << "That is not a valid guess" << endl;
            cout << "Enter your guess: ";
            cin >> guess;
        }
        if (guess == cpu_num)
        {
            tries_remaining--;
            tries++;
            system("CLS");
            cout << "You did it! It only took you " << tries << " tries" << endl;
            tries = 0;
            if (play_again() == true)
            {
                main();
            }
            else
            {
                system("CLS");
                
                return 0;
            }
        }
        else if (guess < cpu_num)
        {
            tries_remaining--;
            tries++;
            system("CLS");
            cout << "Your guess is too low. Try again" << endl
                << tries_remaining << " tries remaining" << endl;
        }
        else if (guess > cpu_num)
        {
            tries_remaining--;
            tries++;
            system("CLS");
            cout << "Your guess is too high. Try again" << endl
                << tries_remaining << " tries remaining" << endl;
        }
        if (tries_remaining == 0)
        {
            cout << "You lost" << endl
                << "The number was " << cpu_num << endl;
            tries = 0;
            if (play_again() == true)
            {
                main();
            }
            else
            {
                system("CLS");
               
                return 0;
            }
        }
    } while (tries_remaining > 0);
    return 0;
}

