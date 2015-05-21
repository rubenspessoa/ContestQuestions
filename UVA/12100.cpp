#include <iostream>
#include <list>

#define DEBUG 1
#define D(value) if (DEBUG) cout << value << endl;

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

using namespace std;

class Job
{
	public:
		int priority;
	Job(int p, bool myJob = false)
	{
		this->priority = p;
		this->myJob = myJob;
	}
	bool myJob;
};

class myPQ
{
	list<Job> queue;
	public:
	void push(Job current)
	{
		queue.push_back(current);
	}
	void pop()
	{
		bool printed = false;
		int timer = 0;
		while(!printed)
		{
			bool found = false;
			for(list<Job>::iterator it = queue.begin();it != queue.end();++it)
			{
				if(queue.front().priority < it->priority)
				{
					found = true;
					queue.push_back(queue.front());
					queue.pop_front();
					break;
				}
			}
			if(!found)
			{
				if(queue.front().myJob)
				{
					cout << ++timer << endl;
					printed = true;
				}
				else
				{
					queue.pop_front();
					timer++;
				}
			}
		}

	}
};

int main()
{
    int testCases;
    cin >> testCases;
    REP(i,0,testCases)
    {
		int n, m;
		cin >> n >> m;
		myPQ pq;
		REP(j,0,n)
		{
			int currentPriority;
			cin >> currentPriority;
			Job *current;
			if(j == m)
			{
				current = new Job(currentPriority, true);
			}
			else
			{
				current = new Job(currentPriority);
			}
			pq.push(*current);
		}
		pq.pop();
    }
}
