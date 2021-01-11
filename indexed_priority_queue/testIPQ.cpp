// File to test Normal heap push and pop

/* 
 * Data Structure 	:	Indexed Priority Queue
 * Author 	        : 	Aliasgar Musani <cs17b004 at iittp dot ac dot in>
 * Institute 	    :	Indian Institute of Technology Tirupati
 * As a part of final year BTech Project
 * Professor	    :	Dr. Raghavendra K <raghavendrak at iittp dot ac dot in>
 */

#include<bits/stdc++.h>
#include "indexed_priority_queue.h"

using namespace std;

int main() {
    int n = 100;
    int m = 20;
    I_PQ<double> ipq(n);
    for (int i = 0; i < m; i++) {
        int k = rand() % 100;
        int j = rand() % 100;
        // cout << k << " ";
        ipq.push(i, (double) k / j);
    }
    // cout << endl;

    double arr[m];
    int i = 0;
    while(!ipq.empty()) {
        // cout << ipq.pop() << " ";
        arr[i] = ipq.pop();
        i++;
    }
    cout << endl;
    for (int j = 0; j < i; j++) cout << arr[j] << " ";
    cout << endl;
    return 0;
}