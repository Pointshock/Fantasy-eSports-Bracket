#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>





//void DisplayArray(int sizeOfmatchup, int  matchup[4]);

int main() {
	// prototypes variables and place holders
	std::string quarterWinner;
	std::string semiWinner;
	std::string finalWinner;
	int min = 50;
	int max = 120;
	int teamOne, teamTwo;
	int semiJ = 0;
	int finalJ = 0;



	//Title
	std::cout << ("\n\n\t ***** Esports Fantasy March Madness ***** \n\n\n");

	std::cout << "\n Ladies and Gentleman, boys and girls welcome to the 2021 E-sports March Madess tournament!";
	std::cout << "\n My name is Tony Hinton and I will be casting these amazing games in this tournament!";
	std::cout << "\n Now to explain the rules! You as a spectator will vote on the presented bracket and ";
	std::cout << "\n watch as the teams you vote for duke it out to see who is the greatest of all time!";
	std::cout << "\n Now lets meet the teams!";

	std::cout << "\n";

	//Teams
	std::string teams[8] = { "MarioBrothers","WiiSports", "Lakers", "Overwatch", "Scions", "VaultHunters", "FalloutRaiders", "PhantomThieves" };
	std::string semiTeams[4];
	std::string finalTeams[2];
	//int matchup[8] = { 1, 1, 2, 2, 3, 3, 4, 4 };
	//prints out the teams

	int sizeOfmatchup = sizeof(teams) / sizeof(teams[8]);
	// List of the teams
	for (int i = 0; i <= 7; i++)
	{
		std::cout << "\n " << i + 1 << ".)  Team " << teams[i];
	}

	srand(time(0));
	// To ensure the seed is not the same every time we use srand
	std::cout << "\n";

	std::cout << "\n  Now lets shuffle up the bracket and see which team is facing who!";

	std::cout << "\n";
	//Shuffles around the array
	std::random_shuffle(std::begin(teams), std::end(teams));

	for (int i = 0; i <= 7; i = i + 2)
	{
		std::cout << "\n Round " << i / 2 + 1 << " " << teams[i] << " VS " << teams[i + 1];
	}

	std::cout << "\n";

	int score = 0;
	//quarter finals
	for (int i = 0; i <= 6; i = i + 2) {
		std::cout << "\n\n Cast your votes! All fantasy voters good luck! " << teams[i] << " or " << teams[i + 1] << "\n";
		// Random Generators create the score and decide which team is the winner
		teamOne = rand() % max + min;
		teamTwo = rand() % max + min;
		if (teamOne > teamTwo) {
			quarterWinner = teams[0 + i];
		}
		else if (teamTwo > teamOne) {
			quarterWinner = teams[1 + i];
		}
		// In case a team ties we add one to teamOne
		else {
			teamOne = teamOne + 1;
		}


		std::string userGuess;
		//Gets the guess from the user
		std::cin >> userGuess;
		//Tells the user what they guessed
		std::cout << '\a';

		std::cout << "\n\n Your guess was " << userGuess << std::endl;

		std::cout << "\n\n The score was \n\n " << teams[i] << ": " << teamOne << "\n " << teams[i + 1] << ": " << teamTwo << std::endl;
		std::cout << "\n\n " << quarterWinner << " are the winners!";

		if (userGuess == quarterWinner)
		{
			std::cout << "\n\n\t *** Congratulations! Your guess was correct! ***\n\n";
			score = score + 1;
		}
		else
		{
			std::cout << "\n\n\t *** Sorry! You guessed wrong.\n";
		}
		//This adds the winning team into another array which is used in the semi finals
		semiTeams[semiJ] = quarterWinner;
		semiJ++;
	}

	//semi finals

	std::cout << "\n\n It is now time for the Semi Finals, each of these teams have clawed their way to this point!";
	std::cout << "\n\n But the competition isn't over just yet! Lets watch and see these last few games of the 2021 E-Sports March Madness Tournament!";
	std::cout << "\n\n These are your qualifying teams! ";

	for (int i = 0; i <= 3; i = i + 2)
	{
		std::cout << "\n Round " << i / 2 + 1 << " " << semiTeams[i] << " VS " << semiTeams[i + 1];
	}

	for (int i = 0; i <= 3; i = i + 2) {
		std::cout << "\n\n Which team do you think will win the matchup? " << semiTeams[i] << " or " << semiTeams[i + 1] << "\n";
		// Random Numbers generate the teams scores and compare them to find out who wins
		teamOne = rand() % max + min;
		teamTwo = rand() % max + min;
		if (teamOne > teamTwo) {
			semiWinner = semiTeams[0 + i];
		}
		else if (teamTwo > teamOne) {
			semiWinner = semiTeams[1 + i];
		}
		// Just in case a team ties we have an else statement
		else {
			teamOne = teamOne + 1;
		}

		std::string userGuess;
		//Gets the guess from the user
		std::cin >> userGuess;
		//Tells the user what they guessed
		std::cout << '\a';

		std::cout << "\n\n Your guess was " << userGuess << std::endl;

		std::cout << "\n\n The score was \n\n" << semiTeams[i] << ": " << teamOne << "\n" << semiTeams[i + 1] << ": " << teamTwo << std::endl;
		std::cout << "\n\n" << semiWinner << " are the winners!";

		if (userGuess == semiWinner)
		{
			std::cout << "\n\n\t *** Congratulations! Your guess was correct! ***\n\n";
			// score is plus 2 because its the semi finals
			score = score + 2;
		}
		else
		{
			std::cout << "\n\n\t *** Sorry! You guessed wrong.\n";
		}
		//This adds the winning team into another array which is used in the semi finals
		finalTeams[finalJ] = semiWinner;
		finalJ++;
	}

	//finals!

	std::cout << "\n\n And now for the grand event! The finale of the 2021 E-Sports March Madness tournament!";
	std::cout << "\n\n These teams are the best of the best who have fought their way to the top! ";
	std::cout << "\n\n Let's show both these teams some respect as they enter the arena! ";
	std::cout << "\n\n The two final teams are ";

	for (int i = 0; i <= 1; i++)
	{
		std::cout << "\n" << i + 1 << ".)  Team " << finalTeams[i];
	}

	std::cout << "\n\n Which team do you think will win the championship? " << finalTeams[0] << " or " << finalTeams[1] << "\n";
	// Random generate to get scores
	teamOne = rand() % max + min;
	teamTwo = rand() % max + min;
	if (teamOne > teamTwo) {
		finalWinner = finalTeams[0];
	}
	else if (teamTwo > teamOne) {
		finalWinner = finalTeams[1];
	}
	else {
		teamOne = teamOne + 1;
	}

	std::string userGuess;
	//Gets the guess from the user
	std::cin >> userGuess;
	//Tells the user what they guessed

	std::cout << '\a';

	std::cout << "\n\n Your guess was " << userGuess << std::endl;

	std::cout << "\n\n The score was \n\n" << finalTeams[0] << ": " << teamOne << "\n" << finalTeams[1] << ": " << teamTwo << std::endl;
	std::cout << "\n\n" << finalWinner << " are the chamionship winners!!!";

	if (userGuess == finalWinner)
	{
		std::cout << "\n\n\t *** Congratulations! Your guess was correct! ***\n\n";
		score = score + 3;
	}
	else
	{
		std::cout << "\n\n\t *** Sorry! You guessed wrong.\n";
	}
	// Show user what they scored at the end!
	std::cout << "\n\n What an amazing match! A wonderful thing to watch! ";
	std::cout << "\n\n Now lets tally up the fantasy voters! Lets see where you stand! ";
	std::cout << "\n\n Your final score was " << score << " Congragulations! Make sure you come back next year!";
	std::cout << "\n\n Thank you all for watching and playing! This is Tony Hinton signing out! ";



	return 0;
}