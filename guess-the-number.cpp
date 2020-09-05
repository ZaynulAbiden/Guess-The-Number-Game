#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std;

char playerNames[10][20]; int topScores[10];				//top 10 scores and names
														
void updateScoreBoard(string name, int score)
{
	for (int i = 0; i < 10; i++)
		if (score > topScores[i])
		{
			for (int j = 9; j != i - 1; j--)
			{
				topScores[j] = topScores[j - 1];
				int k = 0;
				while (playerNames[j - 1][k] != '\0')
				{
					playerNames[j][k] = playerNames[j - 1][k];
					k++;
				}playerNames[j][k] = '\0';
			}
			topScores[i] = score;
			int k = 0;
			while (name[k] != '\0')
			{
				playerNames[i][k] = name[k];
				k++;
			}playerNames[i][k] = '\0';
			break;
		}
}
void playGame(string name)
{
	char input;
	do {
		int chances = 5, number, guess, score = 25; bool isCorrect = 0;
		system("cls");
		cout << "Hey " << name << ", I picked a number between 0 to 100.\nYou must try to guess the number in " << chances << " chances. OK?" << endl;
		system("pause"); system("cls");
		number = rand() % 100;
		cout << "What is your guess? "; cin >> guess;
		while (guess < 0 || guess>100)
		{
			cout << "Select between 0 to 100 :";
			cin >> guess;
		}
		while (0 < chances)
		{
			chances--;
			if (guess == number)
			{
				isCorrect = 1; 
				break;
			}
			else if(chances > 0)
			{
				score = score - 5;
				if (guess < number)
					cout << guess << " is low. Try a higher number.\nYou have " << chances << " chances left.\n";
				else if (guess > number)
					cout << guess << " is high. Try a lower number.\nYou have " << chances << " chances left.\n";
				cout << "What is your guess? "; cin >> guess;
			}
		}
		if (isCorrect==1)
		{
			cout << "Congratulations " << name << "!!! " << guess << " is correct.Your score is " << score << endl;
			updateScoreBoard(name, score);
		}
		else
			cout << "Sorry, you have " << chances << " chances left. Correct number was " << number << "." << endl;
		do {
			cout << "Do you want to play again? <y/n> "; cin >> input;
		} while (input != 'y' && input != 'n' && input != 'Y' && input != 'N');		//asking to play again
		if (input == 'y' || input == 'Y')
		{
			cout << "Enter your name : "; cin >> name;
		}
	} while (input == 'y' || input == 'Y');	//restarting or exit game
	system("cls");
}	
void DisplayScoreboard()
{	
	int i = 0, j = 0;
	if (playerNames[i][j]=='\0')
	{
		cout << "\n\t\t\tTHERE ARE NO SCORES SUBMITTED YET!!!!"<< endl;
	}
	else
	{
		cout << "\t\t  __________________________________________________ " << endl;
		cout << "\t\t (|                                                |)" << endl;
		cout << "\t\t     RANK" << setw(20) << "NAME" << setw(20) << "SCORE"<< endl;
		cout << "\t\t (|________________________________________________|)" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout <<setw(24)<< i+1 << setw(20) << playerNames[i] << setw(20) << topScores[i] << endl;
		}
	}
}
int main()
{
	string name;int input;
	cout << "\t\t-----------------------------------------------------" << endl;
	cout << "\t\t*****************************************************" << endl;
	cout << "\t\t***             GUESS MY NUMBER GAME              ***" << endl;
	cout << "\t\t*****************************************************" << endl;
	cout << "\t\t               Enter your name : "; cin >> name;
	cout << "\t\t***         WELCOME TO MY FIRST C++ GAME          ***" << endl;
	cout << "\t\t-----------------------------------------------------" << endl;
	cout << "\t\t*****************************************************" << endl;
	do {
	cout << "\t\t-----------------------------------------------------" << endl;
	cout << "\t\t           SELECT AN OPTION FROM THE MENU" << endl;
	cout << "\t\t           ||||||||||||||||||||||||||||||" << endl;
	cout << "\t\t     (1) Play Game (2) Check Scoreboard (3) Exit" << endl << endl;
	cout << "\t\t-----------------------------------------------------" << endl;
		do {
	cout << "\n\t\t             Enter your choice (1,2,3):"; cin >> input;
		} while (input != 1 && input != 2 && input != 3);					//selection from menu

		switch (input)
		{
		case 1: {playGame(name); break; }
		case 2: {DisplayScoreboard(); break; }
		case 3: {cout << "\n\t\t\t\tTHANKS FOR PLAYING " << name << "\n\t\t\t\tAPPLICATION IS EXITING..." << endl; exit(0); }
		}
	} while (input != 3);
}
