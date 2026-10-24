#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[100];
    dp[0]=0;
    dp[1]=dp[2]=1;
    for(int i =3; i<=n; i++) dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n]<<"\n";
    cout<<"\n\n";
}