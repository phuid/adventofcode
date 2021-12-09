#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> inputvector;
vector<string> charsvector;
vector<int> lengthvector;

string usedchars;
int sum = 0;

bool everyone(char i_char, int i) {
  for (size_t u = 0; u < inputvector[i].size(); u++)
  {
    if (inputvector[i][u].find(i_char) == string::npos)
    {
      return false;
    }
    
  }
  return true;
}

int main()
{

  ifstream input;
  input.open("day6input.txt");
  if (input.is_open())
  {

    string line;
    int x = 0;
    inputvector.push_back({});
    while (getline(input, line))
    {
      if (line.length() > 0)
      {
        inputvector[x].push_back(line);
      }
      else
      {
        x++;
        inputvector.push_back({});
      }
    }
    input.close();

    for (size_t i = 0; i < inputvector.size(); i++)
    {
      usedchars.clear();
        for (size_t z = 0; z < inputvector[i][0].length(); z++)
        {
          if (everyone(inputvector[i][0][z], i))
          {
            sum++;
            cout << inputvector[i][0][z];
          }
        }
      cout << " sum:" << sum << endl;
    }
  }
  else
    cout << "!!!!!!!!!!isnt open!!!!!!!!!!!!";
}