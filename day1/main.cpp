#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int i, j;
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
            if (task[i] + task[j] == 2020)
            {
                cout << "solution found" << task[i] << " + " << task[j] << " = 2020." << endl;
                cout << task[i] << " * " << task[j] << " = " << task[i] * task[j] << endl;
            }
        }
    }

    return 0;
}