#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> inputvector;

int main()
{

  ifstream input;
  input.open("day1input.txt");
  string line;
  int x;
  if (input.is_open())
  {
    while (getline(input, line))
    {
      inputvector.push_back(line);
      x++;
    }
    input.close();

    for (int i = 0; i < inputvector.size(); i++)
    {
      for (int u = 0; u < inputvector.size(); u++)
      {
        for (int f = 0; f < inputvector.size(); f++)
        {
          if (stoi(inputvector[i]) + stoi(inputvector[u]) + stoi(inputvector[f]) == 2020)
            cout << inputvector[i] << " * " << inputvector[u] << " * " << inputvector[f] << " = " << (stoi(inputvector[i]) * stoi(inputvector[u]) * stoi(inputvector[f])) << endl;
          // cout << ".-";
        }
      }
    }
  }
  else
  {
    cout << "no!§!§!§!!!!" << endl;
  }
}