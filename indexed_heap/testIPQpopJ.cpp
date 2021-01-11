// File to test Normal heap push, popJ, topJ

#include<bits/stdc++.h>
#include "indexed_heap.h"

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

    pair<int, double> k = ipq.topJ();
    cout << k.first << " " << k.second << endl << endl;

    vector<pair<int, double>> arr;
    int i = 0;
    while(!ipq.empty()) {
        // cout << ipq.pop() << " ";
        arr.push_back(ipq.popJ());
        i++;
    }
    cout << endl;
    for (int j = 0; j < i; j++) cout << arr[j].first << " " << arr[j].second << endl;
    cout << endl;
    return 0;
}