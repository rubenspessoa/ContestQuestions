#include <iostream>
#include <stack>
#include <list>

#define DEBUG 0
#define D(value) if (DEBUG) cout << value << endl;
#define REP(i, a, b) \
   for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

using namespace std;


int verify_order(int n) {
	stack<int> station;
    int coach_position = 1;

    int coach;
    cin >> coach;

    if (coach == 0) {
    	return 2;
    }

    if (coach == 1) {

    	coach_position = coach + 1;

    	REP(i, 1, n) {
			cin >> coach;
	    	if (coach >= coach_position) {

		    	REP(i, coach_position, coach + 1) {
					station.push(i);
		    	}

		    	coach_position = coach + 1;
	    		station.pop();

	    	} else {

	    		if (coach == station.top()) {
	    			station.pop();
	    		}
	    	}
    	}	

    } else {

    	if (coach >= coach_position) {

	    	REP(i, coach_position, coach + 1) {
				station.push(i);
	    	}

	    	coach_position = coach + 1;
    		station.pop();

    	} else {

    		if (coach == station.top()) {
    			station.pop();
    		}
    	}

    	REP(i, 1, n) {
    		cin >> coach;
	    	if (coach >= coach_position) {

		    	REP(i, coach_position, coach + 1) {
					station.push(i);
		    	}

		    	coach_position = coach + 1;
	    		station.pop();

	    	} else {

	    		if (coach == station.top()) {
	    			station.pop();
	    		}
	    	}
		}	
    }

    if (!station.empty()) {
		return 0;
	}
	return 1;
}

int main() {

	int n;

	while (cin >> n) {
		
		if (n == 0) {
			break;
		}

	    while (1) {
	    	int ans = verify_order(n);
	    	if (ans == 1) {
	    		cout << "Yes" << endl;
	    	} else if (ans == 0){
	    		cout << "No" << endl;
	    	} else {
	    		break;
	    	}
	    }

	    cout << endl;
	}

	D("acabou");

}