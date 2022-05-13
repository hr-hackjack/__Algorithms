#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
using namespace std;


int binary_search(vector<char> &v, char key){

    int lo = 0;
    int hi = v.size()-1;
    int n = v.size();

    int res = -1;

    while(lo <= hi){

        int mid = lo + (hi - lo)/2;

        if(v[mid] == key){
            lo = mid + 1;
        }else if(v[mid] < key){
            lo = mid + 1;
        }else{
            res = mid;
            hi = mid - 1;
        }

    }

    if(lo > hi && hi == n-1){       //char larger than last element 
        return 0;                   //then point to the first char
    }
    
    return res;
}


int32_t main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin>>n;
    char k; cin>>k;
    vector<char> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int ans = binary_search(v, k);

    cout<<v[ans];
	

	return 0;
}