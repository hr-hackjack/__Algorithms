#include<bits/stdc++.h>
#define ll long long
using namespace std;

//IBH Based Method

void solve(vector<int> &res, int index, int k, int &ans){

	//Base Condition : when the no. of people remaining is one 
	//he is the one who survived hence the answer.

	if(res.size()==1){
		ans = res[0];
		return;
	}

	//Hypothesis : Our hypothesis is that solve() should
	//remove the the person from the required index and 
	//reduce the size of array.

	index = (index+k)%res.size();
	res.erase(res.begin()+index);

	solve(res, index, k, ans);

	//Induction : there is no induction step because we dont 
	//require to do anything once we kill/remove the person
	//from the array.

}



int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin>>n>>k;

	vector<int> v;
	for(int i=1; i<=n; i++){
		v.emplace_back(i);
	}

	int ans = -1;
	k--;
	solve(v, 0, k, ans);

	cout<<ans<<endl;

	return 0;
}