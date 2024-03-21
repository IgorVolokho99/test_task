#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mutex;
std::vector<unsigned long long> factorials;

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for(int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void calculateFactorial(int n) {
    unsigned long long result = factorial(n);

    mutex.lock();
    factorials.push_back(result);
    mutex.unlock();
}

int main() {
    std::thread thread1(calculateFactorial, 5);
    std::thread thread2(calculateFactorial, 7);

    thread1.join();
    thread2.join();


    std::cout << "Factorials:\n";
    for(auto &f : factorials) {
        std::cout << f << std::endl;
    }

    return 0;
}
