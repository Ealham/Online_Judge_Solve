/*

Problem Link
http://acm.timus.ru/problem.aspx?space=1&num=1048

*/



#include <bits/stdc++.h>
using namespace std;

#define mac_for(i,s,e) for(int i = s; i<e; i++)




int main()
{
    ios::sync_with_stdio(false);

    int n,temp, tens, ones;

    string A,B,C,temp_str;
    A=B=C="";

    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>temp_str;
        A+=temp_str;
        cin>>temp_str;
        B+=temp_str;

    }

    temp = tens = ones = 0;
    for (int i=n-1; i>=0; i--)
    {
        temp = A[i] + B[i] - 2*'0'+ tens;
        ones = temp % 10;
        tens = temp / 10;
        C += (ones + '0');
    }

    reverse(C.begin(),C.end());

    cout<<C;
    return 0;
}

