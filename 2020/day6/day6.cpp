#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string chars = "";
int sum;

bool haha(char i_char) {
        for (size_t i = 0; i < chars.length(); i++)
        {
          if (i_char == chars[i])
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
    vector<string> inputvector;
    vector<string> charsvector;
    vector<int> lengthvector;

    string line;
    string moreline;
    while (getline(input, line))
    {
      if (line.length() > 0)
      {
        moreline += line;
      }
      else
      {
        inputvector.push_back(moreline);
        moreline = "";
      }
    }
    inputvector.push_back(moreline);
    input.close();

    for (size_t i = 0; i < inputvector.size(); i++)
    {
      // cout << inputvector[i] << endl;
      for (size_t u = 0; u < inputvector[i].length(); u++)
      {
        if (haha(inputvector[i][u]))
        {
          chars += inputvector[i][u];
        }
        
      }
      charsvector.push_back(chars);
      chars = "";
    }

    for (size_t u = 0; u < charsvector.size(); u++)
    {
      lengthvector.push_back(charsvector[u].length());
      sum += charsvector[u].length();
      cout << charsvector[u]  << ", (" << charsvector[u].length() << ")" << ", sum:" << sum << endl;
    }
    
  }
  else
    cout << "!!!!!!!!!!isnt open!!!!!!!!!!!!";
}