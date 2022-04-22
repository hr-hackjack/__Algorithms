//https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/

/*
Since we want to have k stacks in an array, we need k tops. Hence we make an array top[] of size k.
Initialise top[] with -1.
*/

//6-7 baar dekhne k baad aaya smjh..boht hard boht hard..lol

class NStack
{
    int *arr;	// Array of size S to store actual content to be stored in stacks
    int *top;	// Array of size N to store indexes of top elements of stacks
    int *next;	//Array of size S to store next entry in all stacks
                // and free list
    
    int n, s;
    int freeSpot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //initialize top
        for(int i = 0; i<n ; i++)
        {
            top[i] = -1;
        }
        
        //initialise next
        for(int i = 0; i<s; i++)
        {
            next[i] = i+1;
        }
        
        //update last index value of next to -1
        //kyuki wo kisi ko point nhi krega
        next[s-1] = -1;
        
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Check for overflow
        if(freeSpot == -1)
            return false;
        
        //find index where we will push the element
        int index = freeSpot;
        
        //update freeSpot
        freeSpot = next[index];
        
        //insert element into array
        arr[index] = x;
        
        //update next
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true; 
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow
        if(top[m-1] == -1)
            return -1;
        
        //push wale function ko reverse order me likh do
        
        int index = top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freeSpot;
        
        freeSpot = index;
        
        return arr[index];
    }
};