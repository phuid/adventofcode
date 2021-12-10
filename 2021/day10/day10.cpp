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

  start("day10input.txt", inputvector);

  std::string startingbrackets = "([{<";
  std::string endingbrackets = ")]}>";

  int corruptionscore = 0;
  std::vector<long long int> autocompletescores;

  for (auto &&line : inputvector)
  {
    while (line.length() > 2)
    {
      bool done = 1;
      for (size_t i = 0; i < line.length() - 1; i++)
      {
        for (size_t u = 0; u < 4; u++)
        {
          if (line[i] == startingbrackets[u] && line[i + 1] == endingbrackets[u])
          {
            line.erase(i, 2);
            // std::cout << line << std::endl;
            done = 0;
          }
          else
          {
            for (size_t z = 1; z < 4; z++)
            {
              if (line[i] == startingbrackets[u] && line[i + 1] == endingbrackets[(u + z) % 4])
              {
                std::cout << "syntax error at col " << i + 1 << " Expected " << startingbrackets[u] << ", but found " << endingbrackets[(u + z) % 4] << " instead.: ";
                if ((u + z) % 4 == 0)
                {
                  corruptionscore += 3;
                }
                else if ((u + z) % 4 == 1)
                {
                  corruptionscore += 57;
                }
                else if ((u + z) % 4 == 2)
                {
                  corruptionscore += 1197;
                }
                else if ((u + z) % 4 == 3)
                {
                  corruptionscore += 25137;
                }
                goto endloop;
              }
            }
          }
        }
      }
      if (done)
      {
        for (size_t u = 0; u < 4; u++)
        {
          if (line[line.length() - 1] == startingbrackets[u])
          {
            std::cout << "unfinished statement: ";
            long long int currentscore = 0;
            for (int i = line.length() - 1; i >= 0; i--)
            {
              currentscore *= 5;
              for (size_t character = 0; character < 4; character++)
              {
                if (line[i] == startingbrackets[character])
                {
                  currentscore += character + 1;
                }
              }
            }
            // std::cout << "*score: " << currentscore << "*";
            autocompletescores.push_back(currentscore);
            goto endloop;
          }
        }
      }
    }
  endloop:
    std::cout << line << std::endl;
  }
  std::cout << "corruption score: " << corruptionscore << std::endl;
  for (auto &&i : autocompletescores)
  {
    int biggerthan = 0;
    for (auto &&u : autocompletescores)
    {
      if (i > u)
      {
        biggerthan++;
      }
      
    }
    if (biggerthan == autocompletescores.size() / 2)
    {
      std::cout << "autocompletion score: " << i << std::endl;
    }
    
    
  }
  
}