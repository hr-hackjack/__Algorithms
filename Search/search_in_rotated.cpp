#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
using namespace std;

int point_of_rotation(vector<int> &arr, int n){
    
    int lo = 0;
    int hi = n-1;
    
    int pivot = -1;
    
    while(lo <= hi){
        
        if(arr[lo] <= arr[hi]){
            return lo;
        }
        
        int mid = lo +(hi - lo)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        
        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
            pivot = mid;
            break;
        }
        
        if(arr[lo] <= arr[mid]){
            lo = mid + 1;
        }else if(arr[mid] <= arr[hi]){
            hi = mid - 1;
        }
        
    }
    
    return pivot;
}


int binary_search(vector<int> &arr, int lo, int hi, int key){
        
    while(lo <= hi){
        
        int mid = lo + (hi - lo)/2;
        
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] < key){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    
    return -1;
    
}

int search(vector<int> &arr, int l, int h, int key){
    
    int mid = point_of_rotation(arr, h+1);
    
    int f = binary_search(arr, 0, mid-1, key);
    int s = binary_search(arr, mid, h, key);
    
    
    if(f == -1 && s == -1) return -1;
    
    if(f == -1) return s;
    else return f;
    
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