#include <SugarSyncLog.h>
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {
  auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  cout << std::put_time(std::localtime(&t), "%Y/%m/%d %H-%M-%S") << endl; 
  return 0;
}