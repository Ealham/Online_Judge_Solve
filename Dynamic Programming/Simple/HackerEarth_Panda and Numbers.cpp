/*

Problem Link:
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/panda-and-numbers/

Simple DP

*/



#include <bits/stdc++.h>
using namespace std;

int dp[1000000+5];


bool recurse(int n)
{
    //cout<<n<<endl;

    if (dp[n] != -1)
        return dp[n];

    else
    {
        int copy_n = n;

        while(copy_n)
        {
            int digit = copy_n % 10;
            if (digit && (n - (digit*digit) > 0) ) {

                 if (recurse(n-digit*digit))
                    return dp[n] = true;
            }

            copy_n = copy_n / 10;
        }

    }

    return dp[n] = false;
}


int main()
{
    //int arr[100000+1];

    ios::sync_with_stdio(false);

    memset(dp,-1,sizeof(dp));

    for (int i=1; i<=7; i++)
    {
        dp[(int)pow(i,i)] = true;
    }




    for (int i=1; i<=10; i++)
    {
        if (dp[i] == -1)
            dp[i] = false;
    }


    int n, temp;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        cin>>temp;
        if (recurse(temp))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }

    return 0;
}
