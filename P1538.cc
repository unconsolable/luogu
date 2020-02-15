#include <iostream>
#include <string>
using std::string;

//0 not print,1 print
int printpt1[10] = { 1,0,1,1,0,1,1,1,1,1 };
//1 left,2 right,3 both
int printpt2[10] = { 3,2,2,2,3,1,1,2,3,3 };
int printpt3[10] = { 0,0,1,1,1,1,1,0,1,1 };
int printpt4[10] = { 3,2,1,2,2,2,3,2,3,2 };
int printpt5[10] = { 1,0,1,1,0,1,1,0,1,1 };


inline void print_row(int num, int people,int style[])
{
	std::cout << ' ';
	for (int j = 0; j != people; ++j)
	{
		std::cout << ((style[num]) ? '-' : ' ');
	}	
	std::cout << ' ' << ' ';
}

inline void print_column(int num, int people,int style[])
{
	//std::cout << ' ';
	std::cout << ((style[num] != 2) ? '|' : ' ');
	for (int j = 0; j != people; j++) std::cout << ' ';
	std::cout << ((style[num] != 1) ? '|' : ' ');
	std::cout << ' ';
}

int main()
{
	int people; string number;
	std::cin >> people >> number;
	for (const auto& a : number)
	{
		print_row(a - '0', people, printpt1);
	}
	for (int j = 0; j != people; ++j)
	{
		std::cout << std::endl;
		for (const auto& a : number)
		{
			print_column(a - '0', people, printpt2);
		}
	}
	std::cout << std::endl;
	for (const auto& a : number)
	{
		print_row(a - '0', people, printpt3);
	}
	for (int j = 0; j != people; ++j)
	{
		std::cout << std::endl;
		for (const auto& a : number)
		{
			print_column(a - '0', people, printpt4);
		}
	}
	std::cout << std::endl;
	for (const auto& a : number)
	{
		print_row(a - '0', people, printpt5);
	}
}