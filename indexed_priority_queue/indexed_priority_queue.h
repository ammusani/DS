// This is an indexed priority queue implemented using Indexed D-Heap (min)

/* 
 * Data Structure 	:	Indexed Priority Queue
 * Author 	        : 	Aliasgar Musani <cs17b004 at iittp dot ac dot in>
 * Institute 	    :	Indian Institute of Technology Tirupati
 * As a part of final year BTech Project
 * Professor	    :	Dr. Raghavendra K <raghavendrak at iittp dot ac dot in>
 */

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class I_PQ {
    
    private:

        /* Max size of the heap
         * */
        int mSz;

        /* Current size of the heap
         * */       
        int cSz;

        /* Degree of each node
         * */
        int D;

        /* Look up arrays to track child/parent of node
        */
        int *child;           
        int *parent;

        /* Generic value data type that store the values
         * */
        T *vals;

        /* Position map maps key indexes (kI) to position of that key,
         * represented in the priority queue in the domain [0, sz).
         * */
        int *posM;

        /* Inverse look up Map, 
         * stores key from range [0, cSz)
         * */
        int *invM; 

        /* Note: 
         * invM[posM[i]] = i
         * i.e. invM and posM are inverse of each other
         * */

    public:

        /* Construction function for D-arry Heap
         * */
        I_PQ (int maxS, int dVal) {
            D = max(2, dVal);
            mSz = max(maxS, D + 1);
            cSz = 0;

            child = (int *)malloc(sizeof(int) * mSz);
            parent = (int *)malloc(sizeof(int) * mSz);
            vals = (T *)malloc(sizeof(T) * mSz);
            posM = (int *)malloc(sizeof(int) * mSz);
            invM = (int *)malloc(sizeof(int) * mSz);

            for (int i = 0; i < mSz; i++) {
                parent[i] = (i - 1) / D;
                child[i] = i * D + 1;
                posM[i] = -1;
                invM[i] = -1;
            }            

        }

        /* Construction function for binary Heap
         * */
        I_PQ (int maxS) {
            mSz = max(3, maxS);
            D = 2;
            cSz = 0;

            child = (int *)malloc(sizeof(int) * mSz);
            parent = (int *)malloc(sizeof(int) * mSz);
            vals = (T *)malloc(sizeof(T) * mSz);
            posM = (int *)malloc(sizeof(int) * mSz);
            invM = (int *)malloc(sizeof(int) * mSz);

            for (int i = 0; i < mSz; i++) {
                parent[i] = (i - 1) / D;
                child[i] = i * D + 1;
                posM[i] = -1;
                invM[i] = -1;
            }
        }

        /* returns current size of the heap
         * */
        int currSize () {
            return cSz;
        }

        /* returns max size of the heap
         * */
        int maxSize () {
            return mSz;
        }

        /* returns true if the heap is empty
         * */
        bool empty () {
            return cSz ? false : true;
        }

        /* returns true if an instance is present
         * */ 
        bool checkI (int kI) {
            // cout << kI << " ";
            boundsCheck(kI);
            return posM[kI] == -1 ? false : true;
        }

        /* Check key at zero-th position
         * */
        int topI () {
            emptyCheck();
            return invM[0];
        }

        /* pop top index
         * */
        int popI () {
            int topKI = topI();
            deleteAt(topKI);
            return topKI;
        }

        /* top value
         * */
        T top () {
            int topKI = topI();
            return vals[topKI];
        }

        /* pop top value
         * */
        T pop () {
            int topKI = topI();
            T topVal = vals[topKI];
            deleteAt(topKI);
            // for (int l = 0; l <= cSz; l++)
            //     cout << l << " "  << vals[l] << " " << posM[l] << " " << invM[l] << endl;
            // cout << endl;
            return topVal;
        }

        /* top key + value
         * */
        pair<int, T>  topJ () {
            int topKI = topI();
            return make_pair(topKI, vals[topKI]);
        }

        /* pop top key + value
         * */
        pair<int, T> popJ () {
            int topKI = topI();
            T topVal = vals[topKI];
            deleteAt(topKI);
            // for (int l = 0; l <= cSz; l++)
            //     cout << l << " "  << vals[l] << " " << posM[l] << " " << invM[l] << endl;
            // cout << endl;
            return make_pair(topKI, topVal);
        }

        /* To insert new values
         * */
        void push (int kI, T val) {
            absenceCheck(kI);
            // valueCheck(val);
            posM[kI] = cSz;
            invM[cSz] = kI;
            // cout << cSz << endl;
            vals[kI] = val;
            bubble_up(cSz);
            // for (int l = 0; l <= cSz; l++)
            //     cout << l << " "  << vals[l] << " " << posM[l] << " " << invM[l] << endl;
            // cout << endl;
            cSz++;
        }

        /* To get value of a particular key
         * */
        T valAt (int kI) {
            presenceCheck(kI);
            return vals[kI];
        }

        /* To delete at a given location
         * */
        T deleteAt (int kI) {
            presenceCheck(kI);
            T val = vals[kI];
            int i = posM[kI];
            cSz--;
            swap(i, cSz);
            bubble_down(i);
            // bubble_up(i);
            posM[kI] = -1;
            invM[cSz] = -1;
            // for (int l = 0; l <= cSz; l++)
            //     cout << l << " "  << vals[l] << " " << posM[l] << " " << invM[l] << endl;
            // cout << endl;
            return val;

        }

        /* To update at a given location
         * */
        T updateAt (int kI, int val) {
            presenceCheck(kI);
            // valueCheck(val);
            int i = posM[kI];
            T oldVal = vals[kI];
            vals[kI] = val;
            bubble_down(i);
            bubble_up(i);
            // for (int l = 0; l <= cSz; l++)
            //     cout << l << " "  << vals[l] << " " << posM[l] << " " << invM[l] << endl;
            // cout << endl;
            return oldVal;
        }

        /* To strictly increase
         * */
        void increase (int kI, int val) {
            presenceCheck(kI);
            // valueCheck(val);
            if (vals[kI] < val) {
                vals[kI] = val;
                bubble_down(posM[kI]);
            }
        }

        /* To strictly decrease
         * */
        void decrease (int kI, int val) {
            presenceCheck(kI);
            // valueCheck(val);
            if (vals[kI] > val) {
                vals[kI] = val;
                bubble_up(posM[kI]);
            }
        }
    
    private:

        /* bubble down the values
         * */
        void bubble_down (int i) {
            int j = minChild(i);
            while (j != -1) {
                swap(i, j);
                i = j;
                j = minChild(i);
            }
        }

        /* bubble up the values
         * */
        void bubble_up (int i) {
            while (less(i,  parent[i])) {
                swap(i, parent[i]);
                i = parent[i];
            }
        }

        /* find the minChild
         * */
        int minChild (int i) {
            int index = -1;
            int j = child[i];
            int k = child[i] + D;
            while(j < cSz && j < k) {
                if (less(j, i)) {
                    index = j;
                    i = j;
                }
                j++;
            }
            return index;
        }

        /* swap function
         * */
        void swap (int i, int j) {
            posM[invM[j]] = i;
            posM[invM[i]] = j;
            int tmp = invM[i];
            invM[i] = invM[j];
            invM[j] = tmp;
        }

        bool less (int i, int j) {
            return vals[invM[i]] < vals[invM[j]];
        }

        /*
         * Error Functions
         * */
        void presenceCheck (int i) {
            if (!checkI(i)) {
                cout << "kI value = " << i << " not present in the PQ" << endl;
                exit(-1);
            }
        }

        void absenceCheck (int i) {
            if (checkI(i)) {
                cout << "kI value = " << i << " already present in the PQ" << endl;
                exit(-1);
            }
        }

        // void valueCheck (T val) {
        //     if (val == NULL) {
        //         cout << "Value pushed in the PQ is null" << endl;
        //         exit(-1);
        //     }
        // }

        void emptyCheck() {
            if (!cSz) {
                cout << "PQ is empty" << endl;
                exit(-1);
            }
        }

        void boundsCheck(int kI) {
            if (kI > mSz || kI < 0) {
                cout << "Index out of bounds" << endl;
                exit(-1);
            }
        }
};