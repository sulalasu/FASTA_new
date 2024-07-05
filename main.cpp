#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <set>

#define msgLOG(message, x) std::cout << message << ":  " << x << std::endl;
#define LOG(x) std::cout << x << std::endl;

// auch member ufnctions selber sollten const gesetzt werden:
//long getNumber() const {}

// getter als const std:type& getXXX() const {return m_XXXX}
// das heißt als const ref übergeben (außer triviale datentypen)

// im .cpp file (definitionen) immer Klasse::Klasse oder Klasse::Klassenfunktion 

// TODO: Big todos:
// make child class of ACTG of base class nucleotide
// find out, how to add new nucleotide class to sequence vector
// how to make sure, right header is mapped to right sequence
// clean up main by converting code parts to functions
// add destructors 
// put classes into .c und .h files.

//switch case: add breaks
// then: try to change ACGT classes so that they are all derived from base
// (meaning, they dont have classes, but use base functions and member vars)

//========================================================================  
//                    helper functions 
//========================================================================  



//========================================================================  
//                    classes 
//========================================================================  

class Nucleotide 
{
public:
    //constructor
    Nucleotide() {}
    
    //destructor
    virtual ~Nucleotide() {}

    //member functions:
    void printNt() const
    {
        std::cout << m_Nt;
    } 
    std::string returnNt() const
    {
        return (m_Nt);
    };
protected:
    Nucleotide(std::string i_Nt) : m_Nt(i_Nt) {} // Accessible to derived classes
    // Change "protected" to "public" to allow others to instantiate A.
private:
    std::string m_Nt;
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





//contains vector of Nucleotide Class (or derived of it).
class Sequence 
{
private:
    std::vector<Nucleotide*> m_nucleotideSequence;

public:
    //de/constructors:
    Sequence() {}
    ~Sequence() {}

    //getter
    void printSeq() const
    {
        for (auto elem : m_nucleotideSequence)
        {
            elem->printNt();
        }
    }
    bool isEmpty() const
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
    void addNucleotide(Nucleotide* i_nucleotide)
    {
        m_nucleotideSequence.push_back(i_nucleotide);
    }

    void clear() 
    {
        m_nucleotideSequence.clear();
    }
}; 


class Header
{
private:
    std::string m_header;

public:
    //constructor
    Header() {}
    Header(const std::string& i_header) : m_header(i_header) {}
    //destructor
    ~Header() = default;

    //getter:
    void printHeader() const
    {
        std::cout << "Header: " << m_header << "|__" << std::endl;
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
    void appendNewLine(const std::string& i_newComment)
    {
        m_header = m_header + i_newComment;
    }
    void clear()
    {
        m_header = "";
    }

};


// Final Class Object: FASTA class to save and output the contents.
// Contains a vector of alternating Header and Sequence.
// Sequences are made up of individual instances of Nucleotide class.
class FASTA
{
private:
    Header* m_header;
    Sequence* m_sequence;

public:
    FASTA() {}
    ~FASTA() = default;


    //setter
    void addHeaderSeqPair(Header* i_header, Sequence* i_sequence)
    {
        this->m_header = i_header;
        this->m_sequence = i_sequence;
    }
    void addHeader(Header* i_header)
    {
        m_header = i_header;
    }
    void addSeq(Sequence* i_sequence)
    {
        m_sequence = i_sequence;
    }

