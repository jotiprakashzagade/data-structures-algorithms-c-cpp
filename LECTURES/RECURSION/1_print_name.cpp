#include<bits/stdc++.h>
using namespace std;

void print(int n, string name){  //TC = O(N) => this loop will run n times 
     // i.e n will run form n to o and then it will return.SC = O(N)
    if(n == 0) return ;
    cout<<name<<endl;

    print(n-1,name);

}
int main() {
    string name;
    int n;
    cin>>n;
    cin>>name;
    print(n,name);
    return 0;
}