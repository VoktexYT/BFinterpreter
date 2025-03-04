#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <thread>
#include <chrono>


#include "../includes/const.h"
#include "../includes/code.h"


//
void execute(
	std::string code, 
	std::vector<int>& data, 
	std::vector<int>& loopI, 
	int& idx, 
	int& i, 
	std::vector<bool>& ifI,
	std::vector<std::vector<std::string>>& var
)
{
	switch (code[i])
	{
		case BF_IF_IN: 
			Code::if_in(data, idx, ifI); break;
		case BF_IF_OUT: 
			Code::if_out(ifI); break;
		default:
			break;
	}

	if (ifI.size() > 0 && ifI.back())
	{
		switch (code[i])
		{
			case BF_VAR_GET:
				Code::var_get(data, idx, var, i, code[i+1]); break;
			case BF_VAR:
				Code::var(data, idx, var, i, code[i+1]); break;
			case BF_CHAR_TO_ASCII:
				Code::char_to_ascii(data, idx, i, code[i+1]); break;
			case BF_FULL:
				Code::full(data, idx); break;
			case BF_EMPTY:
				Code::empty(data, idx); break;
			case BF_PLUS:
				Code::plus(data, idx); break;
			case BF_LESS: 
				Code::less(data, idx); break;
			case BF_RIGHT: 
				Code::right(data, idx); break;
			case BF_LEFT: 
				Code::left(data, idx); break;
			case BF_PRINT: 
				Code::print(data, idx); break;
			case BF_PRINT_C: 
				Code::print_c(data, idx); break;
			case BF_INPUT: 
				Code::input(data, idx); break;
			case BF_INPUT_I: 
				Code::input_i(data, idx); break;
			case BF_LOOP_IN: 
				Code::loop_in(loopI, i); break;
			case BF_LOOP_OUT: 
				Code::loop_out(data, loopI, idx, i); break;
			default: break;
		}
	}
}


void showDataLine(int& idx, std::vector<int>& data)
{
	int step=0;
	for (auto el : data)
	{
		if (idx == step) std::cout << "\033[91m";
		if (el <= 15) std::cout << "0";
		std::cout << std::hex << el << "\033[0m ";
		step++;
	}
}

//
void compiler(std::string code, int size, bool debug) 
{
	std::vector<int> data(size, 0);
	int idx = 0;
	std::vector<int> loopI = {};
	std::vector<bool> ifI = {true};
	std::vector<std::vector<std::string>> var = {};

	for (int i=0; i<code.size(); i++)
	{
		execute(code, data, loopI, idx, i, ifI, var);

		if (debug)
		{
			std::cout << "\t" << code[i] << "\t";
			showDataLine(idx, data);
			std::cout << std::endl;
		}

		if (i >= code.size() - 1)
		{
			std::cout << std::endl << "\t";
			showDataLine(idx, data);
			std::cout << std::endl;
		}
	}
}
