#include <string>
#include <fstream>
#include <iostream>

#include "../includes/const.h"
#include "../includes/parser.h"


//
std::string parseCode(std::string line)
{
	std::string allCodes = "";

	for (char character : line)
	{
		if (character == BF_COMMENT)
		{
			break;
		}

		if (character != ' ')
		{
			allCodes += character;
		}

	}

	return allCodes;
}


//
std::string parseFile(std::string fileName)
{
	std::ifstream file(fileName);
		
	std::string allCodes = "";

	if (file.is_open())
	{
		std::string line;
		
		while (std::getline(file, line))
		{
			allCodes += parseCode(line);
		}

		file.close();
	} 
	
	else 
		std::cerr << "Error opening file!\n";

	return allCodes;
}
