#include<iostream>
#include<vector>
using namespace std;
int main()
{
    "Definaiton";
    /*An array of vectors in C++ is a fixed-size sequence where
    each element is a dynamic, resizable std::vector.*/
    std::vector<int> arr[5]; // An array of 5 vectors
    
    "Visual Breakdown";
    /*Unlike a 2D vector (which is completely dynamic), the "backbone"
    of this structure is a static array allocated on the stack, 
    while the actual data elements reside on the heap.

    arr[0] ──> [ 1, 2, 3 ]         (Size: 3)
    arr[1] ──> [ 4 ]               (Size: 1)
    arr[2] ──> [ ]                 (Size: 0)
    arr[3] ──> [ 7, 8, 9, 10, 11 ] (Size: 5)
    arr[4] ──> [ 5, 6 ]            (Size: 2) */

    "Example 1";
    vector<int>v[3];
    // v[0].push_back(1);
    // v[0].push_back(34);
    // v[1].push_back(4);
    // v[2].push_back(344);
    // v[2].push_back(78);
    // v[2].push_back(44);

    for(int i=0; i<3; i++)
    {
       int n;
       cout<<"Enter size of vector "<<i+1<<"= ";cin>>n;
       cout<<"Enter elements of the vector "<<i+1<<"= ";
       for(int j=0; j<n; j++)
       {
            int value;cin>>value;
            v[i].push_back(value);
       }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }






    "Example 2";
    std::vector<int> adj[3];

    // Append elements to individual rows
    adj[0].push_back(10);
    adj[0].push_back(20);

    adj[1].push_back(30); // Row 1 gets one element

    adj[2].push_back(40);
    adj[2].push_back(50);
    adj[2].push_back(60); // Row 2 gets three elements

    // Traversal
    for (int i = 0; i < 3; ++i) {
        std::cout << "Row " << i << ": ";
        for (int val : adj[i]) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;

}