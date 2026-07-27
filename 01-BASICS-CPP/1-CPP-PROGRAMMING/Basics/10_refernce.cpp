#include <iostream>

using namespace std;

void change_value(int &x)
{
    x=100;
}
int main()
{
    int a{10};
    cout<<a<<endl;
    change_value(a);
    cout<<a<<endl;
    return 0;
}
/*why to use the references ?
  |
 \|/
 as we know in function  call by refernce we pass the addrss of the original 
 argunments form the main() funciotn and in called funciotn we use the 
 pointer to stote this addrss but usage of pointer is complex and we can make
 mistake in large programs so instd of the pointers we can use the refernces 
 so in change_value(int &x) we use the refernce so the changes made in this funciton 
 are affecting the original value because both original and the refernce used in 
 the funciotn have same memmory address as the pointer and it is easy to use 
 */