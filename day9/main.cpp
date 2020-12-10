#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool getStep(vector<long long int> digit, int step)
{
    int incomp;
    for (int i = step; i < 25 + step; i++)
    {
        for (int j = i + 1; j < 25 + step; j++)
        {
            if (digit[i] + digit[j] == digit[25 + step])
            {
                return false;
            }
        }
    }

    incomp = digit[step + 25];
    cout << "The incompatible number is " << incomp << "." << endl;

    int total = 0;
    int highest = 0;
    for (int start = 0; start < step + 25; start++)
    {
        for (int end = start; end < step + 25; end++)
        {
            total += digit[end];
            if (total == incomp)
            {
                for (int k = start; k < end + 1; k++)
                {
                    if (digit[k] > highest)
                    {
                        highest = digit[k];
                    }
                    if (digit[k] < incomp)
                    {
                        incomp = digit[k];
                    }
                }
                cout << "The sum of odds is " << highest << " + " << incomp << " = " << highest + incomp << ".";
                return true;
            }
            if (total > incomp)
            {
                break;
            }
        }
        total = 0;
    }
    return false;
}

int main(void)
{
    fstream ifp;
    ifp.open("input.txt");

    vector<long long int> digits;
    string buffer;
    int steps = 0;
    while (!ifp.eof())
    {
        ifp >> buffer;
        digits.push_back(stoll(buffer));
        if (digits.size() > 25)
        {
            if (getStep(digits, steps))
            {
                break;
            }
            steps++;
        }
    }
}