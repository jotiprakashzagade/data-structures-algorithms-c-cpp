/*
  1
  1 0
  1 0 1
  1 0 1 0
  1 0 1 0 1
   */
  #include<bits/stdc++.h>
  using namespace std;
  
  
  void printPattern(int n){
        for(int i=0; i<n; i++){
            int start = 1;
            if(i%2==0) start = 1;
            else start = 0;
            for(int j=0; j <= i; j++){
                cout<<start<<" ";
                start = 1 - start;
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