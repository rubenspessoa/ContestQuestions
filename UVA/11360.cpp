#include <iostream>
#include <cstdio>
#include <cstdlib>

#define DEBUG 1
#define D(value) if (DEBUG) cout << value << endl;

#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!

using namespace std;

int main()
{
    int t, case1=1;
    cin >> t;
    for(int i = 0 ; i < t ; ++i )
    {
        int n,m;
        cin >> n;
        getchar();
        string matriz[n];
        for(int j = 0 ; j < n ; ++j)
        {
            getline(cin, matriz[j]);
        }
        cin >> m;
        getchar();
        string instruction;
        for(int k = 0 ; k < m ; ++k)
        {
            getline(cin, instruction);
            if(instruction == "transpose")
            {
                char solution[n][n];
                for(int x = 0 ; x < n ; ++x)
                {
                    for(int y = 0 ; y < n ; ++y)
                    {
                        solution[x][y]= matriz[y][x];
                    }
                }
                for(int x = 0 ; x < n ; ++x)
                {
                    for(int y = 0 ; y < n ; ++y)
                    {
                        matriz[x][y] = solution[x][y];
                    }
                }
            }
            else
            {
                string substring = instruction;
                substring = substring.substr(0,3);
                if (substring == "inc")
                {
                    for(int x = 0 ; x < n ; ++x)
                    {
                        for(int y = 0 ; y < n ; ++y)
                        {
                            int aux = matriz[x][y];
                            aux -= 48;
                            aux = (aux + 1) % 10;
                            matriz[x][y] = aux + 48;
                        }
                    }
                }
                else if (substring == "dec")
                {
                    for(int x = 0 ; x < n ; ++x)
                    {
                        for(int y = 0 ; y < n ; ++y)
                        {
                            int aux = matriz[x][y];
                            aux -= 48;
                            aux = aux - 1;
                            if(aux<0) aux = 9;
                            matriz[x][y] = aux + 48;
                        }
                    }

                }
                else if (substring == "col")
                {
                    int x = instruction[4] - 48 - 1;
                    int y = instruction[6] - 48 - 1;
                    char aux;
                    for(int o = 0 ; o < n ; ++o)
                    {
                        aux = matriz[o][x];
                        matriz[o][x] = matriz[o][y];
                        matriz[o][y] = aux;
                    }

                }
                else if (substring == "row")
                {
                    string aux;
                    int x = instruction[4] - 48 - 1;
                    int y = instruction[6] - 48 - 1;
                    aux = matriz[x];
                    matriz[x] = matriz[y];
                    matriz[y] = aux;
                }
            }
        }
        cout << "Case #" << case1 << endl;
        for(int x = 0 ; x < n ; ++x)
        {
            for(int y = 0 ; y < n ; ++y)
            {
                cout << matriz[x][y];
            }
            cout << endl;
        }
        case1++;
        cout << endl;
    }
}
