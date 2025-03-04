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
		<< "This package is used to compile brainfuck code.\n\t" 
		<< "bfc++ <script.bf>\n\t\t"
		<< PARAM_DEBUG
		<< " Show all step compilation\n\t\t"
		<< PARAM_SIZEM 
		<< " <size> The size of the memory (default 10)\n\n\t"
		<< "All symbols:\n\t\t"
		<< BF_PLUS << " Increase memory case\n\t\t"
		<< BF_LESS << " Decrease memory case\n\t\t"
		<< BF_RIGHT << " Move memory cursor to the right\n\t\t"
		<< BF_LEFT << " Move memory cursor to the left\n\t\t"
		<< BF_LOOP_IN << " The start of the loop (While actual case != 0)\n\t\t"
		<< BF_LOOP_OUT << " The end of the loop\n\t\t"
		<< BF_IF_IN << " The start of the if (if actual case == 0)\n\t\t"
		<< BF_IF_OUT << " The end of the if\n\t\t"
		<< BF_PRINT << " Print ASCII symbol\n\t\t"
		<< BF_PRINT_C << " Print ASCII code\n\t\t"
		<< BF_INPUT << " Get char (Convert char to ASCII code)\n\t\t"
		<< BF_INPUT_I << " Get num (Max : 255, Min : 0)\n\t\t"
		<< BF_COMMENT << " Comment, ignore line\n\t\t"
		<< BF_FULL << " Set max value in actual case (255)\n\t\t"
		<< BF_EMPTY << " Set min value in actual case (0)\n\t\t"
		<< BF_CHAR_TO_ASCII << " Convert char to ascii and put value in actual case (/a = 97)\n\t\t"
		<< BF_VAR << " Store value of actual case in var\n\t\t"
		<< BF_VAR_GET << " Set actual case value with variable value\n\t\t"
		<< "\n"
		;
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
		<< "\t+--------------------+\n"
		<< "\t| Brainfuck Compiler |\n"
		<< "\t+--------------------+\n";
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
