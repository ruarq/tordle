#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>

auto LoadWords(const std::string &filename) -> std::vector<std::string>
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		return {};
	}

	std::vector<std::string> words;
	std::string word;
	while (std::getline(file, word))
	{
		words.push_back(word);
	}

	return words;
}

auto Input(const std::string &str = "") -> std::string
{
	std::cout << str;
	
	std::string buf;
	std::getline(std::cin, buf);

	return buf;
}

auto main() -> int
{
	std::srand(std::time(nullptr));

	const auto solutions = LoadWords("data/solutions");
	const auto words = LoadWords("data/words");

	const auto solution_pos = std::rand() % solutions.size();
	const auto solution = solutions.at(solution_pos);

	std::string guess;
	bool user_won = false;
	for (int i = 0; i < 6; ++i)
	{
		bool guess_again;
		do
		{
			guess_again = false;
			guess = Input(std::to_string(i + 1) + " ");

			if (guess.size() != 5)
			{
				std::cout << "Word has to be 5 characters long\n";
				guess_again = true;
			}
			else if (std::find(words.begin(), words.end(), guess) == words.end())
			{
				std::cout << "Not a valid word!\n";
				guess_again = true;
			}
		}
		while (guess_again);

		std::cout << "  ";
		for (size_t g = 0; g < guess.size(); ++g)
		{
			bool is_correct = false;
			bool is_correct_pos = false;

			for (size_t s = 0; s < solution.size(); ++s)
			{
				if (guess[g] == solution[s])
				{
					is_correct = true;

					if (g == s)
					{
						is_correct_pos = true;
					}
				}
			}

			if (is_correct && is_correct_pos)
			{
				std::cout << "\33[30m\33[4m\33[42m" << guess[g] << "\33[0m";
			}
			else if (is_correct)
			{
				std::cout << "\33[30m\33[43m" << guess[g] << "\33[0m";
			}
			else
			{
				std::cout << ".";
			}
		}
		std::cout << "\n";

		if (guess == solution)
		{
			user_won = true;
			break;
		}
	}

	if (user_won)
	{
		std::cout << "You win!\n";
	}
	else
	{
		std::cout << "You loose!\n";
	}

	std::cout << "The solution was: " << solution << "\n";

	return 0;
}
