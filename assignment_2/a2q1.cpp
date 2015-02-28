#include <iostream>
#include <vector>

int countInversion(const std::vector<int> & vec, unsigned start, unsigned end)
{
    if (end < start) return 0;
    if (end == start) return 0;
	if (end - start == 1)
	{
		if (vec[start] > vec[end]) return 1;
		return 0;
	}
	
	int mid = (end - start) / 2 + start;
	int left = countInversion(vec, start, mid);
	int right = countInversion(vec, 1 + mid, end);
	
	int c = 0;
	
	for (int i = start; i <= mid; i++)
	{
		for (int j = mid + 1; j <= end; j++)
		{
			if (vec[i] > vec[j])
			{
				c++;
			}
		}
	}
	
	return c + left + right;
}

int main()
{
    // randomly generated sample. Expected output: 10.
	//std::vector<int> vec = {8, 5, 3, 4, 2, 6};
	
	// provided example. Expected output: 5.
	std::vector<int> vec = {9, 8, 4, 5};
	
	std::cout<< countInversion(vec, 0, vec.size() - 1)<< "\n";
}