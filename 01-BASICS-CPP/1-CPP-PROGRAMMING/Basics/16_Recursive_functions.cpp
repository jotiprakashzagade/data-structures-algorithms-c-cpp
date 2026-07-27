#include<iostream>
using namespace std;

unsigned long long total_money(int day)
{
    if(day == 1)return 1;
    return total_money(day-1)*2;
}
int main() {
    int day;cin>>day;
    cout<<"total money = "<<total_money(day);
    return 0;
}