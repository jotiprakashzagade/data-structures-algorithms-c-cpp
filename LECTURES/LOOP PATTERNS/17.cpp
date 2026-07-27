/*       A
        ABA
       ABCBA
      ABCDCBA
   */
  #include<bits/stdc++.h>
  using namespace std;
  
  
  void printPattern(int n){
    
    for(int i=0; i<n; i++){

        //spaces      
    for(int j=0; j<n-i-1; j++){
        cout<<" ";
    }
        //characters
        char ch = 'A';
        int breakPoint = ((2*i) + 1) / 2;
        for(int j=1; j<=(2*i)+1; j++){
            cout<<ch;
            if(j <= breakPoint) ch++;
            else ch--;
        }

        //spaces
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
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