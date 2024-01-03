// Task3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <random>
#include <future>

template <typename It, typename F>
void parallel_for_each(It begin, It end, F func);
template <typename It>
void printVector(It begin, It end);

int main()
{
	int N = 10;
	std::vector<int> v;
	for (int i = 0; i < N; ++i)
	{
		v.push_back(std::rand() % 100);
	}
	printVector(v.cbegin(), v.cend());
	parallel_for_each(v.begin(), v.end(), [](int& n)
		{
			n++;
		}
	);
	printVector(v.cbegin(), v.cend());

	return 0;
}

template<typename It, typename F>
void parallel_for_each(It begin, It end, F func)
{
	auto currSize = std::distance(begin, end);
	if (currSize <= 1)
	{
		func(*begin);
		return;
	}
	auto mid = begin;
	std::advance(mid, currSize / 2);
	auto ftRes = std::async(parallel_for_each<It, F>, begin, mid, func);
	parallel_for_each(mid, end, func);
}

template <typename It>
void printVector(It begin, It end)
{
	std::cout << "Vector: { ";
	for (It i = begin; i < end; ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "};" << std::endl;
}