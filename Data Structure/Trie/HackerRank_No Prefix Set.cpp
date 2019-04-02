
/*
Problem Link:
https://www.hackerrank.com/challenges/no-prefix-set/problem

The idea is simple. Either the given string is already a Prefix or some other string is Prefix of the given string. Using Trie and some boolean variables, it can easily be solved.

*/

#include <bits/stdc++.h>
using namespace std;

/*
    Here, we are allocating each Trie node with "new".
    Allocating each node with "new" consumes some time.
    Instead of allocating each node, it is possible to use a global 2D Array.
*/
typedef struct TRIE
{
    bool EndMark, DoesHaveChild;
    struct TRIE* next[10];
    TRIE()
    {
        for (int i=0; i<10; i++)
            next[i]=NULL;
        EndMark = DoesHaveChild = 0;
    }
} trie;

trie* Root=NULL;

bool IsBad=0;
string BADSET;

void Insert(string A)
{
    int l=A.length();

    trie *curr;
    curr=Root;

    for (int i=0; i<l; i++)
    {
        (*curr).DoesHaveChild=1;

        if ((*curr).next[A[i]-'a']==NULL)
            (*curr).next[A[i]-'a']=new trie;

        curr=(*curr).next[A[i]-'a'];


        if ((*curr).EndMark==1 && IsBad==0) // We've just ended up with a Prefix.
        {
            IsBad=1;
            BADSET = A;
        }
    }
    (*curr).EndMark=1;

    if ((*curr).DoesHaveChild && IsBad==0) // String has been Inserted, but this String is Prefix of other string.
    {
          IsBad=1;
          BADSET = A;
    }

}


trie* Search(string A)
{

    trie *curr=Root;

    int l= A.length();

    for (int i=0; i<l; i++)
    {
        if ((*curr).next[A[i]-'a']==NULL)
            return 0;

        else curr=(*curr).next[A[i]-'a'];
    }

    return curr; // Any non
}




int main()
{
    ios::sync_with_stdio(false);

    Root=new trie;
    string Temp;

    int n;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        cin>>Temp;
        Insert(Temp);
    }

    if (IsBad==0)
        cout<<"GOOD SET\n";
    else
        cout<<"BAD SET\n"<<BADSET<<"\n";


    return 0;
}
