#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <Windows.h>
#include <random>
#include <map>

using namespace std::chrono_literals;

class Data {
private:
	int value_ = 0;

public:
	Data() = default;
	Data(int value) : value_(value) {}

	std::mutex mutex_;

    int getValue() const
    {
        return Data::value_;
    }
    void setValue(int value)
    {
        Data::value_ = value;
    }
};


void swapWithLock(Data& d1, Data& d2)
{
    std::lock(d1.mutex_, d2.mutex_);

    //swap
    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "ThreadId: " << std::this_thread::get_id() << ". После обмена: " __FUNCTION__ << std::endl;
    std::cout << "value_ = " << d1.getValue() << ";" << std::endl;
    std::cout << "value_ = " << d2.getValue() << ";" << std::endl;

    d1.mutex_.unlock();
    d2.mutex_.unlock();
}

void swapWithScopedLock(Data& d1, Data& d2)
{
    std::scoped_lock lock(d1.mutex_, d2.mutex_);

    //swap
    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "ThreadId: " << std::this_thread::get_id() << ". После обмена: " __FUNCTION__ << std::endl;
    std::cout << "value_ = " << d1.getValue() << ";" << std::endl;
    std::cout << "value_ = " << d2.getValue() << ";" << std::endl;
}

void swapWithUniqueLock(Data& d1, Data& d2)
{
    std::unique_lock<std::mutex> lock1(d1.mutex_, std::defer_lock);
    std::unique_lock<std::mutex> lock2(d2.mutex_, std::defer_lock);
    //lock1.lock();
   // lock2.lock();

    //swap
    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::lock (d1.mutex_, d2.mutex_);

    std::cout << std::endl << "ThreadId: " << std::this_thread::get_id() << ". После обмена: " __FUNCTION__ << std::endl;
    std::cout << "value_ = " << d1.getValue() << ";" << std::endl;
    std::cout << "value_ = " << d2.getValue() << ";" << std::endl;
   
    d1.mutex_.unlock();
    d2.mutex_.unlock();
    //lock1.unlock();
   // lock2.unlock();
   }

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "ID main thread: " << std::this_thread::get_id() << "\n";

    Data d1(55555);
    Data d2(11111);

    std::cout << "\nДо обмена:\n";
    std::cout << "value_ = " << d1.getValue() << ";" << std::endl;
    std::cout << "value_ = " << d2.getValue() << ";" << std::endl;

    std::thread thread1(swapWithLock, std::ref(d1), std::ref(d2));
    std::thread thread2(swapWithScopedLock, std::ref(d1), std::ref(d2));
    std::thread thread3(swapWithUniqueLock, std::ref(d1), std::ref(d2));

    thread1.join();
    thread2.join();
    thread3.join();

    //std::cout << "\n\nend of main\n";
}