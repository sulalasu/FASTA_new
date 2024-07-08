#pragma once

#include <string>
#include <iostream>



class Nucleotide 
{
private:
    std::string m_Nt;

protected:
    Nucleotide(std::string i_Nt) : m_Nt(i_Nt) {} // Accessible to derived classes
    // Change "protected" to "public" to allow others to instantiate A.

public:
    //constructor
    Nucleotide() {}
    
    //destructor
    virtual ~Nucleotide() {}

    //member functions:
    void print() const
    {
        std::cout << m_Nt;
    } 
    const std::string* getNt() //cant set function as const as it defines a variable
    {
        std::string* nt = &m_Nt;
        return (nt);
    };
};


class Adenine : public Nucleotide 
{
public:
    Adenine() : Nucleotide("A") {} // Calls Nucleotide's constructor, initializing m_Nt to 'A'
};


class Thymine : public Nucleotide
{
public:
    Thymine() : Nucleotide("T") {} // Calls Nucleotide's constructor, initializing m_Nt to 'A'
};


class Guanine : public Nucleotide
{
public:
    Guanine() : Nucleotide("G") {} // Calls Nucleotide's constructor, initializing m_Nt to 'A'
};


class Cytosine : public Nucleotide 
{
public:
    Cytosine() : Nucleotide("C") {} // Calls Nucleotide's constructor, initializing m_Nt to 'A'
};
