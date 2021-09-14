#include <SugarSyncLog.h>
// #include <SugarSyncLogManager.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  // auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  // cout << std::put_time(std::localtime(&t), "%Y/%m/%d %H-%M-%S") << endl; 
  // Logger* logger = new FileLogger();
  // logger->write("Debug", "Hello World!");
  // auto helper = sugar::sync::log::HelloWorldHelper();
  // helper.Print();
  std::string path = "./HelloWorld/";
  cout << path.length() << endl;
  path.pop_back();
  cout << path.length() << endl;
  cout << path << endl;
  return 0;
}
