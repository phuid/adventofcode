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

bool isasum(int preamble, std::vector<long long unsigned int> nums, size_t i_i)
{

  for (size_t i = i_i - preamble - 1; i < i_i; i++)
  {
    for (size_t u = i_i - preamble - 1; u < i_i; u++)
    {
      if (nums[i] + nums[u] == nums[i_i])
      {
        return (1);
      }
    }
  }
  return (0);
}

int main()
{
  std::vector<std::string> inputvector;

  start("day9input.txt", inputvector);

  std::vector<unsigned long long int> nums;

  for (auto &&i : inputvector)
  {
    nums.push_back(std::stoll(i));
  }

  int preamble = 25;

  long long int invalid;

  for (size_t i = preamble + 1; i < nums.size(); i++)
  {
    if (!isasum(preamble, nums, i))
    {
      std::cout << "first invalid number is nums[" << i << "] (" << nums[i] << ")" << std::endl;
      invalid = nums[i];
      break;
    }
  }

  for (size_t i = 2; i < nums.size(); i++) //lenght of the contiguous set of numbers
  {
    for (size_t u = 0; u < nums.size(); u++)
    {
      if (i + u < nums.size())
      {
        long long int tmp = 0;
        for (size_t z = 0; z < i; z++)
        {
          tmp += nums[u + z];
        }
        if (tmp == invalid)
        {
          std::cout << "the nums are: ";
          for (size_t z = 0; z < i; z++)
          {
            std::cout << nums[u + z] << ", ";
          }
          unsigned long long int biggest = 0;
          unsigned long long int smallest = 0;
          for (size_t z = 0; z < i; z++)
          {
            if (nums[u + z] > biggest)
            {
              biggest = nums[u + z];
            }
            if (nums[u + z] < smallest)
            {
              smallest = nums[u + z];
            }
          }
          std::cout << std::endl << smallest << " + " << biggest << " == " << smallest + biggest;
        }
      }
      else
      {
        break;
      }
    }
  }
}