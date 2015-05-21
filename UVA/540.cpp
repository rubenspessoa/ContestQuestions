#include <iostream>
#include <cstdlib>
#include <list>
#include <queue>
#include <map>

#define DEBUG 0
#define D(value) if (DEBUG) cout << value << endl;

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

using namespace std;


class TeamQueue
{
private:
    list<int> myQueue;

    map<int,int> groups;
    map<int,queue<int>* > groupQueue;

public:

	void add_to_group(int number, int group)
	{
		groups[number] = group;
	}

    void push(int number)
    {
    	int numberGroup = groups[number];
    	for(list<int>::iterator it = myQueue.begin();it != myQueue.end();++it)
		{
			if(numberGroup == *it)
			{
				groupQueue[*it]->push(number);
				return;
			}
		}
		groupQueue[numberGroup] = new queue<int>;
		groupQueue[numberGroup]->push(number);
		myQueue.push_back(numberGroup);
    }

    int pop()
    {
    	list<int>::iterator it = myQueue.begin();
    	cout << groupQueue[*it]->front() << endl;
    	groupQueue[*it]->pop();
    	if(groupQueue[*it]->empty())
		{
			myQueue.pop_front();
		}
    }
    friend ostream& operator<< (ostream &os, TeamQueue &obj)
    {
        for(list<int>::iterator it = obj.myQueue.begin(); it != obj.myQueue.end(); ++it)
        {
            os << *it << " ";
        }
        return os;
    }
};

int main()
{
	int scenario = 1;
	int n;
    while(cin >> n)
    {
        if(n == 0)
        {
            return 0;
        }
        TeamQueue teamQueue;
        cout << teamQueue;
        REP(i,0,n)
        {
            int groupSize;
            cin >> groupSize;
            REP(j,0,groupSize )
            {
                int current;
                cin >> current;
                teamQueue.add_to_group(current, i);
            }
        }
        string operation;
        cout << "Scenario #" << scenario++ << endl;
        while(operation[0] != 'S')
        {
            cin >> operation;
            if(operation[0] == 'E')
            {
                int insert;
                cin >> insert;
                teamQueue.push(insert);
            }
            if(operation[0] == 'D')
            {
                teamQueue.pop();
            }
        }
        cout << endl;
    }
}
