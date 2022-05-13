#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
using namespace std;


int binary_search(vector<int> &v, int key){

    int lo = 0;
    int hi = v.size()-1;

    while(lo <= hi){

        int mid = lo + (hi-lo)/2;

        if(v[mid] == key) return mid;
        else if(v[mid] > key) lo = mid+1;   //change in this line 
        else hi = mid-1;
    }

    return -1;

}


int32_t main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, k; cin>>n>>k;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int ans = binary_search(v, k);

    if(ans == -1){
        cout<<"Not Found"<<"\n";
    }else{
        cout<<"Found at "<<ans<<"\n";
    }

	

	return 0;
}