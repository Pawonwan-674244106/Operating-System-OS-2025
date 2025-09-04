#include <iostream>
#include <thread>
#include <vector>
int counter = 0; // Shared variable
void incrementCounter() {
for(int i = 0; i < 1000; i++) {
counter++; // Race condition here!
}
}
int main() {
std::vector<std::thread> threads;
// Create multiple threads that increment counter
for(int i = 0; i < 5; i++) {
threads.emplace_back(incrementCounter);
}
for(auto& t : threads) {
t.join();
}
std::cout << "Expected: 5000, Actual: " << counter << std::endl;
// Result will likely be less than 5000 due to race condition
return 0;
}