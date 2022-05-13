#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
using namespace std;

int last_occur(vector<int> &v, int key){

    int lo = 0;
    int hi = v.size()-1;
    
    int res = -1;
    
    while(lo <= hi){
        
        int mid = lo + (hi -lo)/2;

        //here we keep on searching towards the right of the mid 
        //even if our mid is the key.
        
        if(v[mid] == key){
            res = mid;
            lo = mid + 1;
        }else if(v[mid] < key){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
        
    }
    
    return res;

}

int first_occur(vector<int> &v, int key){

    int lo = 0;
    int hi = v.size()-1;

    int res = -1;

    while(lo <= hi){

        int mid = lo + (hi-lo)/2;

        //even if we find that mid is our key we still dont know 
        //whether that is the first element or not so we keep 
        //on searching towards the left of the mid if mid is our key

        if(v[mid] == key){
            res = mid;
            hi = mid - 1;
        }else if(v[mid] < key){
            lo = mid + 1;
        }else{
            hi = mid-1;
        }
    }

    return res;

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

    int p1 = first_occur(v, k);
    int p2 = last_occur(v, k);

    cout<<"count is ->"<<p2-p1+1<<endl;
    
    cout<<p1<<" "<<p2<<"\n";
	

	return 0;
}