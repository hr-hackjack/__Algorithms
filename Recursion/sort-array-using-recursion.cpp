#include<bits/stdc++.h>
#define ll long long
using namespace std;


void insert(vector<int> &v, int key){

	if(v.size() == 0 || v[v.size()-1] <= key){
		v.emplace_back(key);
		return;
	}
	int item = v[v.size()-1];
	v.pop_back();

	insert(v, key);

	v.emplace_back(item);

}


void sort(vector<int> &arr){

	if(arr.size() == 1){
		return;
	}

	int val = arr[arr.size()-1];
	arr.pop_back();
	sort(arr);

	insert(arr, val);

}



int main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n; cin>>n;

	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}


	sort(arr);


	for(int x : arr){
		cout<<x<<" ";
	}


	return 0;
}