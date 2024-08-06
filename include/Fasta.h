#pragma once

#include "Header.h"
#include "Sequence.h"
/* 
Fasta class to save and output the contents.
Each Fasta Object contains to member variables which are pointers
to a Header and a Sequence Object respectively.
*/
class Fasta
{
private:
    // member vars
    Header* m_pHeader;
    Sequence* m_pSequence;

public:
    // 'structors
    Fasta(); 
    Fasta(Header* i_pHeader, Sequence* i_pSequence);
    ~Fasta() = default;

    // setter

    void addHeaderSeqPair(Header* i_pHeader, Sequence* i_pSequence);

    //getter

    void print() const;
    const Header* getHeader() const;
    const Sequence* getSequence() const; //const std::string* getSequence() const
    const std::string getSequenceString() const;
    const std::string getHeaderString() const;
};