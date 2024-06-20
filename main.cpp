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
// put classes into .c und .h files.


//========================================================================  
//                    helper functions 
//========================================================================  



//========================================================================  
//                    classes 
//========================================================================  

class Nucleotide {};

class Adenine : public Nucleotide {};
class Thymine : public Nucleotide {};
class Guanine : public Nucleotide {};
class Cytosine : public Nucleotide {};


//-> contains vector of nucleotides.
class Sequence 
{
private:
    std::vector<Nucleotide> m_nucleotideSequence;
public:
    void addNucleotide(const Nucleotide& i_nucleotide)
    {
        m_nucleotideSequence.push_back(i_nucleotide);
    }
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
if (argc != 2)
{
    std::cout << "ERROR: Please supply exactly one argument, which is the filename" << std::endl;
}
std::cout << "Opening file named: " << argv[1] << std::endl;

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
std::vector<Nucleotide> nucleotideSequence;
bool newHeader = true;

// open and read file
std::ifstream inputFASTA;
inputFASTA.open(argv[1]);

// if successfully opened, read line by line
if (inputFASTA.is_open())
{
    // TODO:
    // clear line and sequence and header
    // then: start while loop
    // in while loop: 
    while (getline(inputFASTA, line)) 
    {

        if (line[0] == '>' && newHeader == true)
        // its a comment line:
        {
            Header* tempHeader = new Header(line);
            tempHeader->printHeader();
            //newHeader = false;
        }
        else
        {
            std::cout << "\nnot a header\n" << line << "\n" << std::endl;
            for (const auto& nt : line)
            {
                //TODO: switch statement to decide between nucleotides.x
                switch (nt)
                {
                    case 'a':
                    case 'A':
                        std::cout << "case a - " << nt << std::endl;
                        //TODO: add new nucleotide instance to 'nucleotideSequence' vector
                    case 't':
                    case 'T':
                        std::cout << "case t - " << nt << std::endl;
                    case 'g':
                    case 'G':
                        std::cout << "case g - " << nt << std::endl;
                    case 'c':
                    case 'C':
                        std::cout << "case c - " << nt << std::endl;
                }
                //nucleotideSequence.push_back()
                //std::cout << nt << " ";
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
