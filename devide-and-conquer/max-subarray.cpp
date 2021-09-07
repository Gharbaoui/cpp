#include <iostream>
#include <vector>


void	daynamic(std::vector<int> a, int size);
void	brute_force(std::vector<int> a, int size);
int main()
{
	//13, –3, –25, 20, –3, –16, –23, 18, 20, –7, 12, –5, –22, 15, –4, 7
	std::vector <int> a{-2, -3, 4, -1, -2, 1, 5, -3};
	brute_force(a, a.size());
	daynamic(a, a.size());
}

void	brute_force(std::vector<int> a, int size)
{
	int	low;
	int high;
	int max;
	int	sum;

	max = -10000;
	for (int i = 0; i < size; i++)
	{
		sum = 0;
		for (int j = i; j >= 0; j--) {
			sum += a[j];
			if (sum > max)
			{
				max = sum;
				low = j;
				high = i;
			}
		}
	}

	std::cout << max << std::endl;
	std::cout << low << " " << high << std::endl;
}

void	daynamic(std::vector<int> a, int size)
{
	int sum;
	std::tuple<std::pair<int, int>, int> lastinf;	
	std::get<0>(lastinf) = {0, 0};
	std::get<1>(lastinf) = a[0];
	
	std::tuple<std::pair<int, int>, int> max;	
	std::get<0>(max) = {0, 0};
	std::get<1>(max) = -1000000;
	sum = 0;

	for (int i = 1; i < size; i++) {
		sum = a[i] + std::get<1>(lastinf);
		if (a[i] < sum)
		{
			std::get<0>(lastinf).second = i;
			std::get<1>(lastinf) = sum;
		}else {
			std::get<0>(lastinf) = {i, i};
			std::get<1>(lastinf) = a[i];
		}
		if (std::get<1>(max) < std::get<1>(lastinf)) {
			std::get<1>(max) = sum;
			std::get<0>(max) = std::get<0>(lastinf);
		}
	}
	std::cout << std::get<1>(max) << std::endl;
	std::cout << std::get<0> (max).first << " " << std::get<0>(max).second << std::endl;
}
