#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> inputvector;
std::vector<std::string> tocheck;
std::vector<std::string> checkedvector;

size_t counter;

bool checked(std::string i_str)
{
  for (auto &&i : checkedvector)
  {
    if (i_str == i)
      return (1);
  }
  return (0);
}

std::string find(std::string i_str)
{
  for (auto &&i : inputvector)
  {
    if (i.find(i_str) != std::string::npos)
    {
      return (i);
    }
  }
}

int main()
{
  std::ifstream input("day7input.txt");

  std::string line;
  while (getline(input, line))
  {
    inputvector.push_back(line);
  }

  tocheck.push_back("1 shiny gold bags");

  while (tocheck.size() > 0)
  {
    // if (!checked(tocheck.back().substr(2)))
    // {
      if (tocheck.back() == "no other bags")
      {
        tocheck.pop_back();
        continue;
      }
      
      // checkedvector.push_back(tocheck.back().substr(2));
      //std::cout << "back: '" << tocheck.back() << "' "; 
      std::string checking = find(tocheck.back().substr(2) + " contain").substr(find(tocheck.back().substr(2) + " contain").find("contain") + 8);
      std::cout << std::endl << "contain: '" << checking << "'; ";      
      size_t n = stoi((tocheck.back().substr(0, 1)));
      tocheck.pop_back();
      counter += n;

      for (size_t i = 0; i < n; i++)
      {
        std::string topushtocheck = checking;
        std::cout << i;
        while (topushtocheck.length() != 0)
        {
          if (topushtocheck[topushtocheck.find("bag") + 3] == 's')
          {
            tocheck.push_back(topushtocheck.substr(0, topushtocheck.find("bags") + 4));
            topushtocheck = topushtocheck.substr(topushtocheck.find("bags") + 5);
          }
          else
          {
            tocheck.push_back(topushtocheck.substr(0, topushtocheck.find("bag") + 3) + "s");
            topushtocheck = topushtocheck.substr(topushtocheck.find("bag") + 4);
          }
          if (topushtocheck.length() == 1)
            topushtocheck = "";
          else if (topushtocheck.length() > 0 && topushtocheck[0] == '.' | ' ' | ',')
            topushtocheck = topushtocheck.substr(1);
        }
      }
    // }
  }

  counter--; //it counts the shiny gold too

  std::cout << counter << std::endl;
}