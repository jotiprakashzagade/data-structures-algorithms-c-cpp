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
    
    for(int i=1; i<=n; i++){
        char ch = 'A';
        for(int j=n; j>=i; j--){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
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