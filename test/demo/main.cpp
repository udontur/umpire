#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1){
        return 0;
    }
    int dp[100];
    dp[0]=0;
    dp[1]=dp[2]=1;
    for(int i =3; i<=n; i++) dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n]<<"\n";
    cout<<"\n\n";

    return 0;
}
