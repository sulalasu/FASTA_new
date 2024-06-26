#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <set>

#define msgLOG(message, x) std::cout << message << ":  " << x << std::endl;
#define LOG(x) std::cout << x << std::endl;

// TODO: Big todos:
// make child class of ACTG of base class nucleotide
// find out, how to add new nucleotide class to sequence vector
// how to make sure, right header is mapped to right sequence
// clean up main by converting code parts to functions
// add destructors 
// put classes into .c und .h files.


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
    virtual void printNt() const = 0; // const here: function does not modify member data in the class it is a part of
    virtual std::string returnNt() const = 0; // pure virtual function => no definition,
    // but subclasses will have a definition
};


class Adenine : public Nucleotide 
{
public:
    // Member Functions
    void printNt() const override
    {
        std::cout << m_Nt;
    };

    std::string returnNt() const override
    {
        return (m_Nt);
    };

private:
    const std::string m_Nt = "A";
};


class Thymine : public Nucleotide
{
public:
    // Member Functions
    void printNt() const override
    {
        std::cout << m_Nt;
    };

    std::string returnNt() const override
    {
        return (m_Nt);
    };

private:
    const std::string m_Nt = "T";
};


class Guanine : public Nucleotide
{
public:
    // Member Functions
    void printNt() const override
    {
        std::cout << m_Nt;
    };

    std::string returnNt() const override
    {
        return (m_Nt);
    };

private:
    const std::string m_Nt = "G";
};


class Cytosine : public Nucleotide 
{
public:
    // Member Functions
    void printNt() const override
    {
        std::cout << m_Nt;
    };

    std::string returnNt() const override
    {
        return (m_Nt);
    };

private:
    const std::string m_Nt = "G";
};





//-> contains vector of nucleotides.
class Sequence 
{
private:
    std::vector<Nucleotide* > m_nucleotideSequence;
public:
    //constructors:
    Sequence() {}
    //destructor:
    ~Sequence() {}

    void addNucleotide(Nucleotide* i_nucleotide)
    {
        m_nucleotideSequence.push_back(i_nucleotide);
    }

    //TODO: make a member function, that prints all nucleotides
    // void printSeq()
    // {
    //     for (auto elem : m_nucleotideSequence)
    //     {
    //         elem->print()
    //     }
    // }
}; 


class Header
{
private:
    //member vars
    std::string m_comment;

public:
    //constructor
    Header(const std::string& i_commentString) : m_comment(i_commentString) {}
    //destructor
        //TODO

    //getter:
    void printHeader() 
    {
        std::cout << "Header comment:\n" << m_comment << std::endl;
    }
    const std::string& getHeader() const
    {
        return m_comment;
    }
};


// Final Class Object: FASTA class to save and output the contents.
// Contains a vector of alternating Header and Sequence.
// Sequences are made up of individual instances of Nucleotide class.
class FASTA
{
private:
    std::map<Header, Sequence> m_contents;
public:

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

bool previousLineWasHeader = false; //maybe use bool to check if new or old header-seq pair?
//dürfen keine pointer sein, weil sie ja auf line zeigen und diese sich immer verändert! (denke ich)
//Header currentHeader; // use to later append to mapping 
Sequence currentSequence; //use to later append to mapping

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
    // in while loop (while iterating over lines:)
    //      if line startswith '<': add new Header obj.
    //      set newHeader to false.
    //      next line
    while (getline(inputFASTA, line)) 
    {
        //std::cout << line << std::endl;
        if (line[0] == '>' && previousLineWasHeader == true)
        // line = header
        // TODO: add empty sequence to mapping
        {
            Header* tempHeader = new Header(line);
            tempHeader->printHeader();
            //newHeader = false;
        }
        else if (line[0] == '>' && previousLineWasHeader == false)
        // line = new header --> add to mapping.
        {
            //currentHeader = line;
        }
        else
        // line = sequence line
        {
            std::cout << "\nnot a header\n" << line << "\n" << std::endl;
            for (const auto& nt : line)
            {
                //TODO: switch statement to decide between nucleotides.
                switch (nt)
                {
                    case 'a':
                    case 'A':
                    {
                        std::cout << "case a - " << nt << std::endl;
                        Adenine* pA = new Adenine;
                        currentSequence.addNucleotide(pA);
                        // delete pA;
                        // wir reservieren im Heap speicher für eine instanz der klasse
                        // adenine, unser pointer pA zeigt auf diesen speicher.
                        //TODO: add new nucleotide instance to 'nucleotideSequence' vector
                    }
                    case 't':
                    case 'T':
                    {
                        std::cout << "case t - " << nt << std::endl;
                    }
                    case 'g':
                    case 'G':
                    {
                        std::cout << "case g - " << nt << std::endl;
                    }
                    case 'c':
                    case 'C':
                    {
                        std::cout << "case c - " << nt << std::endl;
                    }
                }
                //nucleotideSequence.push_back()
                //std::cout << nt << " ";
                //nucleotideSequence.printSeq();
            }
            std::cout << std::endl;
        }

    // TODO:
    // if line is a Sequence, iterate over it, letter by letter, and assign to corresponding subclass in vector in seqElement
    // how do i test it? einfach annhemen, dass es nur Header/Seq. gibt? Oder != startswith (">", ";", "#")?
    }   
}
else {
    std::cout << "Couldnt open file '" << argv[1] << "'." << std::endl; 
}

inputFASTA.close();



std::cout << "\n\nprogram out" << std::endl;

return 0;
}
