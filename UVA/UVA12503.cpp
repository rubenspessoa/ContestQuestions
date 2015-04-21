#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main ()
{
    int t;
    cin >> t;
    for(int i=0; i<t ; ++i)
    {
        int n, p=0;
        cin >> n;
        int instructions[n];
        string instruction;
        getchar();
        for(int j=0; j < n ; ++j)
        {
            getline(cin,instruction);
            if(instruction == "LEFT")
            {
                instructions[j] = -1;
            }
            else if(instruction == "RIGHT")
            {
                instructions[j] = 1;
            }
            else
            {
                if(instruction.length()==9)
                {
                    char aux[2];
                    aux[0] = instruction[8];
                    aux[1] = '\0';
                    instructions[j] = instructions[atoi(aux)-1];
                }
                else
                {
                    char aux[3];
                    aux[0] = instruction[8];
                    aux[1] = instruction[9];
                    aux[2] = '\0';
                    instructions[j] = instructions[atoi(aux)-1];
                }
            }
            p = p + instructions[j];
        }
        cout << p << endl;
    }
}
