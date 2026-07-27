#include <iostream>
using namespace std;

class BankDeposite
{
    int principal;
    int years;
    float interestRate;
    float returnValue;

public:
    BankDeposite() {};
    /* ========================================================================
     NOTE: WHY WE NEED THE BLANK (DEFAULT) CONSTRUCTOR HERE
    ========================================================================

    1. THE PROBLEM IN MAIN():
       In main(), we declared the objects before getting user input:
       "BankDeposite bd1, bd2, bd3;"
       This line explicitly commands the compiler to allocate memory and
       initialize three objects immediately. Because we passed zero arguments
       at this point, the compiler MUST find a zero-argument (default)
       constructor to build them.

    2. THE C++ COMPILER RULE:
       - If you write a class with NO constructors, C++ automatically creates
         a hidden, blank default constructor for you behind the scenes.
       - However, the moment you define ANY parameterized constructor (like our
         3-argument constructors), C++ immediately destroys its automatic
         default constructor.
       - Therefore, since we defined parameterized constructors, we had to
         explicitly type "BankDeposite() {};" to bring the default constructor
         back to life. Without it, the line "BankDeposite bd1..." fails to compile.

    3. HOW TO OPTIMIZE THIS AND DELETE THE BLANK CONSTRUCTOR:
       Instead of declaring empty objects and then assigning values later using
       the '=' operator (which creates a slow temporary object in memory), we
       should get the user input FIRST, and then initialize the objects directly:

       int p, y; float r;
       cin >> p >> y >> r;
       BankDeposite bd1(p, y, r); // Direct initialization!

       If we restructure main() this way, the objects never exist without data,
       meaning the blank "BankDeposite() {};" constructor becomes completely
       useless and can be deleted from the class entirely.
    ========================================================================
*/
    BankDeposite(int p, int y, float r);
    BankDeposite(int p, int y, int R);
    void show();
};

BankDeposite ::BankDeposite(int p, int y, float r)
{
    principal = p;
    years = y;
    interestRate = r;
    returnValue = principal;

    for (int i = 0; i < years; i++)
    {
        returnValue *= (r + 1);
    }
}

BankDeposite ::BankDeposite(int p, int y, int R)
{
    principal = p;
    years = y;
    interestRate = float(R) / 100;
    returnValue = principal;

    for (int i = 0; i < years; i++)
    {
        returnValue *= (interestRate + 1);
    }
}

void BankDeposite ::show()
{
    cout << "Principle amount was " << principal << endl
         << "Return Value after " << years
         << " is " << returnValue << endl;
}

int main()
{
    BankDeposite bd1, bd2, bd3;
    int p, y;
    float r;
    int R;

    cout << "Enter values of p, y, r : ";
    cin >> p >> y >> r;
    bd1 = BankDeposite(p, y, r);
    /*  QUESTION :  If we call "bd1 = BankDeposite(p, y, r);", the constructor uses private members,
     but how does the compiler know which object those members belong to since we
    called the constructor directly without referencing bd1?
    ANSWER :
    1. The constructor BankDeposite(p, y, r) does NOT know that bd1 exists.
    2. Instead, it creates a TEMPORARY, nameless object in memory and initializes
    the private members of THAT temporary object.
    3. Then, the assignment operator (=) copies all the data from the temporary
    object into the existing 'bd1' object.
    4. Once the assignment is finished, the temporary object is deleted.
    Note: To avoid this extra copy step, initialize directly after getting input:
    BankDeposite bd1(p, y, r);  */
    bd1.show();

    cout << "Enter values of p, y, r : ";
    cin >> p >> y >> r;
    bd2 = BankDeposite(p, y, r);
    bd2.show();

    cout << "Enter values of p, y, R : ";
    cin >> p >> y >> R;
    bd3 = BankDeposite(p, y, R);
    bd3.show();

    return 0;
}