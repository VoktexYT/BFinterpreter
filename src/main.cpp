#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <thread>
#include <chrono>

#include "../includes/code.h"
#include "../includes/parser.h"
#include "../includes/const.h"
#include "../includes/compiler.h"


void displayHelp()
{
	std::cout 
		<< "=====================================\n"
		<< "  🧠 bfc++ - Advanced Brainfuck Interpreter  \n"
		<< "=====================================\n\n"

		<< "Usage:\n"
		<< "\tbfc++ <script.bf> [options]\n\n"

		<< "Options:\n"
		<< "\t" << PARAM_DEBUG << "\t Show all steps during compilation\n"
		<< "\t" << PARAM_SIZEM << " <size>\t Set the memory size (default: 10)\n\n"
		<< "\t" << PARAM_HELP << "\t Show the docs\n\n"

		<< "Brainfuck Instructions:\n"
		<< "\t" << BF_PLUS          << "\t Increase value at current memory cell\n"
		<< "\t" << BF_LESS          << "\t Decrease value at current memory cell\n"
		<< "\t" << BF_RIGHT         << "\t Move memory pointer to the right\n"
		<< "\t" << BF_LEFT          << "\t Move memory pointer to the left\n"
		<< "\t" << BF_LOOP_IN       << "\t Start a loop (while current cell != 0)\n"
		<< "\t" << BF_LOOP_OUT      << "\t End of the loop\n"
		<< "\t" << BF_IF_IN         << "\t Start an IF block (if current cell == 0)\n"
		<< "\t" << BF_IF_OUT        << "\t End of the IF block\n"
		<< "\t" << BF_PRINT         << "\t Print ASCII character of current cell\n"
		<< "\t" << BF_PRINT_C       << "\t Print numeric ASCII value of current cell\n"
		<< "\t" << BF_INPUT         << "\t Get a character from user input (stores ASCII)\n"
		<< "\t" << BF_INPUT_I       << "\t Get a number from user input (0-255)\n"
		<< "\t" << BF_COMMENT       << "\t Comment (ignore the entire line)\n"
		<< "\t" << BF_FULL          << "\t Set current cell to max value (255)\n"
		<< "\t" << BF_EMPTY         << "\t Set current cell to min value (0)\n"
		<< "\t" << BF_CHAR_TO_ASCII << "\t Convert char to ASCII and store (/a → 97)\n"
		<< "\t" << BF_VAR           << "\t Store current cell value in a variable\n"
		<< "\t" << BF_VAR_GET       << "\t Set current cell value to stored variable value\n"

		<< "\n=====================================\n";
}



//
void checkSettings(int argc, char* argv[], int& sizeOfMemory, bool& debug)
{
	sizeOfMemory = 10;
	debug = false;

	for (int i = 2; i < argc; i++)
	{
		if (std::strcmp(argv[i], PARAM_SIZEM) == 0 && i + 1 < argc) 
			sizeOfMemory = std::stoi(argv[i + 1]);

		if (std::strcmp(argv[i], PARAM_HELP) == 0)
			displayHelp();

		if (std::strcmp(argv[i], PARAM_DEBUG) == 0) debug = true;
	}
}


void titre() 
{
	std::cout
		<< "  🧠 bfc++ - Advanced Brainfuck Interpreter  \n";
}

//
int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		std::string fileName = argv[1];
		int sizeOfMemory, showTime;
		bool debug = false;
		checkSettings(argc, argv, sizeOfMemory, debug);

		titre();

		std::string allCodes = parseFile(fileName);
		
		compiler(allCodes, sizeOfMemory, debug);
	}

	return 0;
}
