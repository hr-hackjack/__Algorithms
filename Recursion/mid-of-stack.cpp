#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;

//here we are reducing the k value as we pass smaller 
//and smaller input to the recursive func


void midOfStack(stack<int> &st, int k){

	//base condition :- think of the smallest possible value of 
	//k i.e. it is 1 because after that we can simply pop off
	//the element

	if(k == 1){
		st.pop();
		return;
	}

	//hypothesis :- we pop the last element and send the rest
	//to the recursive function, we take a leap of faith that 
	//this will remove the mid and return the stack

	int val = st.top();
	st.pop();

	midOfStack(st, k-1);

	//induction :- whatever element we popped off will be added
	//to the stack again, here we assume that midofstack() will
	//remove the mid element

	st.push(val);

}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int n; cin>>n;

	stack<int> st;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		st.push(a);
	}

	int k = (n/2) + 1;

	midOfStack(st, k);

	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}


	return 0;

}