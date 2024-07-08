#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip> // for setfill, setw

#include "Helper.h"
#include "Fasta.h"
#include "FastaFile.h"
#include "Nucleotide.h"

#define msgLOG(message, x) std::cout << message << ":  " << x << std::endl;
#define LOG(x) std::cout << x << std::endl;
#define NtLOG() std::cout << pNt->getNt() << std::endl;


//========================================================================  
//                    helper functions 
//========================================================================  





//========================================================================  
//                    classes 
//========================================================================  





/*
contains a string with the header info
*/
class Header
{
private:
    std::string m_header;

public:
    //'structors

    Header() : m_header() {}
    Header(const std::string& i_header) : m_header(i_header) {}
    ~Header() = default;

    //getter:

    void print() const
    {
        std::cout << m_header << std::endl;
    }

    const std::string& getHeader() const
    {
        return m_header;
    }

    bool isEmpty() const
    {
        if (m_header.empty()) 
        {
            return(true);
        }
        else 
        {
            return(false);
        }
    }

    //setter:

    void append(const std::string& i_newComment)
    {
        m_header = m_header + i_newComment;
    }
    void clear()
    {
        m_header = "";
    }

};


/* 
Final Class Object: Fasta class to save and output the contents.
Contains a vector of alternating Header and Sequence.
Sequences are made up of individual instances of Nucleotide class.
*/
class Fasta
{
private:
    Header* m_pHeader;
    Sequence* m_pSequence;

public:
    Fasta() 
    : m_pHeader(nullptr),
      m_pSequence(nullptr)
    {}
    Fasta(Header* i_pHeader, Sequence* i_pSequence)
    : m_pHeader(i_pHeader),
      m_pSequence(i_pSequence)
    {}
    ~Fasta() = default;

    // setter

    void addHeaderSeqPair(Header* i_pHeader, Sequence* i_pSequence)
    {
        this->m_pHeader = i_pHeader;
        this->m_pSequence = i_pSequence;
    }

    //getter

    void print() const
    {
        m_pHeader->print();
        m_pSequence->print();
    }
    
    const std::string getHeader() const 
    {
        return (m_pHeader->getHeader());
        // TODO: add return function
    } 

    const Sequence* getSequence() const //const std::string* getSequence() const
    {
        return (m_pSequence);
    }

    const std::string getSequenceString() const 
    {
        return (m_pSequence->getSeqString());
        // TODO: add return function
    } 
    // {
    //     return (m_pSequence->getSeqString());
    // }
};

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
    // count number of Nucleotides in a SINGLE Sequence
    // @param: const reference to string containing Nucleotide Sequence
    std::map<char, int> count(std::string seq) const
    {
        //std::string seq = getAllSeqAsString();
        //TODO: add count of occurences in collected sequence
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
    void drawHistogram()
    {
        const Sequence* seq;
        std::string headerString;
        std::string seqString;
        // loop over all Fasta objects within 'FastaFile' object
        for (auto* fasta : m_fastaFile)
        {
            headerString = fasta->getHeader();
            seq = fasta->getSequence();
            seqString = seq->getSeqString();


            //TODO: draw histogram
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

    // member function
    void write(const std::string& fileName) const
    {       
        std::ofstream outputFile;
        outputFile.open(fileName);
        for (auto elem : m_fastaFile)
        {
            outputFile << elem->getHeader();
            outputFile << std::endl;
            outputFile << elem->getSequenceString();
            outputFile << std::endl;

        }
        outputFile.close();
    }

    //getter

    void print()
    {
        for (auto fasta : m_fastaFile)
        {
            fasta->print();
            std::cout << std::endl;
        }
    }

    //setter
    
    void add(Fasta* i_pFasta)
    {
        m_fastaFile.push_back(i_pFasta);
    }
};



//========================================================================  
//                    ---- M A I N ---- 
//========================================================================  

int main(int argc, char* argv[])
{
// argc = 3;
// argv[1] = "input.fasta";
// argv[2] = "output.fasta";

//check for number of command line arguments
if (argc != 3)
{
    std::cout << "ERROR: Please supply exactly two arguments: Input Filename and Output filename" << std::endl;
    return 1;
}


PrettyPrint openingMsg(argv[1], "Trying to open file named", ' ');
openingMsg.consoleOut();
// open and read file

std::ifstream inputFile(argv[1]);
FastaFile fastaFile;

if (inputFile.is_open())
{
    std::string line;
    std::string sequenceString;
    std::string headerString;

    while (getline(inputFile, line)) 
    {
        //put this in front, so last line gets read as well
        if (line[0] != '>')
        {
            sequenceString += line;
        }

        // separate IF to catch last line; check eof to not have to write same code twice (for appending last seq/header)
        if (line[0] == '>' || inputFile.eof() == true) 
        {
            // the previous Header/Sequence is fully filled and can be appended to Fasta object
            if(!headerString.empty() && !sequenceString.empty())
            {
                Header* pHeader = new Header();
                Sequence* pSequence = new Sequence();
                Fasta* pFasta = new Fasta();

                pHeader->append(headerString);
                pSequence->parseStringToSequence(sequenceString);
                pFasta->addHeaderSeqPair(pHeader, pSequence);
                fastaFile.add(pFasta);
                sequenceString.clear();
                headerString.clear();

            }
            
            // to remove '>' if two consecutive header lines in input
            if (!headerString.empty() == true) 
            {
                headerString += line.substr(1);
            }
            // normal header line
            else 
            { 
                headerString = line; 
            }
        }
    }
inputFile.close();
}
//}   

else 
{
    std::cout << "Couldnt open file '" << argv[1] << "'." << std::endl; 
    return 1;
}

PrettyPrint msgHistogram("Histograms:");
msgHistogram.consoleOut();
fastaFile.drawHistogram();

PrettyPrint msgResult("Result of reading File:");
msgResult.consoleOut();

fastaFile.print();

PrettyPrint msgOutputfile(argv[2], "Writing to: ", ' ');
msgOutputfile.consoleOut();
fastaFile.write(argv[2]);


PrettyPrint msgEnd("Program finished successfully", "", ' ');
msgEnd.consoleOut();
return 0;
}
