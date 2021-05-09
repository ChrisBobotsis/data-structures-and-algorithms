#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
	int size, parent, rank;
	
	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	int max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	int getParent(int table) {
		// find parent and compress path

		int i = table;

		if (i != sets[i].parent) {

			sets[i].parent = getParent(sets[i].parent);
		}

		return sets[i].parent;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
			// merge two components
			if (sets[realDestination].rank > sets[realSource].rank) {

				sets[realSource].parent = realDestination;
				
				sets[realDestination].rank += sets[realSource].rank;
				sets[realSource].rank = 0;
			}

			else {

				sets[realDestination].parent = realSource;
				//cout << sets[realSource].rank << endl;
				sets[realSource].rank += sets[realDestination].rank;
				//cout << sets[realSource].rank << endl;
				sets[realDestination].rank = 0;
				/*if (sets[realDestination].rank == sets[realSource].rank) {


				}*/
			}

			// use union by rank heuristic
                        // update max_table_size
			
			int possible_max_rank = max(sets[realDestination].rank, sets[realSource].rank);
			//cout << possible_max_rank << endl;
			max_table_size = max(max_table_size, possible_max_rank);
		}		
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		table.rank = table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++) {
		int destination, source;
		cin >> destination >> source;
                --destination;
                --source;
		
		tables.merge(destination, source);
	        cout << tables.max_table_size << endl;
	}

	return 0;
}
