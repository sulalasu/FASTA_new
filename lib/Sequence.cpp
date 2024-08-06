// contains Fasta, whcih contains Sequence and Header class as member variablse
//contains vector of Nucleotide Class (or derived of it).
#include "Sequence.h"
#include "Nucleotide.h"

// destructor
Sequence::~Sequence() {}

//getter

// prints the sequence to console
void Sequence::print() const
{
    for (auto elem : m_nucleotideSequence)
    {
        elem->Nucleotide::print();
    }
}

// returns the vector containing pointers to Nucleotide Objects
const std::vector<Nucleotide*>& Sequence::getSeq() const 
{
    return m_nucleotideSequence;
}

// returns a String containing the Sequence letters
std::string Sequence::getSeqString() const
{
    std::string SeqString = "";

    for (auto nt : m_nucleotideSequence)
    {
        SeqString += (*nt->getNt());
    }
    return (SeqString);
}

// returns TRUE if Sequence is empty, otherwise FALSE
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

// adds a Nucleotide Pointer to the Nucleotide pointer vector
void Sequence::add(Nucleotide* i_pNucleotide)
{
    m_nucleotideSequence.push_back(i_pNucleotide);
}

// clears the Nucleotide pointer vector
void Sequence::clear() 
{
    m_nucleotideSequence.clear();
}

/*
Input: string of a sequence.
String gets parsed and corresponding nucleotides added vector of Nucleotides
*/
void Sequence::parseStringToSequence(const std::string& i_line, Adenine* pAdenine, Guanine* pGuanine, Cytosine* pCytosine, Thymine* pThymine) 
{
    for (const auto& nt : i_line)
    {
    switch (nt)
    {
        case 'a':
        case 'A':
            {
            //Adenine* pNt = new Adenine();
            Sequence::add(pAdenine);
            }
            break;
        case 't':
        case 'T':
            {
            //Thymine* pNt = new Thymine();
            //Sequence::add(pNt);
            Sequence::add(pThymine);
            } 
            break;

        case 'g':
        case 'G':
            {
            // Guanine* pNt = new Guanine();
            // Sequence::add(pNt);
            Sequence::add(pGuanine);
            } 
            break;
        case 'c':
        case 'C':
            {
            // Cytosine* pNt = new Cytosine();
            // Sequence::add(pNt);
            Sequence::add(pCytosine);
            }
            break;

    }
}
}


