#include "Header.h"
#include "Fasta.h"
#include "Sequence.h"

//'structors

Fasta::Fasta() 
    : m_pHeader(nullptr), 
      m_pSequence(nullptr) 
{}

Fasta::Fasta(Header* i_pHeader, Sequence* i_pSequence)
    : m_pHeader(i_pHeader),
      m_pSequence(i_pSequence)
{}

// setter

void Fasta::addHeaderSeqPair(Header* i_pHeader, Sequence* i_pSequence)
{
    this->m_pHeader = i_pHeader;
    this->m_pSequence = i_pSequence;
}

//getter

void Fasta::print() const
{
    m_pHeader->print();
    m_pSequence->print();
}

const Header* Fasta::getHeader() const 
{
    return (m_pHeader);
} 

const Sequence* Fasta::getSequence() const //const std::string* getSequence() const
{
    return (m_pSequence);
}

const std::string Fasta::getSequenceString() const 
{
    return (m_pSequence->getSeqString());
} 


const std::string Fasta::getHeaderString() const 
{
    return (m_pHeader->getHeader());
} 