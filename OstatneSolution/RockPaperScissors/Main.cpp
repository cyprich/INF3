#include <iostream>

int main()
{
	std::string choices[3] = { "rock", "paper", "scissors" };
	std::string player;
	int playerScore;

	while (true)
	{
		std::cout << "Rock, paper, or scissors?: " << std::endl;
		std::cin >> player;
		std::cout << player << std::endl;
	}


	return 0;
}

