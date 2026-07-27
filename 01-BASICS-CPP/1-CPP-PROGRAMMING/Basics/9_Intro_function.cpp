#include <iostream>
using namespace std;
void dispaly(std::string name)
{
    std::cout<<"Hi "<<name;
}
int main() {
    
    std::string name;
    std::cin>>name;
    dispaly(name);
    
    return 0;
}