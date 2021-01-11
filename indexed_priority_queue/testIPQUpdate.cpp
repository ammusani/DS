// File to test indexed heap update, deleteAt & valueAt

/* 
 * Data Structure   :   Indexed Priority Queue implemented using Indexed Heap
 * Author 	        :   Aliasgar Musani <cs17b004 at iittp dot ac dot in> / <aliasgarmusani at gmail dot com>
 * Institute 	    :   Indian Institute of Technology Tirupati
 * Part of final year BTech Project
 * Professor	    :	Dr. Raghavendra K <raghavendrak at iittp dot ac dot in>
 */

#include<bits/stdc++.h>
#include "indexed_priority_queue.h"

using namespace std;

int main() {
    int n = 100;
    int m = 20;
    I_PQ<int> ipq(n);
    for (int i = 0; i < m; i++) {
        int k = rand() % 100;
        int j = rand() % 100;
        // cout << k << " ";
        ipq.push(i, k + j);
    }
    // cout << endl;
    for (int j = 0; j < m; j++) {
        cout << ipq.valAt(j) << " ";
    }
    cout << endl;

    ipq.updateAt(5, 11);
    for (int j = 0; j < m; j++) {
        if(ipq.checkI(j)) cout << ipq.valAt(j) << " ";
    }
    cout << endl;


    ipq.deleteAt(6);
    for (int j = 0; j < m; j++) {
        if(ipq.checkI(j)) cout << ipq.valAt(j) << " ";
    }
    cout << endl;

    ipq.updateAt(11, 110);
    for (int j = 0; j < m; j++) {
        if(ipq.checkI(j)) cout << ipq.valAt(j) << " ";
    }
    cout << endl;

    ipq.deleteAt(18);
    for (int j = 0; j < m; j++) if(ipq.checkI(j)) cout << ipq.valAt(j) << " ";
    cout << endl;

    int arr[m];
    int i = 0;
    while(!ipq.empty()) arr[i++] = ipq.pop();

    for (int j = 0; j < i; j++) cout << arr[j] << " ";
    cout << endl;

    return 0;
}