#include <iostream>
#include <cstdio>

#define DEBUG 1
#define D(value) if (DEBUG) cout << value;

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

using namespace std;

#define MAX_SIZE 10

char input[MAX_SIZE][MAX_SIZE];
char comparison[MAX_SIZE][MAX_SIZE];
char degree90[MAX_SIZE][MAX_SIZE];
char degree180[MAX_SIZE][MAX_SIZE];
char degree270[MAX_SIZE][MAX_SIZE];
char vertical[MAX_SIZE][MAX_SIZE];

int main()
{
    int patternNumber = 0;
    int n;
    while(cin >> n)
    {
        patternNumber++;
        getchar();
        //L? o input
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                cin >> input[i][j];
            }
            getchar();
            REP(j,0,n)
            {
                cin >> comparison[i][j];
            }
        }
        int aux=0,printed=0;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                if(input[i][j] != comparison[i][j]) aux=1;
                if(aux==1) break;
            }
            if(aux==1) break;
        }
        if(aux==0)
        {
            printed=1;
            cout << "Pattern " << patternNumber << " was preserved."<<endl;
            continue;
        }

        //GIRA O input 90 GRAUS PRA DIREITA E SALVA EM degree90
        int k, l = 0;
        REP(i,0,n)
        {
            k = n - 1;
            REP(j,0,n)
            {
                degree90[i][j] = input[k--][l];
            }
            l++;
        }

        aux=0;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                if(degree90[i][j] != comparison[i][j]) aux=1;
                if(aux==1) break;
            }
            if(aux==1) break;
        }
        if(aux==0)
        {
            printed=1;
            cout << "Pattern " << patternNumber << " was rotated 90 degrees."<<endl;
            continue;
        }

        l = 0;
        REP(i,0,n)
        {
            k = n - 1;
            REP(j,0,n)
            {
                degree180[i][j] = degree90[k--][l];
            }
            l++;
        }

        aux=0;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                if(degree180[i][j] != comparison[i][j]) aux=1;
                if(aux==1) break;
            }
            if(aux==1) break;
        }
        if(aux==0)
        {
            printed=1;
            cout << "Pattern " << patternNumber << " was rotated 180 degrees."<<endl;
            continue;
        }

        l = 0;
        REP(i,0,n)
        {
            k = n - 1;
            REP(j,0,n)
            {
                degree270[i][j] = degree180[k--][l];
            }
            l++;
        }

        aux=0;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                if(degree270[i][j] != comparison[i][j]) aux=1;
                if(aux==1) break;
            }
            if(aux==1) break;
        }
        if(aux==0)
        {
            printed=1;
            cout << "Pattern " << patternNumber << " was rotated 270 degrees."<<endl;
            continue;
        }

        k = n - 1;
        l = 0;
        REP(i,0,n)
        {
            l = 0;
            REP(j,0,n)
            {
                vertical[i][j] = input[k][l++];
            }
            k--;
        }
        aux=0;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                if(vertical[i][j] != comparison[i][j]) aux=1;
                if(aux==1) break;
            }
            if(aux==1) break;
        }
        if(aux==0)
        {
            printed=1;
            cout << "Pattern " << patternNumber << " was reflected vertically."<<endl;
            continue;
        }

        l = 0;
        REP(i,0,n)
        {
            k = n - 1;
            REP(j,0,n)
            {
                degree90[i][j] = vertical[k--][l];
            }
            l++;
        }
        aux=0;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                if(degree90[i][j] != comparison[i][j]) aux=1;
                if(aux==1) break;
            }
            if(aux==1) break;
        }
        if(aux==0)
        {
            printed=1;
            cout << "Pattern " << patternNumber << " was reflected vertically and rotated 90 degrees."<<endl;
            continue;
        }

        l = 0;
        REP(i,0,n)
        {
            k = n - 1;
            REP(j,0,n)
            {
                degree180[i][j] = degree90[k--][l];
            }
            l++;
        }
        aux=0;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                if(degree180[i][j] != comparison[i][j]) aux=1;
                if(aux==1) break;
            }
            if(aux==1) break;
        }
        if(aux==0)
        {
            printed=1;
            cout << "Pattern " << patternNumber << " was reflected vertically and rotated 180 degrees."<<endl;
            continue;
        }

        l = 0;
        REP(i,0,n)
        {
            k = n - 1;
            REP(j,0,n)
            {
                degree270[i][j] = degree180[k--][l];
            }
            l++;
        }
        aux=0;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                if(degree270[i][j] != comparison[i][j]) aux=1;
               if(aux==1) break;
            }
            if(aux==1) break;
        }
        if(aux==0)
        {
            printed=1;
            cout << "Pattern " << patternNumber << " was reflected vertically and rotated 270 degrees."<<endl;
            continue;
        }
        cout << "Pattern " << patternNumber << " was improperly transformed."<<endl;
    }
}
