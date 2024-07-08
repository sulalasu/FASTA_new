// contains Fasta, whcih contains Sequence and Header class as member variablse
//contains vector of Nucleotide Class (or derived of it).
#include "Fasta.h"
#include "Nucleotide.h"


std::vector<Nucleotide*> m_nucleotideSequence;

//de/constructors:

// Sequence::Sequence() {}
// Sequence::~Sequence() {}

//getter

void Sequence::print() const
{
    for (auto elem : m_nucleotideSequence)
    {
        elem->Nucleotide::print();
    }
}

const std::vector<Nucleotide*>& Sequence::getSeq() const 
{
    return m_nucleotideSequence;
}

std::string Sequence::getSeqString() const
{
    std::string SeqString = "";

    for (auto nt : m_nucleotideSequence)
    {
        SeqString += (*nt->getNt());
    }
    return (SeqString);
}

bool Sequence::isEmpty() const
{
    if (m_nucleotideSequence.empty()) 
    {
        return(true);
    }
    else 
    {
        return(false);
    }
}

//setter

void Sequence::add(Nucleotide* i_pNucleotide)
{
    m_nucleotideSequence.push_back(i_pNucleotide);
}

void Sequence::clear() 
{
    m_nucleotideSequence.clear();
}

/*
Input: string of a sequence.
String gets parsed and corresponding nucleotides added vector of Nucleotides
*/
void Sequence::parseStringToSequence(const std::string& i_line) 
{
    for (const auto& nt : i_line)
    {
    switch (nt)
    {
        case 'a':
        case 'A':
            {
            Adenine* pNt = new Adenine();
            Sequence::add(pNt);
            }
            break;
        case 't':
        case 'T':
            {
            Thymine* pNt = new Thymine();
            Sequence::add(pNt);
            } 
            break;

        case 'g':
        case 'G':
            {
            Guanine* pNt = new Guanine();
            Sequence::add(pNt);
            } 
            break;
        case 'c':
        case 'C':
            {
            Cytosine* pNt = new Cytosine();
            Sequence::add(pNt);
            }
            break;

    }
}
}


