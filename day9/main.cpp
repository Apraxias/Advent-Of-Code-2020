#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool getStep(vector<long long int> digit, int step)
{
    for (int i = step; i < 25 + step; i++)
    {
        for (int j = i + step + 1; j < 25 + step; j++)
        {
            if (digit[i] + digit[j] == digit[25 + step])
            {
                return false;
            }
        }
    }
    cout << "The incompatible number is" << digit[step+25] << ".";
    return true;
}

int main(void)
{
    fstream ifp;
    ifp.open("input.txt");

    vector<long long int> digits;
    string buffer;
    while (!ifp.eof())
    {
        ifp >> buffer;
        cout << buffer << endl;
        digits.push_back(stoll(buffer));
    }

    int steps = 0;
    while (!ifp.eof())
    {
        if (getStep(digits, steps))
        {
            break;
        }
        steps++;
    }
}