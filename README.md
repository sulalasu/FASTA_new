build with 'cmake -S . -B build'
run with 'cmake --build build && ./build/fasta test.fasta'


# Header und Source (.cpp) Files:

## Header files .h
#pragma once !
Class declarations enthält
     - member variables (im PRIVATE)
     - function definitions:
          'returntype funcName(int i_inputvars);' 
          ohne {} am Ende!

#INCLUDE HEADER -- Für Base Class oder wenn benutzt,
ebenso alle standard libraries die verwendet werden.

v.a. member variables etc.
kein {} am Ende
; am Ende signalisiert dem compliler, das es eine declaration ist.

## Source files. cpp
enthält funciton definition
'#INCLUDE' alle HEADER FILES DIE ES BENUTZT, mindestens sein 'eigenes'.
Ebenso #include alle standard libaries wenn benutzt.

## Constructor and Destructor
no virtual constructor, only virtual destructor!

## std::string
https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/  
**Do not pass by Value** as a parameter, as copying a string is expensive: funct param must be instantiated and initialized with the arguemnt --> gets copied. 

This also applies e.g. to std::cout:
std::string myString = "Hello World";
std::cout << myString << endl; 
so here too, pass by reference.
Instead:

**Returning** a string is ok. But can also be returned by const ref





## Const

### Constant function parameters
so you can not change x inside function (and make that more clear)
WHEN USING REFERENCES!!!
**PASSING BY REFERENCE**


**PASSING BY ADDRESS**



**PASSING BY VALUE**
here wouldnt matter, as x inside function is a copy anyway and gets destroyed after funciton call. **Dont use const when passing by VALUE**

void printInt(const int x)
{
     std::cout << x << endl;
}

### Constant variables
adjacent to variable type:
const int myVar = 3; (best practice)
int const myVar = 3;
#Classes

## Base class / derived class:
### override
https://www.geeksforgeeks.org/override-base-class-method-in-derived-class-in-cpp/
Function overriding is a concept in object-oriented programming languages, in which a function/method of a parent class is redefined in its child class to change its behavior for the objects of the child class. 
Base class Member Function has to be virtual
```
/ Base class Person 
class Person { 
public: 
    // Virtual function to greet 
    virtual void greet() 
    { 
        cout << "Person: Hello, there! \n"; 
    } 
}; 
  
// Derived class AngryPerson inheriting from Person 
class AngryPerson : public Person { 
public: 
    // Override the greet function to provide a different 
    // greeting 
    void greet() override 
    { 
        cout << "Angry Person: Hello, looser! \n"; 
    } 
}; 
```

#### *Pure* virtual function
Base class Member function can be set as 'virtual std::string getName() **= 0**' to be set as a **Pure Virtual Function**


# DELETE:
cmake video bis 43:00 nochmal angeschaut.
