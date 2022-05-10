#include<bits/stdc++.h>
#define ll long long
using namespace std;


void insert(int key, stack<int> &st){

	//Base Condition :- if there are zero elements left only then
	//pushing the key will make sense because we the job of 
	//insert() is to insert key at the beginning of stack.

	if(st.size() == 0){
		st.push(key);
		return;
	}

	//Hypothesis :- if we want to insert at the beginning we 
	//first need to remove all elements from the stack, so 
	//we call insert with smaller input everytime.
	//we assume that insert will insert the key at the 
	//beginning with smaller input everytime.

	int item = st.top();
	st.pop();
	insert(key, st);

	//Induction :- all that remains after we get the modified
	//stack is to insert the saved element to restore the stack.

	st.push(item);

}


void reverse(stack<int> &st){

	//Base Condition :- single element by itself is its reverse 
	//so if we have a single element we simply return

	if(st.size() == 1){
		return;
	}

	//Hypothesis :- we assume our func would reverse the stack
	//with one element less each time its called. And we save
	//top element.

	int val = st.top();
	st.pop();
	reverse(st);

	//Induction :- we assume that our stack with one element less
	//is reversed now all that is left is to push the saved 
	//element to the end of stack.

	insert(val, st);

}


int main(){


	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin>>n;

	stack<int> st;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		st.push(a);
	}



	reverse(st);

	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}



	return 0;

}