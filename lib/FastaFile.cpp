// contains FastaFile, which contains a vector of Fasta
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip> // for setfill, setw


#include "Fasta.h"
#include "FastaFile.h"
#include "Sequence.h"

// destructor
FastaFile::~FastaFile() 
{
    for (auto fasta : m_fastaFile) {
        delete fasta->getSequence();
        delete fasta->getHeader();
        delete fasta; 
    }

    std::cout << "Destructor for Fasta File called.";
}


// member function

/* count number of Nucleotides in a SINGLE Sequence
@param: const reference to string containing Nucleotide Sequence*/
std::map<char, int> FastaFile::count(std::string seq) const
{
    std::map<char, int> hist = {
        {'A', 0},
        {'C', 0}, 
        {'T', 0},
        {'G', 0}
    };
    for (const auto& letter : seq)
    {
        hist[letter]++;
    }
    return hist;
}

/*
calculate sum of nucleotides, then draw percentage based diagrams for each seq.
*/
void FastaFile::drawHistogram()
{
    const Sequence* seq;
    std::string headerString;
    std::string seqString;
    // loop over all Fasta objects within 'FastaFile' object
    for (auto* fasta : m_fastaFile)
    {
        headerString = fasta->getHeaderString();
        seq = fasta->getSequence();
        seqString = seq->getSeqString();

        std::map<char, int> countMap = count(seqString);
        int sum = 0;

        // get sum:
        for (const auto &[k, v] : countMap)
        {
            sum += v;
        }

        //print histogram including Header line
        std::cout << std::endl << headerString << std::endl;
        std::cout << seqString << std::endl;
        for (const auto &[k, v] : countMap)
        {
            std::cout   << k << ": " 
                        << std::setfill(' ') << std::setw(3) << v << " " 
                        << std::string(v*40/sum, 'x') 
                        << std::string(40 - v*40/sum, '-') 
                        << std::endl;
        }
    }
}

void FastaFile::write(const std::string& fileName) const
{       
    std::ofstream outputFile;
    outputFile.open(fileName);
    for (auto elem : m_fastaFile)
    {
        outputFile << elem->getHeaderString();
        outputFile << std::endl;
        outputFile << elem->getSequenceString();
        outputFile << std::endl;

    }
    outputFile.close();
}

//getter

void FastaFile::print()
{
    for (auto fasta : m_fastaFile)
    {
        fasta->print();
        std::cout << std::endl;
    }
}

//setter

void FastaFile::add(Fasta* i_pFasta)
{
    m_fastaFile.push_back(i_pFasta);
}
