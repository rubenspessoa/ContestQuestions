#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <list>
#include <queue>
#define DEBUG 1
#define D(value) if (DEBUG) cout << value << endl;

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

using namespace std;

int dist(int a, int b)
{
    return fabs(a - b);
}

int minimumDistance(string current)
{
    int minimum = dist(current[0], current[1]);
    REP(i,1,current.length() - 1)
    {
        if(dist(current[i],current[i+1]) < minimum)
        {
            minimum = dist(current[i],current[i+1]);
        }
    }
    return minimum;
}

class stringWithDist
{
public:
    string word;
    int dist;
};

int main()
{
    string current;
    while(getline(cin,current))
    {
        list<stringWithDist> permutations;
        char *c_str = (char*) const_cast<char*> (current.c_str());
        int biggest = -99999;
        stringWithDist toAdd;
        toAdd.word = string(c_str);
        toAdd.dist = minimumDistance(toAdd.word);
        permutations.push_front(toAdd);
        if(toAdd.dist > biggest)
        {
            biggest = toAdd.dist;
        }
        REP(i,0,10)
        {
            if(next_permutation(c_str,c_str + strlen(c_str)))
            {
                stringWithDist toAdd;
                toAdd.word = string(c_str);
                toAdd.dist = minimumDistance(toAdd.word);
                permutations.push_front(toAdd);
                if(toAdd.dist > biggest)
                {
                    biggest = toAdd.dist;
                }
                D(i << " " <<string(c_str) << minimumDistance(string(c_str)));
            }
            else
            {
                D("break");
                break;
            }

        }
        c_str = (char*) const_cast<char*> (current.c_str());
        REP(i,0,10)
        {
            if(prev_permutation(c_str,c_str + strlen(c_str)))
            {
                stringWithDist toAdd;
                toAdd.word = string(c_str);
                toAdd.dist = minimumDistance(toAdd.word);
                permutations.push_front(toAdd);
                if(toAdd.dist > biggest)
                {
                    biggest = toAdd.dist;
                }
                D(i << " " << string(c_str) << minimumDistance(string(c_str)));
            }
            else
            {
                D("break");
                break;
            }

        }
        priority_queue<string> lexicographical;
        for(list<stringWithDist>::iterator it = permutations.begin(); it != permutations.end(); ++it)
        {
            if(it->dist == biggest)
            {
                lexicographical.push(it->word);
            }
        }
        string last;
        while(!lexicographical.empty())
        {
            last = lexicographical.top();
            lexicographical.pop();
        }
        cout << last << biggest << endl;
    }
}