    //getter
    void printFASTA() const
    {
        std::cout << "Fasta (Header-Sequence Pair):" << std::endl;
        m_header->printHeader();
        std::cout << std::endl;
        m_sequence->printSeq();
        std::cout << std::endl;
    }
};



//========================================================================  
//                    ---- M A I N ---- 
//========================================================================  

int main(int argc, char* argv[])
{

//check for number of command line arguments
if (argc != 3)
{
    std::cout << "ERROR: Please supply exactly two arguments: Input Filename and Output filename" << std::endl;
    return 1;
}
std::cout << "Opening file named: " << argv[1] << std::endl;
std::cout << "Writing to: " << argv[2] << std::endl;


//main programn:

// // open input file, store lines in vector
// std::vector<std::string> inputFastaVector = readFastaFile(argv); //intellisense says error, but works fine.

// std::vector<char> seqLetterVector; // for storing sequence of letters
// std::vector<SequenceElement*> sequenceElements; // to store pointers to SequenceElement objects
// bool seqContinue = true; // true as long as not encounterd header line again. (if seq is mulitple lines)

// for (std::string line : inputFastaVector) 
// {
//     if (!line.empty() && line[0] == '>') // is Header
//     {
//         SequenceElement* p_SeqElem = new SequenceElement;
//         p_SeqElem->addHeader(line);
//         sequenceElements.push_back(p_SeqElem);
//         seqContinue = false;
//         std::cout << "should add line to header: " << line << std::endl;
//         //sequenceElement.addHeader(line);

//     }
//     else
//     {
//         if (!line.empty())
//         {
//             seqContinue = true;
//             seqLetterVector.clear(); // make sure vector is empty
//             //TODO: ich will alle zeilen zu einer zusammenfassen, bis wieder ein '>' vorkommt udn alls ein Sequence objekt sspeichern.
//             std::cout << "should add combine non-header lines and add to seq: " << line << std::endl;
//             //sequenceElement.addSequence(line);
//             //seqLetterVector.push_back(line.begin(), line.end())
//         }
//     }
// }

// declare necessary variables
std::string line;
std::vector<Nucleotide*> nucleotideSequence;
FASTA global_FASTA;

bool newHeader = true; //maybe use bool to check if new or old header-seq pair?
//dürfen keine pointer sein, weil sie ja auf line zeigen und diese sich immer verändert! (denke ich)
//Header currentHeader; // use to later append to mapping 
Sequence currentSequence; //use to later append to mapping
Header currentHeader; // use to fill/empty with current header info

// open and read file
std::ifstream inputFASTA;
std::cout << argv[1] << std::endl;
inputFASTA.open(argv[1]);


// if successfully opened, read line by line
if (inputFASTA.is_open())
{
    // TODO:
    // clear line and sequence and header variables
    // then: start while loop

    //TODO: in 1 aus 2 verschachteltet funtionen bestehende funktion verpacken:
    // außen: while loop + if else if
    // innen: switch-case-fun
    while (getline(inputFASTA, line)) 
    {

        if (line.empty()) 
        {
            continue;
        }
        else if (line[0] == '>' && newHeader == true)
        // TODO: add empty sequence to mapping
        {
            if (!currentHeader.isEmpty() && !currentSequence.isEmpty())
            {
            global_FASTA.addHeaderSeqPair(currentHeader, currentSequence);
            currentHeader.clear();
            currentSequence.clear();
            }

            // std::cout << "1. Header:   " << line << std::endl;
            Header* tempHeader = new Header(line);
            //tempHeader->printHeader();
            newHeader = false;
            //tempseq =  
            currentHeader.appendNewLine(line);
        }
        else if (line[0] == '>' && newHeader == false)
        // line --> append to previous header
        {
            currentHeader.appendNewLine(line);
        }
        else
        // line = sequence line
        {
            newHeader = true;

            for (const auto& nt : line)
            {
                //TODO: switch statement to decide between nucleotides.
                switch (nt)
                {
                    case 'a':
                    case 'A':
                        {
                        Adenine* pNt = new Adenine;
                        currentSequence.addNucleotide(pNt);

                        // delete pA;
                        // wir reservieren im Heap speicher für eine instanz der klasse
                        // adenine, unser pointer pA zeigt auf diesen speicher.
                        //TODO: add new nucleotide instance to 'nucleotideSequence' vector
                        }
                        break;
                    case 't':
                    case 'T':
                        {
                        Thymine* pNt = new Thymine;
                        currentSequence.addNucleotide(pNt);
                        } 
                        break;

                    case 'g':
                    case 'G':
                        {
                        Guanine* pNt = new Guanine;
                        currentSequence.addNucleotide(pNt);
                        } 
                        break;
                    case 'c':
                    case 'C':
                        {
                        Cytosine* pNt = new Cytosine;
                        currentSequence.addNucleotide(pNt);

                        }
                        break;
                }
                //nucleotideSequence.push_back()
                //std::cout << nt << " ";
                //nucleotideSequence.printSeq();
            }
            //std::cout << std::endl;
        }
    std::cout << "\nHeader: ";
    currentHeader.printHeader();
    std::cout << "Sequence: ";
    currentSequence.printSeq();
    std::cout << std::endl;
    // TODO:
    // Add Header and sequence to FASTA
    // clean both variables


    }   
}
else {
    std::cout << "Couldnt open file '" << argv[1] << "'." << std::endl; 
}

inputFASTA.close();



std::cout << "\n\nprogram out" << std::endl;

return 0;
}
