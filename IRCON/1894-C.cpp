

#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int n,m;
    cin>>n>>m;
    string s;cin>>s;
    
    vector<int>one,zero,pre(n); 
    for(int i=0;i<n;i++){ 
        if(i>=1){
        	pre[i]=pre[i-1];
        }
    	if(s[i]=='1'){
    		one.push_back(i);
    		pre[i]++;
    	}else{
    		zero.push_back(i);
    	}
    }
    set<pair<int,int>>st;
    while(m--){
    	int x,y;cin>>x>>y;
    	x--;y--;
    	int oneCount=pre[y];
    	if(x>0){
    		oneCount-=pre[x-1];
    	}
    	if(x==y || oneCount==(y-x+1) || oneCount==0){
    		st.insert({-1,-1});
    		continue;
    	}
    	int oneIndex=lower_bound(one.begin(),one.end(),x)-one.begin();
    	int zeroIndex=upper_bound(zero.begin(),zero.end(),y)-zero.begin();
    	zeroIndex--;
    	oneIndex=one[oneIndex];
    	zeroIndex=zero[zeroIndex];
    	if(zeroIndex>oneIndex){ 
    		st.insert({oneIndex,zeroIndex});
    	}else{
    		st.insert({-1,-1});
    	}
    }
    cout<<st.size()<<endl;
}

signed main() {
    ios_base::sync_with_stdio();cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}