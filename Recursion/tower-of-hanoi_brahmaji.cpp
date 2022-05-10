#include<bits/stdc++.h>
#define ll long long
using namespace std;

void tOfB(int n, string src, string dest, string helper){

	//Base Condition :- if there is only one plate left then move that 
	//to destination pole.
	if(n == 1){
		cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<" using "<<helper<<endl;
		return;
	}

	//Hypothesis :- we create a function that can correctly place n-1 
	//discs to helper pole because the first pole has to be at the bottom
	//of the dest pole.

	//Induction :- we place the first pole directly at dest pole, and then move
	//n-1 poles from helper to dest to maintain the ascending size of plates.


	tOfB(n-1, src, helper, dest);

	cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<" using "<<helper<<endl;

	tOfB(n-1, helper, dest, src);
}




int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin>>n;

	tOfB(n, "src", "dest", "helper");


	return 0;
}
