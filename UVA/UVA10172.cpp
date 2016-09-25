#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#define DEBUG 0
#define D(value) if (DEBUG) cout << value << endl;

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

using namespace std;

int main() {

	int SET;
	cin >> SET;

	int stations_size, carrier_size, platb_size;
	
	REP(k, 0, SET) {
		int time_count = 0;

		cin >> stations_size;
		cin >> carrier_size;
		cin >> platb_size;

		queue<int> circularQueue[100];
		stack<int> carrier;
		
		REP(i, 0, stations_size) {
			int qtd_queued_cargoes;
			cin >> qtd_queued_cargoes;

			REP(j, 0, qtd_queued_cargoes) {
				int dest_cargo;
				cin >> dest_cargo;
				circularQueue[i].push(dest_cargo - 1);
			}
		}

		int first_cq = 0;

		while(true) {
			
			while (!carrier.empty() && (carrier.top() == first_cq || circularQueue[first_cq].size() < platb_size)) {
				if(carrier.top() != first_cq) {
					circularQueue[first_cq].push(carrier.top());
				}
				carrier.pop();
				time_count++;
			}

			while (!circularQueue[first_cq].empty() && carrier.size() < carrier_size) {
				carrier.push(circularQueue[first_cq].front());
				circularQueue[first_cq].pop();
				time_count++;
			}

			bool done = carrier.empty();

			REP(i, 0, stations_size) {
				done &= circularQueue[i].empty();
			}

			if(done) {
				break;
			}

			first_cq = (first_cq + 1) % stations_size;
			time_count += 2;
		}
		cout << time_count << endl;
	}

	
}