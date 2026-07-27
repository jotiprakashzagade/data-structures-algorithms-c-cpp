#include<iostream>
#include<math.h>
using namespace std;

class Point
{
    int x,y;
    public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    friend double distancePoint(Point, Point);
    void displayPoint()
    {
        cout<<"The point is ("<<x<<", "<<y<<")"<<endl;
    }
};

double distancePoint(Point X2, Point X1)
{
    return sqrt( ((X2.x - X1.x)*(X2.x - X1.x))  +  ((X2.y - X1.y)*(X2.y - X1.y)) );
}

int main() {
    
    Point a1(1,0);
    Point a2(70,0);
    a1.displayPoint();
    a2.displayPoint();
    double distance = distancePoint(a1,a2);
    cout<<distance<<endl;

    return 0;
}