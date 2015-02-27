#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// returns a pair of indices for each vector. Elements are -1 is it couldn't make the sum
std::pair<int, int> makesSum(std::vector<int> & a, std::vector<int> & b, int sum)
{
	auto f = [](int i, int j){ return i < j; };
	
	// According to http://en.cppreference.com/w/cpp/algorithm/sort std::sort is nlogn time
	std::sort(a.begin(), a.end(), f);
	std::sort(b.begin(), b.end(), f);
	
	int highB;
	int midB;
	int lowB;
	
	// Perform a linear search on A, and a binary search on B (for each value in A)
	
	for (int i = 0; i < a.size(); i++)
	{
		highB = b.size();
		lowB = 0;
		midB = highB / 2;
		while (midB > 0 && midB < b.size())
		{
			if ((a[i] + b[midB]) == sum) return std::pair<int, int>(i, midB);
			if (a[i] + b[midB] < sum)
			{
				highB = midB;
				midB = (highB - lowB) / 2;
			}
			else
			{
				lowB = midB;
				midB = (highB - lowB) / 2;
			}
			
			if (midB == 0) break;
		}
	}
	
	return std::pair<int, int>(-1, -1);
}

int main()
{
	/**/
	std::vector<int> a = {8, 3, 4, 7};
	std::vector<int> b = {5, 6, 12, 1};
	int sum = 10;
	/**/
	
	/*
	std::vector<int> a = {1, 5, 4, 2};
	std::vector<int> b = {6, 3, 2, 1};
	int sum = 12;
	*/
	
	std::pair<int, int> i = makesSum(a, b, sum);
	if (i.first < 0 || i.second < 0) std::cout<< "No integers from A or B add up to "<< sum<< "\n";
	else std::cout<< a[i.first]<< " + "<< b[i.second]<< " = "<< sum<< "\n";
}