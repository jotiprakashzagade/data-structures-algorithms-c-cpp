#include <iostream>
#include<string>
using namespace std;

int main() {
    string str1 = "Joti";
    string str2{"Jotiprakash"};
    string str3("zagade");
    cout<<str1<<" "<<str2<<" "<<str3<<endl; 
    string str4{str3}; //copy form another string 
    cout<<str4<<endl;
    string str5(10, 'J');// this will repeat j 10 as a single string 
    cout<<str5<<endl;
    string str6(str2,4); /* in this line it will copy string from this perticular
    index so it will only copy praksh form the Jotiprakash , and you can
    also use the curly braces instead of the round braket*/
    cout<<str6<<endl;
    string str7{"Pradeep",3};/*in this line it will copy first n character of the 
    string like in pradeep it will only copy the pra , and you can alos use the 
    round braket instead of the curcly braces*/
    cout<<str7<<endl;

    "input form the user";
    //string str8;cout<<"Enter name : ";cin>>str8;cout<<str8<<endl;
    /*we can take input string like this form the user but as soon as user
    enter the tab or space or any whitespace it will stop taking input
    like if you enter Jotiprakash zagade it will only get the Jotiprakash and zagade 
    will not be stored as the string, so for that we can use the getline funciton 
    which take the string with whitespace and stop as soon as newline entered */
    
    string str9;
    cout<<"Name : ";
    getline(cin,str9);//it will get string with the whitespaces
    cout<<str9;

    "We can access indivisual character using index or the at() funcitn ";
    string str10{"Jotiprakash zagade"};
    cout<<str10[11]<<endl;//do not give bound check
    cout<<str10.at(11)<<endl;//give the bound check

    "concatination of strigs";
    string str12{"Joti"};
    string str13{"prakash"};
    cout<<str12+" "+str13<<endl;//we can conatinate two strings directly without any function 
    /*but we can not concatinate two strings directly like cout<<"Joti"+"Prakash"
    because it cout only concatinate the integeral or enum values but 
    you can concatinate c++ object and c style string like below */
    cout<<str12+"prakash"<<endl;//it is allowed it will not give error

    "length of the stirngs";
    cout<<"Length of str12 : "<<str12.length()<<endl;//both will give 
    cout<<"Lenght of str12 : "<<str12.size()<<endl;//lenght of stirng 

    "comparison of strings";
    cout<<(str12 >str13)<<endl;
    /*we can copare 2 string in c++ without funciton by usign directly comparision 
    opretors */
    cout<<(str12=="Joti")<<endl;/*we can compare 1 c++ string with c style string
    but we can compare both c style stirng it will give the error liek ("Joti"=="Joti")*/
    



    



    return 0;
}