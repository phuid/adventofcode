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

int main()
{
  std::vector<std::string> inputvector;

  start("day8input.txt", inputvector);

  struct display
  {
    std::vector<std::string> combinations;
    std::vector<std::string> digits;
  };

  std::vector<display> displays;

  for (auto &&i : inputvector)
  {
    display currentdisplay;
    while (i.find('|') != 0)
    {
      currentdisplay.combinations.push_back(i.substr(0, i.find(' ')));
      i = i.substr(i.find(' ') + 1);
    }
    i = i.substr(2);
    while (i.length() > 0)
    {
      if (i.find(' ') != std::string::npos)
      {
        currentdisplay.digits.push_back(i.substr(0, i.find(' ')));
        i = i.substr(i.find(' ') + 1);
      }
      else
      {
        currentdisplay.digits.push_back(i);
        i = "";
      }
    }
    displays.push_back(currentdisplay);
  }

    int counter = 0;
  for (auto &&i : displays)
  {
    for (auto &&u : i.digits)
    {
      if (u.length() == 2 || u.length() == 3 || u.length() == 4 || u.length() == 7)
      {
        counter++;
      }
    }
  }
  std::cout << "counter: " << counter << std::endl;
}