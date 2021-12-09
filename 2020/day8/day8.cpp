#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int acc = 0;
int stepped = 0;

class object
{
public:
  string s;
  bool used;
};
vector<object> inputvector;

void step(int line)
{
  stepped++;
  if (!inputvector[line].used)
  {
    inputvector[line].used = 1;
    if (inputvector[line].s.substr(0, inputvector[line].s.find(' ')) == "acc")
    {
      acc += stoi(inputvector[line].s.substr(inputvector[line].s.find(' ')));
      cout << stepped << ". " << line+1 << "-acc " << stoi(inputvector[line].s.substr(inputvector[line].s.find(' '))) << endl;
      step(line + 1);
    }
    else if (inputvector[line].s.substr(0, inputvector[line].s.find(' ')) == "jmp")
    {
      cout << stepped << ". " << line+1 << "-jmp " << stoi(inputvector[line].s.substr(inputvector[line].s.find(' '))) << endl;
      step(line + stoi(inputvector[line].s.substr(inputvector[line].s.find(' '))));
    }
    else
    {
      if (inputvector[line].s.substr(0, inputvector[line].s.find(' ')) != "nop")
      {
        cout << stepped << ". " << line+1 << "-NOT 'nop'?! ... welp that sucks." << endl;
        step(line + 1);
      }
      else
      {
        cout << stepped << ". " << line+1 << "-nop." << endl;
        step(line + 1);
      }
    }
  }
  else
    cout << "finished, when trying to repeat line " << line << ", acc = " << acc << endl;
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
    step(0);
  }
  else
  {
    cout << "input not open" << endl;
  }
}