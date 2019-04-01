/*
Problem Link:
https://www.hackerrank.com/challenges/find-the-running-median/problem

Here, we'll use two Heaps, one MinHeap, another MaxHeap... Each will have n/2 elements.

MaxHeap will have the first n/2 of the Sorted List, and MinHeap will have the last n/2 of the Sorted List.

( consider 5 6 1 2 3 8
  MaxHeap = 3 1 2
  MinHeap = 5 6 8
)



*/


#include <bits/stdc++.h>
using namespace std;


#define mac_for(i,s,e) for(int i = s; i<e; i++)


int main()
{
    ios::sync_with_stdio(false);

    priority_queue<double> max_h;
    priority_queue<double> min_h; // We'll insert the Negative of the element so that it will work as Min_Heap.

    double in, temp;
    int n;

    scanf("%d",&n);

    mac_for(i,0,n)
    {
        scanf("%lf",&in);
        if (i!=0)
        {
            if (in < max_h.top())
            {
                max_h.push(in);
                if (max_h.size() - min_h.size() > 1)
                {
                    temp = max_h.top();
                    max_h.pop();
                    min_h.push(-temp);
                }
            }
            else
            {
                min_h.push(-in);
                if (min_h.size() - max_h.size() > 1)
                {
                    temp = min_h.top();
                    min_h.pop();
                    max_h.push(-temp);
                }
            }

            if (max_h.size() == min_h.size())
            {
                printf("%.1f\n",(max_h.top()-min_h.top())/2.0);
            }
            else if (max_h.size()>min_h.size())
            {
                printf("%.1f\n",max_h.top());
            }
            else
            {
                printf("%.1f\n",-min_h.top());
            }

        }
        else
        {
            max_h.push(in);
            printf("%.1f\n",in);
        }
    }

    return 0;
}


