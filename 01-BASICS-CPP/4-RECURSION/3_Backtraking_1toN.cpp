#include<bits/stdc++.h>
using namespace std;

/*Q.print 1 to n without doing i+1;
=>in this kind of situation we can use concept of backtraking 
=>noramally we first check condition , then print someting (like variable
 or value of the i)
=> but in backtracking first we check condition , then
 call the recursive function and then
cout the value of variable
=> so what happens is recurive call occurs multiple time until the condition 
becomes false, and as soon as condtion beccome false and control go back to
the caller function then it execute the remaining statement in the caller fucntion 
and then again control go the caller function , and this process occur till 
the control go to the first call and then to main 
=> like in this below funciton that print 1 to n values, it first check
condition and then immidiatly do recursive call and repeate until the 
condition become false it return the control and then print the value
of the i , but it do it in the reverse order so it print i values form 1 to n */
void BackTrackPrint(int i, int n){
    if(i<1)return;

    BackTrackPrint(i-1, n);
    cout<<i<<endl;
}
int main() {
    int n;
    cin>>n;
    BackTrackPrint(n,n);
    return 0;
}