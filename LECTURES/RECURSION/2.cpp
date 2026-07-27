#include<bits/stdc++.h>
using namespace std;

class Solution;

class check{
   
    public:
    static bool palindrome(string str, int size, int i){
        if(i>=size/2)return true;
        if(str[i] != str[size-i-1])return false;
        return palindrome(str,size,i+1);
    }

};

class Solution{	
	public:		
    
		bool palindromeCheck(string& s){
			return check::palindrome(s, s.size(), 0);
		}
};

