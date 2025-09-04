#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
class Counter{
private:
int count;
std::mutex mtx;
public:
Counter() : count(0) {}
void increment() {
std::lock_guard<std::mutex> lock(mtx);
count++;
std::cout << "Count: " << count << " (Thread: " << std::this_thread::get_id() << ")" << std::endl;
}
int getCount() {
std::lock_guard<std::mutex> lock(mtx);
return count;
}
};
void incrementCounter(Counter& counter, int iterations) {
for(int i = 0; i < iterations; i++) {
counter.increment();
std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
}
int main() {
Counter counter;
const int NUM_THREADS = 3;
const int ITERATIONS_PER_THREAD = 5;
std::vector<std::thread> threads;
// Create threads
for(int i = 0; i < NUM_THREADS; i++) {
threads.emplace_back(incrementCounter, std::ref(counter), ITERATIONS_PER_THREAD);
}
// Wait for completion
for(auto& t : threads) {


For C++11 std::thread examples:

Practical Exercises - Threads
Exercise 4: Create a producer-consumer program using threads and synchronization primitives.
Exercise 5: Implement a thread pool that can execute multiple tasks concurrently.
Exercise 6: Write a multi-threaded file processor that reads multiple files simultaneously and counts
words.
Exercise 7: Create a simple multi-threaded web server simulation that handles multiple client requests.

Lab Assignment Questions
Section A: Process Management(20 points)

1. [5 points] Explain the difference between a process and a program. What happens when you double-
click an executable file?

2. [10 points] Write a C++ program that:
Creates a child process to run "ping google.com"
Monitors the child process status
Prints the process ID of both parent and child
Waits for the child to complete
t.join();
}
std::cout << "Final count: " << counter.getCount() << std::endl;
return 0;
}