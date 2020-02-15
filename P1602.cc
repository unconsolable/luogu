#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cctype>

int main()
{
	std::string sent, word;
	std::vector<std::string> list;
	getline(std::cin, sent);
	std::istringstream str1(sent);
	std::map<std::string, int> fx = { {"one",1},{"two",4},{"three",9},{"four",16},{"five",25},
									{"six",36},{"seven",49},{"eight",64},{"nine",81},{"ten",0},{"eleven",21},{"twelve",44},
									{"thirteen",69},{"fourteen",96},{"fifteen",25},{"sixteen",56},{"seventeen",89},
									{"eighteen",24},{"nineteen",61},{"twenty",00},{"a",1},{"both",4},{"another",1},
									{"first",1},{"second",4},{"third",9} };
	while ((str1 >> word) && (word != "."))
	{
		std::for_each(word.begin(), word.end(), [](char& a) {a = tolower(a); });
		list.push_back(word);
	}
	int num[6], curr = 0;
	for (const auto &a : list)
	{
		if (fx.find(a) != fx.end())
		{
			num[curr++] = fx[a];
		}
	}
	auto sortComp = [](int a, int b) -> bool
	{
		return a > b;
	};
	std::sort(std::begin(num), std::begin(num) + curr, sortComp);
	long long result = 0;
	for (int i = 0; i != curr; ++i)
	{
		result += num[i] * pow(100, i);
	}
	std::cout << result;
}