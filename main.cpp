#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <set>

#define msgLOG(message, x) std::cout << message << ":  " << x << std::endl;
#define LOG(x) std::cout << x << std::endl;
#define NtLOG() std::cout << pNt->getNt() << std::endl;


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
private:
    std::string m_Nt;

protected:
    Nucleotide(std::string i_Nt) : m_Nt(i_Nt) {} // Accessible to derived classes
    // Change "protected" to "public" to allow others to instantiate A.

public:
    //constructor
    Nucleotide() {}
    
    //destructor
    virtual ~Nucleotide() {}

    //member functions:
    void print() const
    {
        std::cout << m_Nt;
    } 
    std::string getNt() const
    {
        return (m_Nt);
    };
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
    void print() const
    {
        for (auto elem : m_nucleotideSequence)
        {
            elem->Nucleotide::print();
        }
    }

    const std::vector<Nucleotide*>& getSeq() const 
    {
        return m_nucleotideSequence;
    }

    const std::string getSeqString() const
    {
        std::string SeqString;

        for (const auto& nt : m_nucleotideSequence)
        {
            SeqString.append(nt->getNt());
        }
        return (SeqString);
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
    void add(Nucleotide* i_pNucleotide)
    {
        m_nucleotideSequence.push_back(i_pNucleotide);
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
    //'structors
    Header() {} // TODO: brauche ich den default constructor? --> ja, weil ich ja zuerst
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


// Final Class Object: Fasta class to save and output the contents.
// Contains a vector of alternating Header and Sequence.
// Sequences are made up of individual instances of Nucleotide class.
class Fasta
{
private:
    Header* m_pHeader;
    Sequence* m_pSequence;

public:
    Fasta() {}
    ~Fasta() = default;


    //setter
    void addHeaderSeqPair(Header* i_pHeader, Sequence* i_pSequence)
    {
        this->m_pHeader = i_pHeader;
        this->m_pSequence = i_pSequence;
    }
    // TODO: will ich wirklich einzelne header/seq hinzufügen?
    void addHeader(Header* i_pHeader)
    {
        m_pHeader = i_pHeader;
    }
    void addSeq(Sequence* i_pSequence) //input kann nicht const sein.
    {
        m_pSequence = i_pSequence;
    }

    //getter
    void print() const
    {
        std::cout << "Fasta (Header-Sequence Pair):" << std::endl; //TODO: remove
        m_pHeader->print();
        std::cout << std::endl;
        m_pSequence->print();
        std::cout << std::endl;
    }
    // TODO: add return function
    void getFasta() const 
    {

    } 
};

class FastaFile
// a vector containing a sequence of Fasta files,
// which each contains a Header and a Sequence class object.
// Sequence class contains a Sequence of Nucleotide objects.
{
private:
    std::vector<Fasta*> fastaFile;

public:
    //getter
    void print(FastaFile)
    {
        for (auto fasta : fastaFile)
        {
            fasta->print();
            std::cout << std::endl;
        }
    }

    //setter
    void add(Fasta* i_pFasta)
    {
        fastaFile.push_back(i_pFasta);
    }
};

//========================================================================  
//                    ---- M A I N ---- 
//========================================================================  

int main(int argc, char* argv[])
{
//for debugging:
// TODO: REMOVE!
// argc = 3;
// argv[1] = "input.fasta";
// argv[2] = "output.fasta";

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
Sequence* currentSequence = new Sequence(); //use to later append to mapping
Header* currentHeader = new Header(); // use to fill/empty with current header info
Fasta currentFasta;
FastaFile fastaFile;
bool newHeader = true; //maybe use bool to check if new or old header-seq pair?
//dürfen keine pointer sein, weil sie ja auf line zeigen und diese sich immer verändert! (denke ich)
//Header currentHeader; // use to later append to mapping 


// open and read file
std::ifstream inputFasta;
std::cout << argv[1] << std::endl;
inputFasta.open(argv[1]);


// if successfully opened, read line by line
if (inputFasta.is_open())
{
    // TODO: clear line and sequence and header variables
    // then: start while loop

    //TODO: in 1 aus 2 verschachteltet funtionen bestehende funktion verpacken:
    // außen: while loop + if else if
    // innen: switch-case-fun
    while (getline(inputFasta, line)) 
    {

        if (line.empty()) 
        {
            continue;
        }

        // line is a comment AND the first line of a Header (newHeader == true)
        else if (line[0] == '>' && newHeader == true)
        {
            
            // the previous Header/Sequence are fully filled and can be appended to Fasta object
            if (!currentHeader->isEmpty() && !currentSequence->isEmpty())
            {
                currentFasta.addHeaderSeqPair(currentHeader, currentSequence);
                //std::cout << "----Header: " << currentHeader->getHeader() << std::endl;
                std::cout << "----------- CURRENT FASTA ------------: " << std::endl;
                currentFasta.print();
                currentHeader->clear();
                currentSequence->clear();
            }
            // start new header
            else 
            { 
                currentHeader->append(line);
            }
            
            newHeader = false; 
            continue;
        }

        // line is second line of a header --> append to previous header
        else if (line[0] == '>' && newHeader == false)
        {
            currentHeader->append(line.substr(1)); // removes ">" from beginning of second header line
        }

        else
        // line is a sequence
        {
            newHeader = true;

            for (const auto& nt : line)
            {
                switch (nt)
                {
                    case 'a':
                    case 'A':
                        {
                        Adenine* pNt = new Adenine();
                        currentSequence->add(pNt);
                        }
                        break;
                    case 't':
                    case 'T':
                        {
                        Thymine* pNt = new Thymine();
                        currentSequence->add(pNt);
                        } 
                        break;

                    case 'g':
                    case 'G':
                        {
                        Guanine* pNt = new Guanine();
                        currentSequence->add(pNt);
                        } 
                        break;
                    case 'c':
                    case 'C':
                        {
                        Cytosine* pNt = new Cytosine();
                        currentSequence->add(pNt);
                        }
                        break;

                }
            }
        }
    }   
    // std::cout << "\nHeader: ";
    // currentHeader->print();
    // std::cout << "Sequence: ";
    // currentSequence->print();
    // std::cout << std::endl;
    // TODO: Add Header and sequence to Fasta, clean both variables
    std::cout << "print current sequence: ";
    currentSequence->print();
    std::cout << std::endl;
    currentFasta.print();
    //fastaFile.add(currentFasta);

}
else {
    std::cout << "Couldnt open file '" << argv[1] << "'." << std::endl; 
}



inputFasta.close();

//fastaFile.print();

std::cout << "\n\nprogram out" << std::endl;

return 0;
}
