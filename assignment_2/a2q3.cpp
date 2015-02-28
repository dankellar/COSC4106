#include <iostream>
#include <vector>

const std::vector<char> SET = {'a', 'b', 'c', 'd'};

std::vector<int> count(const std::vector<char> & vec)
{
    std::vector<int> distrib(4, 0);
    for (auto i : vec)
    {
        switch(i)
        {
            case 'a':
                distrib[0]++;
                break;
            case 'b':
                distrib[1]++;
                break;
            case 'c':
                distrib[2]++;
                break;
            case 'd':
                distrib[3]++;
                break;
            
        }
    }
    
    return distrib;
}

void distributeSort(std::vector<char> & vec)
{
    std::vector<int> distrib = count(vec);
    for (unsigned i = 0; i < vec.size(); i++)
    {
        if (distrib[0] > 0)
        {
            vec[i] = 'a';
            distrib[0]--;
        }
        
        else if (distrib[1] > 0)
        {
            vec[i] = 'b';
            distrib[1]--;
        }
        
        else if (distrib[2] > 0)
        {
            vec[i] = 'c';
            distrib[2]--;
        }
        
        else if (distrib[3] > 0)
        {
            vec[i] = 'd';
            distrib[3]--;
        }
    }
}

int main()
{
    std::vector<char> array = {'b', 'a', 'c', 'c', 'd', 'd', 'a'};
    
    for (auto i : array) std::cout<< i<< " ";
    std::cout<< "\n";
    
    distributeSort(array);
    
    for (auto i : array) std::cout<< i<< " ";
    std::cout<< "\n";
}