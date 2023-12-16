// Task2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <condition_variable>
#include <Windows.h>
#include <random>
#include <atomic>
#include "Time.h"



using namespace std::chrono_literals;
std::mutex m1; // для печати номера и идентификатора потоков
std::mutex m2; // для печати индикатора 
std::mutex m3; // для печати времени
std::once_flag flag; // для печати заголовков при многопоточном вычислении

void printHeaders();
void calcProgressBar(const int numberThread, const int countThreads);

class ProgressBar {
public:
	ProgressBar(int numberThreads, int data) : numberThreads(numberThreads), data(data)
	{
		printNumberAndId();
	};
	void calculation();

private:
	int numberThreads;
	int x0 = 15;
	int x = x0;
	int y = numberThreads;
	int data;
	int width = 12;
	bool endProgress = false;
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	void printNumberAndId();
};

std::vector<ProgressBar> progressBars;

int main() {
	setlocale(LC_ALL, "Russian");
	int countThreads = 4;
	std::vector<std::thread> vectorThreads;
	for (int i = 0; i < countThreads; ++i)
	{
		vectorThreads.push_back(std::thread(calcProgressBar, i + 1, countThreads));
	}
	for (int i = 0; i < countThreads; ++i)
	{
		vectorThreads.at(i).join();
	}
	consol_parameter::SetPosition(0, countThreads + 1);
	return 0;
}

void printHeaders()
{
	std::cout << "#\t" << "id потока\t" << "Прогресс-бар\t" << "Время" << std::endl;
}

void calcProgressBar(const int numberThread, const int countThreads)
{
	std::call_once(flag, printHeaders);
	std::unique_lock<std::mutex> ulc(m1);
std:ProgressBar pb(numberThread, countThreads * 100);
	progressBars.push_back(pb);
	ulc.unlock();
	pb.calculation();
}

void ProgressBar::printNumberAndId() {
	consol_parameter::SetPosition(0, y);
	std::cout << y << "\t" << std::this_thread::get_id() << '\n';
}

void ProgressBar::calculation() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 100);
	double step = static_cast<double>(data) / width;
	double progress = 0;
	int text = 0;
	consol_parameter::SetColor(7, text);
	while (progress < data)
	{
		std::this_thread::sleep_for(200ms);

		std::unique_lock<std::mutex> ulc(m2);
		try {
			if (dis(gen) % 3 == 0) {
				throw std::runtime_error("Error");
			}
			text = 7;
		}
		catch (const std::exception& e) {
			text = 2;
		}
		consol_parameter::SetColor(7, text);
		consol_parameter::SetPosition(x, y);
		std::cout << " ";
		progress += step;
		x += 1;
		std::this_thread::sleep_for(200ms);
		ulc.unlock();
	}
	std::unique_lock<std::mutex> ulc(m3);
	auto end = std::chrono::steady_clock::now();
	std::this_thread::sleep_for(50ms);
	consol_parameter::SetColor(7, 0);
	consol_parameter::SetPosition(x0 + width + 5, y);
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << duration.count() * 1e-3 << "s";
}