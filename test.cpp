#include <string>
#include <vector>
#include <iostream>

class Student 
{
public:
    std::string name;
    int id;

    Student() {}
    Student(int input) : id(input) {};

    void printId() {
        std::cout << id << std::endl;
    }
};


int main() {

std::vector<Student> classList;

Student* Peter;
Peter->id = 13;
classList.push_back(*Peter);

for (int i = 1; i < 10; i++) {
    Student* k = new Student(i);
    k->name = "brügel";
    classList.push_back(*k);
    k->printId();
}



return 0;
}