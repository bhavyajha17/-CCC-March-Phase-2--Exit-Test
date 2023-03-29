#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pi pair<int ,int >
#define pl pair<ll ,ll >
#define pb push_back
#define vl vector <long long int >
#define vi vector <int >
#define vp vector <pi>
#define mod 1000000007
#define eps 1e-9
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define _ <<" "<<
#define forn(x,	n) for(int x = 0; x < n ;++ x) 
#define forn1n(x,n) for(int x = 1; x <= n ;++ x)
#define forn1(x,n) for(int x = 1; x < n ;++ x)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#pragma GCC optimize ("Ofast")
void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F &f, R&... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)

template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<","<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<" ";out<<*it;}out<<"";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}

int main(){
	IOS

	int n;
	cin>>n;
	vi v(n);
	forn(i,n)
	{
		cin>>v[i];
	}

	priority_queue<int>pq;
	ll cost1=0,cost2=0;
	pq.push(v[0]);
	forn1(i,n)
	{
		if(v[i]<pq.top())
		{
			cost1 += pq.top()-v[i];
			pq.pop();
			pq.push(v[i]);
		}
		pq.push(v[i]);
	}
	//reverse(all(v));
	priority_queue<int,vector<int>,greater<int>>pqq;	
	pqq.push(v[0]);
	forn1(i,n)
	{
		pqq.push(v[i]);
		if(v[i]>pqq.top())
		{
			cost2 += v[i]-pqq.top();
			pqq.pop();
			pqq.push(v[i]);
		}
	}
 	cout<<min(cost1,cost2)<<endl;
	return 0;	
}
