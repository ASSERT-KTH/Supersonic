#include <iostream>

int main(int argc, char* argv[]) {
  // Check if the required number of arguments is provided
  if (argc < 3) {
    std::cerr << "Usage: program_name <integer1> <integer2>" << std::endl;
    return 1;
  }
  
  // Parse the input arguments as integers
  int a = std::stoi(argv[1]);
  int b = std::stoi(argv[2]);
  
  // Calculate the required values
  int product = a * b;
  int sum = a * 2 + b * 2;
  
  // Print the results
  std::cout << product << " " << sum << std::endl;
  
  return 0;
}