//contains vector of Nucleotide Class (or derived of it).
#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Nucleotide.h"


class Sequence 
{
private:
    // member vars
    std::vector<Nucleotide*> m_nucleotideSequence;

public:
    //de/constructors:

    Sequence() {}; 
    ~Sequence() {}; 

    //getter

    void print() const;

    const std::vector<Nucleotide*>& getSeq() const;


    std::string getSeqString() const;


    bool isEmpty() const;


    //setter

    void add(Nucleotide* i_pNucleotide);


    void clear();


    /*
    Input: string of a sequence.
    String gets parsed and corresponding nucleotides added vector of Nucleotides
    */
    void parseStringToSequence(const std::string& i_line);
}; 

