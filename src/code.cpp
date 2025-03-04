#include <vector>
#include <iostream>

#include "../includes/code.h"


//
void Code::plus(std::vector<int>& data, int& idx)
{
    data[idx]++;
    if (data[idx] >= 256)
        data[idx] = 0;
}


//
void Code::less(std::vector<int>& data, int& idx)
{
    data[idx]--;
    if (data[idx] < 0)
        data[idx] = 255;
}


//
void Code::right(std::vector<int>& data, int& idx)
{
    idx++;
    if (data.size() == idx)
        idx = 0;
}


//
void Code::left(std::vector<int>& data, int& idx)
{
    idx--;
    if (idx < 0)
        idx = data.size() - 1;
}


//
void Code::print(std::vector<int>& data, int& idx)
{
    std::cout 
        << "\033[92m" 
        << std::dec
        << (char)data[idx] 
        << "\033[0m";
}


//
void Code::print_c(std::vector<int>& data, int& idx)
{
    std::cout 
        << "\033[93m" 
        << std::dec 
        << data[idx] 
        << "\033[0m";
}

//
void Code::input_i(std::vector<int>& data, int& idx)
{
    int i;
    std::cin >> i;

    if (i > 255 || i < 0)
    {
        i = 0;
    }

    data[idx] = i;
}


//
void Code::input(std::vector<int>& data, int& idx)
{
    char c;
    std::cin >> c;
    data[idx] = (int)c;
}


//
void Code::loop_in(std::vector<int>& loopI, int& i)
{
    loopI.push_back(i);
}


//
void Code::loop_out(std::vector<int>& data, std::vector<int>& loopI, int& idx, int& i)
{
    if (data[idx] != 0)
        i = loopI[loopI.size() - 1];
    else
        loopI.pop_back();
}


void Code::if_in(std::vector<int>& data, int& idx, std::vector<bool>& ifI)
{
    ifI.push_back(data[idx] == 0);
}


void Code::if_out(std::vector<bool>& ifI)
{
    ifI.pop_back();
}


void Code::empty(std::vector<int>& data, int& idx)
{
    data[idx] = 0;
}


void Code::full(std::vector<int>& data, int& idx)
{
    data[idx] = 255;
}


void Code::char_to_ascii(std::vector<int>& data, int& idx, int& i, char symbol)
{
    if (symbol == '_') symbol = ' ';

    data[idx] = (int)symbol;
    i++;
}


void Code::var(std::vector<int>& data, int& idx, std::vector<std::vector<std::string>>& var, int& i, char symbol)
{
    bool varExist = false;

    int iVar = 0;

    std::string name = std::string(1, symbol);
    std::string newData = std::to_string(data[idx]);

    for (auto el : var)
    {
        if (el[0] == name)
        {
            varExist = true;
            var[iVar][1] =  newData;
        }

        iVar++;
    }

    if (!varExist)
    {
        var.push_back({name, newData});
    }
    i++;
}


void Code::var_get(std::vector<int>& data, int& idx, std::vector<std::vector<std::string>>& var, int& i, char symbol)
{
    bool varExist = false;
    int iVar = 0;
    std::string name = std::string(1, symbol);

    for (auto el : var)
    {
        if (el[0] == name)
        {
            varExist = true;
            data[idx] = std::stoi(var[iVar][1]);
            break;
        }

        iVar++;
    }
    i++;
}
