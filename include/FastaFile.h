#pragma once

#include <vector>
#include <string>


/* 
a vector containing a sequence of Fasta files,
which each contains a Header and a Sequence class object.
Sequence class contains a Sequence of Nucleotide objects.
*/
class FastaFile
{
private:
    std::vector<Fasta*> m_fastaFile;


public:
    // destructor 
    ~FastaFile();


    // member functions

    std::map<char, int> count(std::string seq) const;
    void drawHistogram();
    void write(const std::string& fileName) const;

    //getter

    void print();

    //setter
    
    void add(Fasta* i_pFasta);
};
