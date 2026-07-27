/*
    *
    **
    ***
    ****
    *****
    *****
    ****
    ***
    **
    *
   */
  #include<bits/stdc++.h>
  using namespace std;
  
  
  void printPattern(int n){
    // for(int i=0; i<n; i++){
    //    for(int j=0; j<i+1; j++)
    //    {
    //     cout<<"* ";
    //    }
    //    cout<<endl;
    // }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n-i; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1; i<= n*2-1; i++){
        int stars = i;
        if(i > n) stars = 2*n-i;
        for(int j=0; j<stars; j++){
            cout<<"* ";
        }
        cout<<endl;
        if(i > n){

        }
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