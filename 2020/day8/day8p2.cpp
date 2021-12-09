#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int acc = 0;
int stepped = 0;
int repeats = 0;

class object
{
public:
  string s;
  bool used;
};
vector<object> inputvector;

void step(int line)
{
  if (line == inputvector.size())
  {
    cout << "finished with acc of: " << acc << endl;
    exit(0);
  }

  stepped++;
  if (!inputvector[line].used)
  {
    inputvector[line].used = 1;
    if (inputvector[line].s.substr(0, inputvector[line].s.find(' ')) == "acc")
    {
      acc += stoi(inputvector[line].s.substr(inputvector[line].s.find(' ')));
      cout << repeats << "r, " << stepped << ". " << line + 1 << "-acc " << stoi(inputvector[line].s.substr(inputvector[line].s.find(' '))) << endl;
      step(line + 1);
    }
    else if (inputvector[line].s.substr(0, inputvector[line].s.find(' ')) == "jmp")
    {
      cout << repeats << "r, " << stepped << ". " << line + 1 << "-jmp " << stoi(inputvector[line].s.substr(inputvector[line].s.find(' '))) << endl;
      step(line + stoi(inputvector[line].s.substr(inputvector[line].s.find(' '))));
    }
    else
    {
      if (inputvector[line].s.substr(0, inputvector[line].s.find(' ')) != "nop")
      {
        cout << repeats << "r, " << stepped << ". " << line + 1 << "-NOT 'nop'?! ... welp that sucks. --> '" << inputvector[line].s << "'" << endl;
        step(line + 1);
      }
      else
      {
        cout << repeats << "r, " << stepped << ". " << line + 1 << "-nop." << endl;
        step(line + 1);
      }
    }
  }
  else
    cout << "changed, when trying to repeat line " << line << ", acc = " << acc << endl;
}
int main()
{
  ifstream input;
  input.open("day8input.txt");
  if (input.is_open())
  {
    string line;
    while (getline(input, line))
    {
      inputvector.push_back(object{line, 0});
    }
    input.close();
    for (size_t LastChanged = 0; LastChanged < inputvector.size() - 1; LastChanged++)
    {
      for (int i = 0; i < inputvector.size(); i++)
      {
        inputvector[i].used = 0;
      }
      stepped = 0;
      acc = 0;
      if (LastChanged > 0)
      {
        if (inputvector[LastChanged - 1].s.substr(0, inputvector[LastChanged - 1].s.find(' ')) == "jmp")
        {
          inputvector[LastChanged - 1].s = "nop  " + inputvector[LastChanged - 1].s.substr(inputvector[LastChanged - 1].s.find(' '));
        }
        else if (inputvector[LastChanged - 1].s.substr(0, inputvector[LastChanged - 1].s.find(' ')) == "nop")
        {
          inputvector[LastChanged - 1].s = "jmp " + inputvector[LastChanged - 1].s.substr(inputvector[LastChanged - 1].s.find(' '));
        }
      }

      if (inputvector[LastChanged].s.substr(0, inputvector[LastChanged].s.find(' ')) == "jmp")
      {
        inputvector[LastChanged].s = "nop " + inputvector[LastChanged].s.substr(inputvector[LastChanged].s.find(' '));
      }
      else if (inputvector[LastChanged].s.substr(0, inputvector[LastChanged].s.find(' ')) == "nop")
      {
        // cout << "'" << inputvector[LastChanged].s << "'" << endl;
        // cout << inputvector[LastChanged].s.find(' ') << endl;
        // cout << inputvector[LastChanged].s.substr(inputvector[LastChanged].s.find(' ')) << endl;
        inputvector[LastChanged].s = "jmp " + inputvector[LastChanged].s.substr(inputvector[LastChanged].s.find(' '));
      }

      repeats++;
      step(0);
    }
  }
  else
  {
    cout << "input not open" << endl;
  }
}