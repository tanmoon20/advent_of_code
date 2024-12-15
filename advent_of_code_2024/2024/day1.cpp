#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void insertAndSortAscending(const int insertNum, std::vector<int>& vector)
{
	if (vector.empty())
	{
		// add to vector if empty
		vector.push_back(insertNum);
		return;
	}
	else
	{
		for (auto it = vector.cbegin(); it != vector.cend(); it++)
		{
			// if less than current value
			// if less than first element, insert to the begin of vector
			// else insert before the pos
			if (insertNum < *it)
			{
				if (it == vector.cbegin())
				{
					vector.insert(it, insertNum);
					return;
				}

				vector.insert(it, insertNum);
				return;
			}
		}
		// insert at the end pos if no less than any value
		vector.push_back(insertNum);
	}
}

int getTotalDistanceDifferent(const std::vector<int>& left, const std::vector<int>& right)
{
	int difference = 0;
	// loop two vector together
	auto leftIt = left.cbegin();
	for (auto rightIt = right.cbegin(); rightIt != right.cend(); leftIt++, rightIt++)
	{
		difference += abs(*rightIt - *leftIt);
	}
	return difference;
}


int getSimilarityScore(const std::vector<int>& left, const std::vector<int>& right)
{	int score = 0;
	int similarityScore = 0;
	int sameNumCount = 0;
	auto rightIt = right.cbegin();
	//auto leftIt = left.cbegin();


	for (auto leftIt = left.cbegin(); leftIt != left.cend(); leftIt++)
	{
		//if left > right, right move to next value
		while (*leftIt > *rightIt)
		{
			if (rightIt + 1 != right.cend())
			{
				*rightIt++;
			}
			else
			{
				//break if right reach the end
				break;
			}
		}

		//if left < right, then continue
		if (*leftIt < *rightIt)
		{
			continue;
		}

		//if left = right
		while (*leftIt == *rightIt)
		{
			sameNumCount++;
			if (rightIt + 1 != right.cend())
			{
				*rightIt++;
			}
		}

		//if value match,
		//check if the next left value same with current left value, yes then add to score 
		//no then set sameNumCount to 0
		if (sameNumCount != 0)
		{
			similarityScore += *leftIt * sameNumCount;

			while (leftIt + 1 != left.cend())
			{
				if (*leftIt == *(leftIt + 1))
				{
					similarityScore += *leftIt * sameNumCount;
					*leftIt++;
				}
				else
				{
					break;
				}
			}
			sameNumCount = 0;
		}
	}

	return similarityScore;
}

void part2()
{
	std::vector<int> left;
	std::vector<int> right;
	//inFile.open("..\\input\\day1Input.txt");
	//inFile.open(R"(C:\Users\USER\Documents\adventOfCode\2024\advent_of_code_2024\input\day1Input.txt)");
	std::ifstream inFile("..\\input\\day1Input.txt");
	std::string input;
	while (inFile >> input)
	{
		insertAndSortAscending(std::stoi(input), left);
		inFile >> input;
		insertAndSortAscending(std::stoi(input), right);
	}

	std::cout << "similarity score: " << getSimilarityScore(left, right) << std::endl;
}

void part1()
{
	std::vector<int> left;
	std::vector<int> right;
	//inFile.open("..\\input\\day1Input.txt");
	//inFile.open(R"(C:\Users\USER\Documents\adventOfCode\2024\advent_of_code_2024\input\day1Input.txt)");
	std::ifstream inFile("..\\input\\day1Input.txt");
	std::string input;
	while (inFile >> input)
	{
		insertAndSortAscending(std::stoi(input), left);
			
		inFile >> input;
		insertAndSortAscending(std::stoi(input), right);
	}
	std::cout << "total difference: " << getTotalDistanceDifferent(left, right) << std::endl;
}


int main()
{
	//part1();
	part2();
	return 0;
}