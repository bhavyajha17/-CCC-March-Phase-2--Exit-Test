#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

#define PRIME 1000000009

#define endl '\n'

#define pb push_back

#define F first

#define S second

#define ll long long

#define ull unsigned int

#define all(c) c.begin(),c.end()

#define rall(c) c.rbegin(),c.rend()

#define sz(c) c.size()

#define r(i,a,b) for(i=a;i<b;i++)

#define ra(i,a,b) for(i=a;i<=b;i++)

#define vi vector<int>

#define vil vector<ll>

/*// for hashing 131 and 1e9+7

// fermats theorem M-2

//mpow

//r=1;

//while(b)

//{

if(b&1) r=(r*a)%M

a=(a*a)%m;

b=b>>1;

//}

*/

/*

void sieve(int n)

{

bool prime[n + 1];

memset(prime, true, sizeof(prime));

for (int p = 2; p * p <= n; p++)

{

// If prime[p] is not changed,

// then it is a prime

if (prime[p] == true)

{

for (int i = p * p; i <= n; i += p)

prime[i] = false;

}

}

}*/


 

ll solve()

{

ll n,m,i,j; ll k; ll l,r;

string s; cin>>s; n=sz(s);

     ll dp[n][5]; memset(dp,0,sizeof(dp));

     if(s[0]=='a') dp[0][0]=1;

     for(int i=1;i<n;i++)

     {

        if(s[i]=='a')

        {

        dp[i][0]=1+dp[i-1][0];  

        }

        else

        dp[i][0]=dp[i-1][0];

        if(s[i]=='e')

        {

        if(dp[i-1][1]!=0)   

        dp[i][1]=1+dp[i-1][1];

        if(dp[i-1][0]!=0)

        dp[i][1]=max(dp[i][1],1+dp[i-1][0]);    

        }

        else

        dp[i][1]=dp[i-1][1];

        if(s[i]=='i')

        {

        if(dp[i-1][2]!=0)   

        dp[i][2]=1+dp[i-1][2];

        if(dp[i-1][1]!=0)

        dp[i][2]=max(dp[i][2],1+dp[i-1][1]);    

        }

        else

        dp[i][2]=dp[i-1][2];

        if(s[i]=='o')

        {

        if(dp[i-1][3]!=0)   

        dp[i][3]=1+dp[i-1][3];

        if(dp[i-1][2]!=0)

        dp[i][3]=max(dp[i][3],1+dp[i-1][2]);    

        }

        else

        dp[i][3]=dp[i-1][3];

        if(s[i]=='u')

        {

        if(dp[i-1][4]!=0)   

        dp[i][4]=1+dp[i-1][4];

        if(dp[i-1][3]!=0)

        dp[i][4]=max(dp[i][4],1+dp[i-1][3]);    

        }

        else

        dp[i][4]=dp[i-1][4];

        

     }

     cout<<dp[n-1][4];

return 0;

}

int main()

{

ios_base::sync_with_stdio(false);

cin.tie(NULL);

ll t;

t=1;

//cin>>t;

while(t--)

{

solve();

}

return 0;

}
