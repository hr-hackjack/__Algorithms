#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
using namespace std;

int search(vector<int> &arr, int lo, int hi, int key){

    int n = arr.size();
    while(lo <= hi){

        int mid = lo + (hi-lo)/2;

        if(arr[mid] == key){
            return mid;
        }
        if(mid != n-1){
            if(arr[mid+1] == key){
                return mid+1;
            }
        }

        if(mid != 0){
            if(arr[mid-1] == key){
                return mid-1;
            }
        }

        if(arr[mid] < key){
            lo = mid+2;
        }else{
            hi = mid-2;
        }


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

    int ans = search(v, 0, n-1, k);

    cout<<ans<<endl;
	return 0;
}