#include<bits/stdc++.h>
using namespace std;

//manual memmory allocation in CPP LANG(without vector)
// int main() {
//     int *p = new int[5];
//     for(int i=0; i<5; i++)cin>>p[i];
//     int *q = new int[10];
//     for(int i=0; i<5; i++)q[i] = p[i];
//     delete []p; 
//     p = q; 
//     q = NULL;
//     for(int i=5; i<10; i++)cin>>p[i];
//     for(int i=0; i<10; i++)cout<<q[i];
//     delete []p;
//     return 0;
// }


//heap memmory allocation in C LANG
int main(){
    int *p =(int*)malloc(5*sizeof(int));

    for(int i=0; i<5; i++)scanf("%d",&p[i]);
    
    int *q =(int*)malloc(10*sizeof(int));

    for(int i=0; i<5; i++) q[i] = p[i];

    
    free(p);

    p = q;
    q = NULL;

    for(int i=5; i<10; i++)scanf("%d",&p[i]);

    for(int i=0; i<10; i++)printf("%d ",p[i]);

    free(p);

    
}