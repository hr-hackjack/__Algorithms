#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
using namespace std;


int floor(vector<int> &arr, int n, int x){

    int lo = 0;
    int hi = n-1;

    int res = -1;

    while(lo <= hi){

        int mid = lo + (hi-lo)/2;

        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] < x){
            res = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }

    }

    return res;
}

int ceil(vector<int> &arr, int n, int x){

    int lo = 0;
    int hi = n-1;

    int res = -1;
    
    while(lo <= hi){

        int mid = lo + (hi - lo)/2;

        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] < x){
            lo = mid + 1;
        }else{
            res = mid;
            hi = mid - 1;
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

    cout<<"floor at "<<floor(v, n, k)<<"\n";

	cout<<"ceil at "<<ceil(v, n, k)<<"\n";

	return 0;
}