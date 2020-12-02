#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int i, j, k;
    int list_length = 0;
    ifstream ifp;
    char buffer[100];
    vector<int> task;

    ifp.open("input.txt");

    while (!ifp.eof())
    {
        list_length++;
        ifp >> buffer;
        task.push_back(stoi(buffer));
    }
    for (i = 0; i < list_length; i++)
    {
        for (j = i; j < list_length; j++)
        {
            for (k = j; k < list_length; k++)
            {
                if (task[i] + task[j] + task[k] == 2020)
                {
                    cout << "Solution found" << task[i] << " + " << task[j] << " + " << task[k] << " = 2020." << endl;
                    cout << task[i] << " * " << task[j] << " * " << task[k] << " = " << task[i] * task[j] * task[k] << endl;
                }
            }
        }
    }
    return 0;
}