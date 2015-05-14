#include <iostream>
#include <algorithm>
#include <cstring>

#define DEBUG 0
#define D(value) if (DEBUG) cout << value << endl;

#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!

using namespace std;

int main()
{
    string current;
    getline(cin,current);
    while(current.compare("#") != 0)
    {
    	char *c_str = (char*) const_cast<char*> (current.c_str());
        if(next_permutation(c_str,c_str + strlen(c_str)))
			cout << c_str << endl;
		else
			cout << "No Successor" << endl;
        getline(cin,current);
    }
}
