#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> //replace

int main()
{
	// TEAMS DATA
	std::ifstream input("result.csv");
	if (!input.is_open()) { std::cout << "Error: File Not Open" << std::endl; }
	std::string year;
	std::string title;
	std::string teamName;
	std::string city;
	std::string goalsAgainst;
	std::string numberOfDraws;
	std::string goalsScored;
	std::string goalDiffernece;
	std::string numberOfLosses;
	std::string numGamesPlayed;
	std::string position;
	std::string points;
	std::string numberOfWins;
	int count = 0;

	std::ofstream outputFile;
	outputFile.open("teamsIntermediate.txt");

	std::string insertBegin = "INSERT INTO Teams ([TeamId], [team], [city], [number_of_wins], [number_of_losses], [number_of_draws], [goals_for], [goals_against], [position]) VALUES ("; //1234, N'test', N'odessa', 1, 1, 1, 1, 1, 1)";
	//std::string insertBegin2 = "INSERT INTO Teams"
	while (input.good()) {
		if (count > 20) { break; }//20
		getline(input, year, ',');
		//if (year != "2016/2017") { break; }
		getline(input, title, ',');
		getline(input, teamName, ',');
		//getline(input, city, ',');
		getline(input, goalsAgainst, ',');
		getline(input, numberOfDraws, ',');
		getline(input, goalsScored, ',');
		//getline(input, goalDiffernece, ',');
		getline(input, numberOfLosses, ',');
		getline(input, numGamesPlayed, ',');
		getline(input, position, ',');
		getline(input, points, ',');
		getline(input, numberOfWins, '\n');
		if (count == 0) { count++; continue; }
		
		//For Debugging
		//std::cout << "year: " << year << std::endl;
		/*if (count <= 2) {
			std::cout << "year: " << year << std::endl;
			std::cout << "title: " << title << std::endl;
			std::cout << "team: " << teamName << std::endl;
			std::cout << "city: " << city << std::endl;
			std::cout << "goalsAgainst: " << goalsAgainst << std::endl;
			std::cout << "number of draws: " << numberOfDraws << std::endl;
			//
			std::cout << "goals scored: " << goalsScored << std::endl;
			std::cout << "goalDifference: " << goalDiffernece << std::endl;
			std::cout << "number losses: " << numberOfLosses << std::endl;
			std::cout << "numGamesPlayed: " << numGamesPlayed << std::endl;
			std::cout << "position: " << position << std::endl;
			std::cout << "points: " << points << std::endl;
			std::cout << "number of wins: " << numberOfWins << std::endl;
		}*/
		std::string insertFull = insertBegin + std::to_string(count) +", N'" + teamName + "', N'" + "city" + "', " + numberOfWins + ", " + numberOfLosses + ", " + numberOfDraws + ", " + goalsScored + ", " + goalsAgainst + ", " + position + ")";

		//Debugging
		//if (count == 2) { std::cout << insertFull << std::endl; }

		outputFile << insertFull << std::endl;

		count++;
	}
	outputFile.close();
	
	// PLAYERS DATA

	std::string insertBegin2 = "INSERT INTO Players([PlayerId], [name], [nation], [position], [team], [age], [matches_played], [goals], [assists], [red_cards], [yellow_cards]) VALUES(";

	std::string id;
	std::string name;
	std::string nation;
	std::string position2;
	std::string team;
	std::string age;
	std::string matches_played;
	std::string goals;
	std::string assists;
	std::string yellow_cards;
	std::string red_cards;
	
	std::string ignore;

	std::ifstream input2("players.csv");
	if (!input2.is_open()) { std::cout << "Error: File Not Open" << std::endl; }
	std::ofstream outputFile2;
	outputFile2.open("playersIntermediate.txt");


	while (input2.good()) {
		getline(input2, id, ',');
		getline(input2, ignore, '\\');
		getline(input2, name, ',');
		std::replace(name.begin(), name.end(), '-', ' ');
		getline(input2, ignore, ' ');
		getline(input2, nation, ',');
		getline(input2, position2, ',');
		getline(input2, team, ',');
		getline(input2, matches_played, ',');
		getline(input2, goals, ',');
		getline(input2, assists, ',');
		getline(input2, yellow_cards, ',');
		getline(input2, red_cards, '\n');
		
		std::string insertFull2 = insertBegin2 + id + ", N'" + name + "', N'" + nation + "', N'" + position2 + "', N'" + team + "'" + age + ", " + matches_played + ", " + goals + ", " + assists + ", " + red_cards + ", " + yellow_cards + ")";
		outputFile2 << insertFull2 << std::endl;
	}

	// COACHES DATA

	std::string id3;
	std::string name3;
	std::string team3;
	std::string nation3;

	std::ifstream input3("coaches.csv");
	if (!input3.is_open()) { std::cout << "Error: File Not Open" << std::endl; }
	std::ofstream outputFile3;
	outputFile3.open("CoachesIntermediate.txt");
	std::string insertBegin3 = "INSERT INTO [dbo].[Coaches] ([Id], [name], [team], [nation]) VALUES (";

	while (input3.good()) {
		getline(input3, id3, ',');
		getline(input3, name3, ',');
		getline(input3, team3, ',');
		getline(input3, nation3, '\n');
		std::string insertFull3 = insertBegin3 + id3 + ", N'" + name3 + "', N'" + team3 + "', N'" + nation3 + "')";
		outputFile3 << insertFull3 << std::endl;
		//std::cout << insertFull3 << std::endl;
	}
}
