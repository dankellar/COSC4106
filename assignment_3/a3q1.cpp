//g++ -std=c++11 -Wall -pedantic -O3 a3q1.cpp -o a3q1

#include <iostream>
#include <string>
#include <map>
#include <vector>

bool substrcomp(const std::string & str, const std::string & pattern, unsigned index)
{
	std::cout<< "string: "<< str<< "\nPattern: "<< pattern<< "\nindex: "<< index<< "\n";
	
	
	if (pattern.length() + index >= str.length()) return false;
	std::string cmp = str.substr(index, pattern.length());
	
	std::cout<< "cmp: "<< cmp<< "\n\n";
	
	return true;
}

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
		
		char pre = pattern[(pattern.length() - 1) - (k + 1)];
		
		for (int i = 0; i < pattern.length(); i++)
		{
			substrcomp(pattern, tail, i);
		}
    }
    
    return suffix;
}

int main()
{
    std::string pattern = "BAOBAB";
    //badSymbol(pattern);
    goodSuffix(pattern);
}