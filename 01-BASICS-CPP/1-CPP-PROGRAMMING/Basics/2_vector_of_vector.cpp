#include<iostream>
#include<vector>
using namespace std;
int main()
{
    "Defination";
    /*A vector of vectors in C++ is a dynamic 2D container
    where both the number of rows and the number of columns
    can grow or shrink at runtime.
    */
   //std::vector<std::vector<int>> vec2d;
   /*Visual Breakdown In memory, the outer vector holds a list of
   std::vector objects (internal headers containing pointers, size,
   and capacity). Each of those inner vectors points to its own 
   separate block of memory on the heap where the actual integers 
   are stored. Because of this, rows do not have to be the same 
   length.
   
   Outer Vector (Heap)      Inner Vectors (Separate Heap Locations)
   [ Row 0 ] ----------> [ 10, 20, 30 ]        (Size: 3)
   [ Row 1 ] ----------> [ 40 ]                (Size: 1)
   [ Row 2 ] ----------> [ 50, 60, 70, 80 ]    (Size: 4)*/

   "Example 1"; 
   vector<vector<int>> v;
   v.push_back({12,34});
   v.push_back({1});
   v.push_back({-1,0,67});

   for(int i=0; i<v.size(); i++)
   {
    for(int j=0; j<v[i].size(); j++)
    /*for(auto it=v[i].begin(); it!=v[i].end(); it++)
    {
        cout<<*it<<" ";
    }*/
    {
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
   }

   vector<vector<int>>::iterator it;
   it = v.begin();
   v.insert(it+1, {5,6,7,8});
   cout<<"After row insertion : "<<endl;
   for(int i=0; i<v.size(); i++)
   {
    for(auto it=v[i].begin(); it!=v[i].end(); it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl;
   }

   v.pop_back();
   cout<<"After pop back : "<<endl;
   for(int i=0; i<v.size(); i++)
   {
    for(auto it=v[i].begin(); it!=v[i].end(); it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl;
   }




   "Example 2";
  
    // // Method 1: Initialize a 3x4 grid with all zeros
    // std::vector<std::vector<int>> grid(3, std::vector<int>(4, 0));

    // // Method 2: Create a completely dynamic ragged structure
    // std::vector<std::vector<int>> dynamic_vec;

    // // Add a new row and push elements into it
    // dynamic_vec.push_back(std::vector<int>()); // Add row 0
    // dynamic_vec[0].push_back(1);
    // dynamic_vec[0].push_back(2);

    // // Direct initialization of another row
    // dynamic_vec.push_back({3, 4, 5}); // Add row 1

    // // Traversal using range-based for loops
    // for (const auto& row : dynamic_vec) {
    //     for (int val : row) {
    //         std::col << val << " ";
    //     }
    //     std::cout << "\n";
    // }

    return 0;


}