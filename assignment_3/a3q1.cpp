#include <iostream>
#include <string>
#include <map>
#include <vector>

std::map<char, int> badSymbol(const std::string & pattern)
{
    std::map<char, int> table;
    
    for (char c = 'A'; c <= 'Z'; c++)
    {
        table.insert(std::pair<char, int>(c, pattern.length()));
    }
    
    for (int i = 0; i < pattern.length() - 1; i++)
    {
        table[pattern[i]] = (pattern.length() - 1) - i;
    }
    
    for (auto i = table.begin(); i != table.end(); i++)
    {
        std::cout<< i -> first<< " : "<< i -> second<< "\n";
    }
    
    return table;
}

std::map<int, int> goodSuffix(const std::string & pattern)
{
    std::map<int, int> suffix;
    
    std::string tail;
    
    std::cout<< pattern<< "\n";
    
    for (int k = 1; k < pattern.length() - 1; k++)
    {
        tail = pattern.substr((pattern.length() - 1) - k);
        std::cout<< tail<< "\n";
    }
}

int main()
{
    std::string pattern = "BAOBAB";
    //badSymbol("BAOBAB");
    goodSuffix(pattern);
}