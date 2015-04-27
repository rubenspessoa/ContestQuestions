#include <iostream>

#define DEBUG 0
#define D(value) if (DEBUG) cout << value << endl;

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

using namespace std;

int main()
{
    int testCase = 1;
    int currentQuest;
    cin >> currentQuest;
    while(currentQuest >= 0)
    {
        cout << "Case " << testCase << ":" << endl;
        int createdQuest[12];
        int usedQuest[12];
        REP(i,0,12)
        {
            cin >> createdQuest[i];
        }
        REP(i,0,12)
        {
            cin >> usedQuest[i];
        }
        REP(i,0,12)
        {
            if(usedQuest[i] <= currentQuest)
            {
                cout << "No problem! :D" << endl;
                currentQuest -= usedQuest[i];
            }
            else
            {
                cout << "No problem. :(" << endl;
            }
            currentQuest += createdQuest[i];
        }
        testCase++;
        cin >> currentQuest;
    }
}
