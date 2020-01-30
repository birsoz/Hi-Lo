//Hi-Lo v3
//#include "stdafx.h"
#include <random> // for std::random_device and std::mt19937
#include <iostream>
#include <cstdlib> // for rand() and srand() and exit()
#include <ctime> // for time()

int getRandomNumber(int min, int max)
{
	//std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock// was creating linear numbers.

	static const double fraction = (1.0 / (RAND_MAX + 1.0));  // static used for efficiency, so we only calculate this value once

	return (min + static_cast<int>((max - min + 1) * (std::rand() * fraction)));// evenly distribute the random number across our range
}//all good
struct Settings
{
	int min;
	int max;
	int tries;
	int newRandNum;

};//all good
Settings getSettings() {
	int x, y, z;
	std::cout << "Here are the settings \n";

	while (true) {
		std::cout << "Smallest number to guess: ";
		std::cin >> x;
		if (std::cin.fail())
		{
			std::cout << "Come on dude!\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');

		}
		else break;
	} while (true) {
		std::cout << "Highest number to guess: ";
		std::cin >> y;
		if (y == x || std::cin.fail())
		{
			std::cout << "Come on dude!\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');

		}
		else break;
	}while (true) {
		std::cout << "Numbers of tries: ";
		std::cin >> z;

		if (z == 0 || std::cin.fail())
		{
			std::cout << "Come on dude!\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');

		}
		else break;
	}
	int t = getRandomNumber(x, y);
	return{ x,y,z,t};
}//all good
void mainMenu(Settings &setting, int x) {

	while (true)
	{
		std::cout << "Enter \n's' for settings, \n'c' to continue with default or current settings, \n'd' to cheat, \n'e' to exit \n<s,c,d or e> : ";
		char choice;
		std::cin >> choice;
		std::cin.ignore(32767, '\n');
		switch (choice)
		{
		case 'c':
			return;
		case 's':
			setting = getSettings();
			return;

		case 'e':
			exit(0);
		case 'd':
			std::cout << x << '\n';
			break;
		default:
			std::cout << "Come on dude!\n";

		}
	};
}//all good
int getGuess(Settings setting, int remainingTries)
{
	int guess;
	while (true)
	{
		std::cout << "Guess please in between<" << setting.min << " - " << setting.max << ">,you have " << remainingTries << " numbers of guesses: ";
		std::cin >> guess;
		if (std::cin.fail())
		{
			std::cout << "Come on dude!\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			remainingTries--;
		}
		return guess;
	};


}
void checkGuess(Settings setting, int x) {
	int remainingTries = setting.tries;
	do
	{

		int guess = getGuess(setting, remainingTries);
		if (x == guess) {
			std::cout << "\nGot it dude, good job\n\n";
			break;
		}
		else if (x > guess)std::cout << "Go higher dude\n";
		else if (x < guess)std::cout << "Go lower dude\n";
		remainingTries--;
	} while (remainingTries>0);
	if (remainingTries == 0)std::cout << "You lost, sorry.\nThe number was: " << x << '\n' << '\n';
}
int main()
{
	//std::cout << "RAND_MAX" << RAND_MAX << "\nrand()" << rand();
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();//Disgarding the first result
	std::rand();
	Settings setting{ 1,100,7 };//default values for the settings
	std::cout << "Hey there. Thank you for trying me.\nHere is the thing, I am gonna pick a number and you are gonna try to guess it.\nSounds good? So Let's get started!\n\n";
	int myRandNum = getRandomNumber(setting.min, setting.max);//getting the random number to be guessed
	while (true)
	{
		mainMenu(setting, myRandNum);
		myRandNum = getRandomNumber(setting.min, setting.max);//x needs to be changed after settings
															  //mainMenu(setting, myRandNum);
		checkGuess(setting, myRandNum);
	}

	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
	return 0;
}
