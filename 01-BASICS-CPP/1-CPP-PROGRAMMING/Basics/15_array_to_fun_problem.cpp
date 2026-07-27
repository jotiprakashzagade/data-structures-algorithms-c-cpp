#include <iostream>
using namespace std;
void min_max(int[]);
int main() {
    int array[] {34,-78,0,1,56,89};
    int size = sizeof(array)/sizeof(int);
    min_max(array);
    return 0;
}
void min_max(int array[])
{
    int size = (sizeof(array)/sizeof(int));
    int min = array[0];
    int max = array[0];
    for(int i = 1; i<size; i++)
    {
        if(min > array[i])
        min = array[i];
        if(max < array[i])
        max = array[i];
    }
    cout<<"Min = "<<min<<endl<<"Max = "<<max<<endl;
}