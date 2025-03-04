#ifndef compiler_h
#define compiler_h

#include <vector>
#include <string>

void execute(char symbol, std::vector<int>& data, std::vector<int>& loopI, int& idx, int i);
void compiler(std::string code, int size, bool debug);


#endif
