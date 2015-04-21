#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int main()
{
   int L;
   cin >> L;
   while (L != 0)
   {
        string highway;
        int dist=0, start=0, mindist=INT_MAX;
        getchar();
        getline(cin,highway);
        for(int i = 0 ; i < highway.length() ; ++i)
        {
            if(highway[i] == 'Z')
            {
                mindist=0;
                break;
            }
            else if(highway[i] == '.' && start!=0)
            {
                dist++;
            }
            else if(highway[i] == 'R')
            {
                if(start==2)
                {
                    if(dist < mindist) mindist=dist;
                    start=1;
                    dist=1;
                }
                else
                {
                    start=1;
                    dist=1;
                }
            }
            else if(highway[i] == 'D')
            {
                if(start==1)
                {
                    if(dist < mindist) mindist=dist;
                    start=2;
                    dist=1;
                }
                else
                {
                    start=2;
                    dist=1;
                }
            }
        }
        cout << mindist << endl;
        cin >> L;
   }

}
