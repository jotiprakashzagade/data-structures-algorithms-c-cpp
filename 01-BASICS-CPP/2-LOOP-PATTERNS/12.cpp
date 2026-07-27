/*
  1      1
  12    21 
  123  321
  123  321 
  12344321
   */
  #include<bits/stdc++.h>
  using namespace std;
  
  
  void printPattern(int n){
       for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        for(int j=1; j<=(n*2)-(i*2); j++){
            cout<<" ";
        }
        for(int j=i; j>=1; j--){
            cout<<j;
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