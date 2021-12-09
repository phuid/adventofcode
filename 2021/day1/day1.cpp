#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void start(std::string inputfile, std::vector<std::string> &inputvector)
{
  std::ifstream input(inputfile);
  if (input.is_open())
  {
    std::string line;
    while (getline(input, line))
    {
      inputvector.push_back(line);
    }
  }
  else
  {
    std::cout << "input not open" << std::endl;
    exit(0);
  }
}

size_t sumofthree(int i, std::vector<int> &nums) {
  size_t output = 0;
  for (size_t u = i; u < i + 3; u++)
  {
    output += nums[u];
  }
  return output;
}

int main()
{
  std::vector<std::string> inputvector;

  start("day1input.txt", inputvector);

  std::vector<int> nums;

  for (auto &&i : inputvector)
  {
    nums.push_back(stoi(i));
  }
  

  size_t count = 0;

  for (size_t i = 1; i < nums.size(); i++)
  {
    // std::cout << nums[i] << " > " << nums[i - 1] << " = " << (nums[i] > nums[i - 1]);
    count += (nums[i] > nums[i - 1]);
  }
  std::cout << "first: " << count << std::endl;  
  
  count = 0;

  for (size_t i = 1; i < nums.size() - 2; i++)
  {
    count += (sumofthree(i, nums) > sumofthree(i - 1, nums));
  }
  
  std::cout << "second: " << count;
}