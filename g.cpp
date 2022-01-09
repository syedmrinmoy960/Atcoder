//#include<cstdio>
//#include<cassert>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)2e9 + 5)
#define MAXP ((int)1e5 + 5)
#define MAXL ((ll)1e18 + 5)
#define MAX_X ((int)2001)
#define MAX_Y ((int)2001)
#define pi acos(-1)
//#define MOD ((int)1e9 + 7)
#define MOD ((int)998244353 + 0)
#define BAS ((int)1e6 + 3)
//#define BAS ((int)2e5 + 3)
#define N ((int)1e4 + 9)
#define eps (1e-8)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define logn 17
#define endl "\n"
#define mpp make_pair
#define BUCK 105
#define LEF (idx<<1)
#define RIG ((idx<<1)|1)
//#define int ll
 
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef unsigned long long ull;
 
/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
 
 
 
 
typedef tree < int,  null_type,  less < int >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
typedef tree < pair < int, int >,  null_type,  less < pair < int, int > >,  rb_tree_tag,  tree_order_statistics_node_update > o_setp;
/// o_set s;
/// s.order_of_key(k) : Number of items strictly smaller than k .
/// *(s.find_by_order(k)) : K-th element in a set (counting from zero).
 
typedef long double ldd;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l,r) (rng);
}
 
 
bool possible(int tim , string &str)
{
    int cover = -1 , n = str.size();
    while(cover + 1 < n && str[cover+1] != '*') cover++;
    for(int i = 0 ; i<n ; i++){
        if(str[i] == 'P'){
            int L = min(i , cover + 1);
            if(i - L > tim) return 0;
            int R = max(tim + 2*L - i , (tim + i + L)/2);
            cover = max(cover , R);
            while(cover + 1 < n && str[cover+1] != '*') cover++;
        }
    }
    if(cover + 1 >= n) return 1;
    return 0;
}
 
int main()
{
    /// problem K
    fastio;
    /// str;
    int n;
    string str;
    cin>>n>>str;
    int L = 0 , R = 2e5;
    while(L < R){
        int mid = (R - L)/2 + L; /// -> (L + R)/2
        if(possible(mid , str) == 1) R = mid;
        else L = mid+1;
    }
 
    cout<<L<<endl;
    return 0;
}