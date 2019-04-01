/*
Problem Link:
http://acm.timus.ru/problem.aspx?space=1&num=1671

This problem can be solved easily using DSJ.

Think the problem as in a reversed way.
You are adding each edge to an existing Web which reduces the number of components. How much reduces is the answer for this problem.

*/


#include <bits/stdc++.h>
using namespace std;


int Parent[100000+2];
int Size[100000+2];
bool is_connected[100000+2];
int number_of_components;

int get_root(int element)
{
    while(Parent[element] != element)
    {
        Parent[element] = Parent[Parent[element]]; // Path Compression
        element = Parent[element];
    }
    return element;
}

void do_union(int A, int B)
{
    int root_A, root_B;
    root_A = get_root(A);
    root_B = get_root(B);

    if (root_A == root_B) // same set.
        return;

    else if (Size[root_A] < Size[root_B]) // B Set is very Big, so change A's root
    {
        Size[root_B] += Size[root_A]; // Ranking
        Parent[root_A] = root_B;
    }
    else
    {
        Size[root_A] += Size[root_B];
        Parent[root_B] = root_A;
    }

    number_of_components--;
}

void init_dsu()
{
    for (int i=0; i<100000+5; i++)
    {
        Parent[i] = i;
        Size[i] = 1;
    }
}


vector < pair <int,int> > cobweb;
vector <int> cut_edge;
vector <int> result;


int main()
{
    ios::sync_with_stdio(false);

    init_dsu();
    memset(is_connected, 1, sizeof(is_connected));

    int n,m,q,temp1,temp2;

    cin>>n>>m;
    number_of_components = n;

    for (int i=0; i<m; i++)
    {
        cin>>temp1>>temp2;
        cobweb.push_back(make_pair(temp1-1, temp2-1));
    }

    cin>>q;
    for (int i=0; i<q; i++)
    {
        cin>>temp1;
        cut_edge.push_back(temp1-1);
        is_connected[temp1-1] = false;
    }

    for (int i=0; i<m; i++)
    {
        if (is_connected[i])
            do_union(cobweb[i].first, cobweb[i].second);
    }
    result.push_back(number_of_components);

    for (int i=q-1; i>0; i--)
    {
        do_union(cobweb[cut_edge[i]].first, cobweb[cut_edge[i]].second);
        result.push_back(number_of_components);
    }

    for (int i=q-1; i>=0; i--)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}
