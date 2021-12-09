#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

vector<string> inputvector;
vector<string> tocheck;
vector<string> checkedvector;
regex shinygoldregex("(\\d shiny gold)");
int haha = 0;

bool checked(string i_string)
{
  for (auto i : checkedvector)
  {
    if (i_string == i)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  ifstream input;
  input.open("day7input.txt");
  if (input.is_open())
  {
    string line;
    while (getline(input, line))
    {
      inputvector.push_back(line);
    }

    for (auto i : inputvector)
    {
      if (regex_search(i, shinygoldregex))
      {
        cout << i.substr(0, i.find(" ", i.find(" ") + 1)) << endl;
        tocheck.push_back(i.substr(0, i.find(" ", i.find(" ") + 1)));
      }
    }

    cout << "-------------------" << endl;

    for (size_t u = 0; u < tocheck.size(); u++)
    {
      if (!checked(tocheck[u]))
      {
        cout << tocheck[u] << ":" << endl;
        regex checkregex("\\d " + tocheck[u]);
        for (size_t i = 0; i < inputvector.size(); i++)
        {
          if (regex_search(inputvector[i], checkregex))
          {
            cout << " -" << inputvector[i].substr(0, inputvector[i].find(" ", inputvector[i].find(" ") + 1)) << endl;
            tocheck.push_back(inputvector[i].substr(0, inputvector[i].find(" ", inputvector[i].find(" ") + 1)));
          }
        }
        checkedvector.push_back(tocheck[u]);
        haha++;
      }
    }

    cout << "haha:" << haha << endl;
  }
  else
    cout << "notopne!!!!!!!!!!!" << endl;
}