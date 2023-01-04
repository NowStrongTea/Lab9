#include <iostream>
#include <windows.h>
#include <fstream>

// The function implements the game "Guess the number"
void guessTheNumber(int n, int k)
{
	//==================================================
	// Opening a file for writing logs
	std::ofstream outputFile("LogFile.txt");
	//==================================================
	// We declare the structure "System time"
	SYSTEMTIME lt;
	GetLocalTime(&lt); // Get local time
	//==================================================
	// The computer generates a random number and asks the user to guess it
	int tmp = 0;
	srand(time(NULL)); // Key for randomizer
	int randomNumber = rand() % n + 1; // Assign a variable a random number from 1 to n inclusive
	//============Writing data to a log file============
	if (outputFile.is_open())
	{
		GetLocalTime(&lt); // Get local time
		outputFile << "==================================================\n";
		outputFile << '[' << lt.wDay << '.' << lt.wMonth << '.' << lt.wYear << "][" << lt.wHour << ':' << lt.wMinute << "]\n";
		outputFile << "The computer guesses a number from 1 to " << n << ". Number of attempts to guess it " << k;
		outputFile << "\nThe computer thinks of a number: " << randomNumber << '\n';
	}
	//==================================================
	for (int i = 0; i < k; i++)
	{
		std::cout << "Enter the number: ";
		std::cin >> tmp;
		//============Writing data to a log file============
		if (outputFile.is_open())
		{
			GetLocalTime(&lt); // Get local time
			outputFile << '[' << lt.wDay << '.' << lt.wMonth << '.' << lt.wYear << "][" << lt.wHour << ':' << lt.wMinute << "]\n";
			outputFile << "User has " << i + 1 << " attempt out of " << k << '\n';
			outputFile << "The user enters a number: " << tmp << '\n';
		}
		//==================================================
		if (tmp == randomNumber)
		{
			//============Writing data to a log file============
			if (outputFile.is_open())
			{
				GetLocalTime(&lt); // Get local time
				outputFile << '[' << lt.wDay << '.' << lt.wMonth << '.' << lt.wYear << "][" << lt.wHour << ':' << lt.wMinute << "]\n";
				outputFile << tmp  << " == " << randomNumber << '\n';
				outputFile << "The user guessed the number. User won!!!\n";
				outputFile << "==================================================\n";
				outputFile.close();
			}
			//==================================================
			std::cout << "You guessed the number. You won!!!\n";
			return;
		}
		else if (i == k - 1 && tmp != randomNumber)
			continue;
		else if (tmp < randomNumber)
		{
			//============Writing data to a log file============
			if (outputFile.is_open())
			{
				GetLocalTime(&lt); // Get local time
				outputFile << '[' << lt.wDay << '.' << lt.wMonth << '.' << lt.wYear << "][" << lt.wHour << ':' << lt.wMinute << "]\n";
				outputFile << "The computer tells the user that the guessed number is greater than the user entered\n";
				outputFile << tmp << " < " << randomNumber << '\n';
			}
			//==================================================
			std::cout << "The guessed number is greater than the entered one\n";
		}
		else if (tmp > randomNumber)
		{
			//============Writing data to a log file============
			if (outputFile.is_open())
			{
				GetLocalTime(&lt); // Get local time
				outputFile << '[' << lt.wDay << '.' << lt.wMonth << '.' << lt.wYear << "][" << lt.wHour << ':' << lt.wMinute << "]\n";
				outputFile << "The computer tells the user that the guessed number is less than the user entered\n";
				outputFile << tmp << " > " << randomNumber << '\n';
			}
			//==================================================
			std::cout << "The hidden number is less than the entered one\n";
		}
	}
	std::cout << "The attempts are over. You lose\n";
	//============Writing data to a log file============
	if (outputFile.is_open())
	{
		GetLocalTime(&lt); // Get local time
		outputFile << '[' << lt.wDay << '.' << lt.wMonth << '.' << lt.wYear << "][" << lt.wHour << ':' << lt.wMinute << "]\n";
		outputFile << tmp << " != " << randomNumber << '\n';
		outputFile << "The user has run out of attempts. The user did not enter a number. User lost\n";
		outputFile << "==================================================\n";
		outputFile.close();
	}
	//==================================================
}

int main()
{
	int n, k;
	std::cout << "The computer guesses a number from 1 to N. You have k attempts to guess it:\n";
	std::cout << "Enter N: ";
	std::cin >> n;
	std::cout << "Enter k: ";
	std::cin >> k;
	system("cls");
	std::cout << "The computer guesses a number from 1 to " << n << ". You have " << k << " attempts to guess it: \n";
	guessTheNumber(n, k);
	system("pause");
	return 0;
}