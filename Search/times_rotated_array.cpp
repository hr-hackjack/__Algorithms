#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
using namespace std;


int binary_search(vector<int> &arr, int n){

    int lo = 0;
    int hi = n-1;

    int pivot = -1;

    while(lo <= hi){
        if(arr[lo] <= arr[hi]){
            return lo;
        }

        int mid = lo + (hi - lo)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;

        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
            pivot = mid;
            break;
        }

        if(arr[lo] <= arr[mid]){
            lo = mid+1;
        }else if(arr[mid] <= arr[hi]){
            hi = mid-1;
        }
    }

    return pivot;

}


int32_t main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int ans = binary_search(v, n);

    cout<<ans<<endl;
	return 0;
}