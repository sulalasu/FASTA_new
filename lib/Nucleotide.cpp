//for Nucleotide Base Class as well as derived Classes
#include <string>
#include <iostream>

#include "Nucleotide.h"


Nucleotide::Nucleotide(std::string i_Nt) : m_Nt(i_Nt) {} // Accessible to derived classes
// Change "protected" to "public" to allow others to instantiate A.

//constructor
Nucleotide::Nucleotide() {}

//destructor
virtual Nucleotide::~Nucleotide() {}

//member functions:
void Nucleotide::print() const
{
    std::cout << m_Nt;
} 
const std::string* Nucleotide::getNt() //cant set function as const as it defines a variable
{
    std::string* nt = &m_Nt;
    return (nt);
}

Adenine::Adenine() : Nucleotide("A") {} // Calls Nucleotide's constructor, initializing m_Nt to 'A'




Thymine::Thymine() : Nucleotide("T") {} // Calls Nucleotide's constructor, initializing m_Nt to 'A'




Guanine::Guanine() : Nucleotide("G") {} // Calls Nucleotide's constructor, initializing m_Nt to 'A'



Cytosine::Cytosine() : Nucleotide("C") {} // Calls Nucleotide's constructor, initializing m_Nt to 'A'
