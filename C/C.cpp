#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define mp             make_pair
#define pb             push_back
#define fs             first
#define sc             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(x))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i < y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
#define type(itr,x) __typeof(x.begin()) itr = x.begin()
#define Inp freopen("a.inp","r",stdin);
#define Out freopen("a.out","w",stdout);
#define N 100005

typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 1e9;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;

// PlayGround
int len,ds[10],arr[10],ans = 10;
void bt(int id){
	if(id == len){
		int sum = 0,dem = 0;
		string temp="";
		rep(i,0,len){
			if(ds[i]){
				sum*=10;
				//cout<<arr[i];
				sum+=arr[i];
				temp+=(arr[i]+'0');
				dem++;
			}
		}
		int l = 0;
		while(temp[l] == '0') l++;
		dem-=l;
		int p = sqrt(sum);
		if(p*p == sum && len-dem < ans && p!=0){
			ans = len-dem;
			  
		}
		//cout<<endl<<"SUM ="<<sum<<" and "<<len-dem<<" "<<temp<<endl;
	
	}else{
		rep(i,0,2){
			ds[id] = i;
			bt(id+1);
		}
	}
}
int main(){
	//Inp;
	sci(n);
	int i=0;
	while(n){
		arr[i++] = n%10;
		n/=10;
	}
	len = i;
	reverse(arr,arr+i);
	bt(0);
	if(ans!=10) cout<<ans<<endl;
	else cout<<"-1"<<endl;
return 0;
}