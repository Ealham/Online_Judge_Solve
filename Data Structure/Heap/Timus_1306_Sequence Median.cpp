/*

Problem Link:
http://acm.timus.ru/problem.aspx?space=1&num=1306

This problem is quite difficult due to limit of the memory.

It can be solved using Min-Heap. (Don't use STL, as it causes MLE).

We'll always maintain Ceil(n/2) elements in our heap. As soon as new element arrives, we push it in Heap and Extract The Min.

*/


#include <bits/stdc++.h>
using namespace std;


#define mac_for(i,s,e) for(int i = s; i<e; i++)


int HeapSize;



void Heap_Insert(int Heap[], int num)
{
    HeapSize++;
    Heap[HeapSize] = num;

    int curr, parent;

    curr = HeapSize;
    parent = curr/2;

    while(parent && Heap[curr] < Heap[parent])
    {
        swap(Heap[parent], Heap[curr]);

        curr = parent;
        parent = parent/2;
    }

//    for (int i=1; i<=HeapSize; i++)
//        cout<<Heap[i]<<" ";
//    cout<<"\n";
}


void Extract_Min(int Heap[])
{
    int to_delete = Heap[1];

    Heap[1] = Heap[HeapSize]; // The last element is in the root now.
    HeapSize--;

    int parent, l_c, r_c;

    parent = 1;
    l_c = 2*parent;
    r_c= 2*parent + 1;


    int child_ind;
    // Now fixing the tree
    while(true)
    {
        if (l_c <= HeapSize && r_c <= HeapSize) // Both child exists
        {
            if (Heap[l_c] < Heap[r_c])
                child_ind = l_c;
            else
                child_ind = r_c;
        }
        else if (l_c <= HeapSize)
            child_ind = l_c;
        else if (r_c <= HeapSize)
            child_ind = r_c;
        else
            break;


        if (Heap[parent] > Heap[child_ind])
            swap(Heap[parent],Heap[child_ind]);
        else
            break;

        parent = child_ind;
        l_c = 2*parent;
        r_c= 2*parent + 1;
    }

}




int main()
{
    ios::sync_with_stdio(false);

    int n, temp;
    cin>>n;

    int Heap[n/2+1+1]; // We'll store n/2+1 (n-even) and n/2+2 (n-odd) at most. +1 since Heap[0] not used.

    cout<<setprecision(1)<<fixed; // We need to print EXACTLY ONE digit after decimal.

    if (n & 1) // For odd number of elements
    {
        mac_for(i,0,n)
        {
            cin>>temp;
            Heap_Insert(Heap,temp);

            if (i > n/2) {// If we have 5 elements, we'll store only 3 elements. As soon as we store 4th element, we Extract.
                //cout<<Heap[1]<<" has been extracted\n";
                Extract_Min(Heap);
            }

        }
        cout<<Heap[1];

    }
    else // Even number of elements
    {
        unsigned first, second; // Sum of two Signed Int will cause Overflow.

        mac_for(i,0,n)
        {
            cin>>temp;
            Heap_Insert(Heap,temp);

            if (i > n/2) {// If we have 6 elements, we'll store only 3 elements. As soon as we store 4th element, we Extract.
                //cout<<Heap[1]<<" has been extracted\n";
                Extract_Min(Heap);
            }
        }

        first = Heap[1];
        Extract_Min(Heap);
        second = Heap[1];

        cout<<(first+second)/2.0;
    }

    return 0;
}
