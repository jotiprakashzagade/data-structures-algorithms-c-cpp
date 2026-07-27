/*
    ABCDE
    ABCD
    ABC
    AB
    A
   */
  #include<bits/stdc++.h>
  using namespace std;
  
  
  void printPattern(int n){
    char ch = 'A';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<ch<<" ";
        }
        cout<<endl;
        ch++;
    }
  }

  int main() {
      int t; 
      cin>>t;
      for(int i=0; i<t; i++){
        int n;
        cin>>n;
        printPattern(n);
      }
      return 0;
  }