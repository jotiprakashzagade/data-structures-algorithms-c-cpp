/*
1. the concept of Reusability in c++ is supported using inheritance
2.we can reuse the properties of an existing class by inherting them 
3.The existing class is called as Base class
4.The new class which is inherited is called as derived class
5.Reusing classes saves time and money
6.There are different types of inheritacnce in c++
   i)single inheritance
   ii)Multiple inheritance
   iii)hierarchial inheritance
   iv)Multilevel inheritance
   v)hybrid inheritance

*/
/*SINGLE INHERITANCE :-
-derived class with only one base class

        class A    
    derived|    /|\
          \|/    |is derived form
         class B     

*/

/*
MULTIPLE INHERITANCE :-
-derived class with more than one base class

class a   class b
        |
       \|/
     class c
*/
/*HIERARCHICAL INHERITANCE:-
-several derived classes from a single base class

        class a
        |    |   
       \|/  \|/
       b     c
*/
/*
MULTILEVEL INHERITANCE:-
-deriving a class from already derived class
        class A    
           |    
          \|/   
        class B (class A + more)
           |    
          \|/
        class c (class A + class b + more properties)
 */

 /*HYBRID INHERITANCE:-
 -Hybrid inheritance is a combination of multiple
 inheritance and multilevel inheritance
 -A class is derived from two class as in multiple inheritance 
 -However , one of the parent classes is not a base class

        class a
        |    |   
       \|/  \|/
       b     c
          |
         \|/
       class d
 */