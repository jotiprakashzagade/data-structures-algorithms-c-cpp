#include <iostream>
#include <string>
using namespace std;

int main() {

    string full_name {"Jenny'sLectures"};
    string f_name{full_name,0,7}; /* this will fetch 7 characters form the string
    full_name where 0 represent the starting index while 7 represent the how 
    many character to add in this new string*/
    string l_name(full_name.substr(7,8));/*substr() method take two arg first is the 
    index form where start to copy and secod is the total charater in the string 
    to copy */
    string formated_full_name{f_name+l_name};
    formated_full_name.insert(7," ");
    cout<<formated_full_name<<endl;

    return 0;
}