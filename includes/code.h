#ifndef code_h
#define code_h

#include <vector>

class Code
{
    public:
        static void char_to_ascii(std::vector<int>& data, int& idx, int& i, char symbol);
        static void var(std::vector<int>& data, int& idx, std::vector<std::vector<std::string>>& var, int& i, char symbol);
        static void var_get(std::vector<int>& data, int& idx, std::vector<std::vector<std::string>>& var, int& i, char symbol);

        static void empty(std::vector<int>& data, int& idx);
        static void full(std::vector<int>& data, int& idx);

        static void plus(std::vector<int>& data, int& idx);
        static void less(std::vector<int>& data, int& idx);
        
        static void right(std::vector<int>& data, int& idx);
        static void left(std::vector<int>& data, int& idx);
        
        static void print(std::vector<int>& data, int& idx);
        static void print_c(std::vector<int>& data, int& idx);
        
        static void input(std::vector<int>& data, int& idx);
        static void input_i(std::vector<int>& data, int& idx);

        static void if_in(std::vector<int>& data, int& idx, std::vector<bool>& ifI);
        static void if_out(std::vector<bool>& ifI);
        
        static void loop_in(std::vector<int>& loopI, int& i);
        static void loop_out(std::vector<int>& data, std::vector<int>& loopI, int& idx, int& i);
};

#endif
