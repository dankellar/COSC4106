#include <iostream>
#include <vector>

/**
 * 
 * The gist of it: if vec has 2 elements, if the first element > the second element, return 1 otherwise return 0
 * 				   if vec has < 2 elements, return 0
 * 
 */
//

int countInversion(const std::vector<int> & vec, unsigned start, unsigned end)
{
	//std::cout<< "start: "<< start<< " end: "<< end<< "\n";
    if (end - start == 1) return 0;
	if (end - start == 2)
	{
		if (vec[start] > vec[end]) return 1;
		return 0;
	}
	
	int mid = (end - start) / 2;
	int left = countInversion(vec, start, mid);
	int right = countInversion(vec, 1 + mid, end);
	
	int c = 0;
	
	for (int i = start; i < mid; i++)
	{
		for (int j = mid; j < end; j++)
		{
			if (vec[i] > vec[j] && i < j)
			{
				//std::cout<< "vec[i]: "<< vec[i]<< "vec[j]: "<< vec[j]<< "\n";
				c++;
			}
		}
	}
	
	return c + left + right;
}

int main()
{
	std::vector<int> vec = {8, 5, 3, 4, 2, 6};
	//std::vector<int> vec = {9, 8, 4, 5};
	
	std::cout<< countInversion(vec, 0, vec.size())<< "\n";
}