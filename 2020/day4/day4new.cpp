#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> inputvector;
std::vector<std::string> passvector;

std::regex regexes[]{
    std::regex("(byr:((19[2-9][0-9])|(200[0-2])) )"),
    std::regex("(iyr:(20((1[0-9])|(20))) )"),
    std::regex("(eyr:(20((2[0-9])|(30)) ))"),
    std::regex("(hgt:((1(([5-8][0-9])|(9[0-3]))cm)|(((59)|(6[0-9])|(7[0-6]))in)) )"),
    std::regex("(hcl:#(.{6}) )"),
    std::regex("(ecl:((amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth)) )"),
    std::regex("(pid:\\d{9} )")
    // std::regex("cid:");
};

bool onlyones(std::string i_str) {
  for (size_t i = 0; i < i_str.length(); i++)
  {
    if (i_str[i] != '\001')
    {
      return (0);
    }
    
  }
  return (1);
}

int main()
{
  int validcount = 0;

  std::ifstream input("day4input.txt");
  if (input.is_open())
  {
    std::string line;
    while (std::getline(input, line))
    {
      inputvector.push_back(line);
    }
    std::string pass = "";
    for (auto &&i : inputvector)
    {
      if (i.length() > 0)
      {
        pass += i;
        if (i.substr(i.length()) != " ")
        {
          pass += " ";
        }
        
      }
      else
      {
        passvector.push_back(pass);
        pass = "";
      }
    }
    passvector.push_back(pass);
    
    for (auto &&i : passvector)
    {
      std::string regexpass = "";
      for (auto &&u : regexes)
      {
        std::cout << std::regex_search(i, u);
        regexpass += std::regex_search(i, u);
      }
      validcount += onlyones(regexpass);
      std::cout << "---" << i << "---" << onlyones(regexpass) << std::endl;
    }

    std::cout << "validcount:" << validcount << std::endl;
    

    // for (auto &&i : passvector)
    // {
    //   std::cout << i << std::endl
    //             << "----" << std::endl;
    // }
  }
  else
    std::cout << "input not open" << std::endl;
}
