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
// TODO: add id?
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
    Fasta() = delete;
    Fasta(Header* i_pHeader, Sequence* i_pSequence)
    : m_pHeader(i_pHeader),
      m_pSequence(i_pSequence)
    {}

    // void addHeaderSeqPair(Header* i_pHeader, Sequence* i_pSequence)
    // {
    //     this->m_pHeader = i_pHeader;
    //     this->m_pSequence = i_pSequence;
    // }

    ~Fasta() = default;


    //setter
    // void addHeaderSeqPair(Header* i_pHeader, Sequence* i_pSequence)
    // {
    //     this->m_pHeader = i_pHeader;
    //     this->m_pSequence = i_pSequence;
    // }
    // // TODO: will ich wirklich einzelne header/seq hinzufügen?
    // void addHeader(Header* i_pHeader)
    // {
    //     m_pHeader = i_pHeader;
    // }
    // void addSeq(Sequence* i_pSequence) //input kann nicht const sein.
    // {
    //     m_pSequence = i_pSequence;
    // }

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
    void print()
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
argc = 3;
argv[1] = "input.fasta";
argv[2] = "output.fasta";

//check for number of command line arguments
if (argc != 3)
{
    std::cout << "ERROR: Please supply exactly two arguments: Input Filename and Output filename" << std::endl;
    return 1;
}
std::cout << "Opening file named: " << argv[1] << std::endl;
std::cout << "Writing to: " << argv[2] << std::endl;

// declare necessary variables
// TODO: cann ich die ganzen 'new' eventuell in die loop bringen und mir damit das clear sparen?
std::string line;
Sequence* pCurrentSequence = new Sequence(); //use to later append to mapping
Header* pCurrentHeader = new Header(); // use to fill/empty with current header info
// Sequence* pCurrentSequence = nullptr;
// Header* pCurrentHeader = nullptr;

FastaFile fastaFile;
bool newHeader = true; //use bool to check if new or old header-seq pair?


// open and read file
std::ifstream inputFasta;
std::cout << argv[1] << std::endl;
inputFasta.open(argv[1]);

int lineNumber = 0;
// if successfully opened, read line by line
if (inputFasta.is_open())
{
    // TODO: last header/seq pair is missing!
    // TODO: clear line and sequence and header variables
    // then: start while loop

    //TODO: in 1 aus 2 verschachteltet funtionen bestehende funktion verpacken:
    // außen: while loop + if else if
    // innen: switch-case-fun
    while (getline(inputFasta, line)) 
    {
        
        // if (lineNumber == 0) 
        // {
        //     Sequence* pCurrentSequence = new Sequence(); //use to later append to mapping
        //     Header* pCurrentHeader = new Header(); // use to fill/empty with current header info

        // }

        if (line.empty()) 
        {
            continue;
        }

        // line is a comment AND the first line of a Header (newHeader == true)
        else if ((line[0] == '>' && newHeader == true) || inputFasta.eof())
        {
            
            // the previous Header/Sequence are fully filled and can be appended to Fasta object
            if (!pCurrentHeader->isEmpty() && !pCurrentSequence->isEmpty())
            {
                // LOG("Adding header and sequence to fasta: ");
                // msgLOG("Header", pCurrentHeader->getHeader());
                // msgLOG("Sequen", pCurrentSequence->getSeqString());
                Fasta* pCurrentFasta = new Fasta(pCurrentHeader, pCurrentSequence);
                // LOG("print current sequence: ");
                // pCurrentHeader->print();
                fastaFile.add(pCurrentFasta);
                LOG("print Fasta File:_____________");
                fastaFile.print();
                LOG("_____________________________");
                Header* pCurrentHeader = new Header();
                Sequence* pCurrentSequence = new Sequence();
                // pCurrentHeader->clear();
                // pCurrentSequence->clear();
            }
            // start new header
            else 
            { 
                pCurrentHeader->append(line);
            }
            
            newHeader = false; 
            continue;
        }

        // line is second line of a header --> append to previous header
        else if (line[0] == '>' && newHeader == false)
        {
            pCurrentHeader->append(line.substr(1)); // removes ">" from beginning of second header line
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
                        pCurrentSequence->add(pNt);
                        }
                        break;
                    case 't':
                    case 'T':
                        {
                        Thymine* pNt = new Thymine();
                        pCurrentSequence->add(pNt);
                        } 
                        break;

                    case 'g':
                    case 'G':
                        {
                        Guanine* pNt = new Guanine();
                        pCurrentSequence->add(pNt);
                        } 
                        break;
                    case 'c':
                    case 'C':
                        {
                        Cytosine* pNt = new Cytosine();
                        pCurrentSequence->add(pNt);
                        }
                        break;

                }
            }
        }
    lineNumber++;
    }   
    //currentFasta->print(); // --> existier hier nicht, da lokal in loop erzeugt wurde!

}
else {
    std::cout << "Couldnt open file '" << argv[1] << "'." << std::endl; 
}



inputFasta.close();

std::cout << "AM ende erhalten wir: " << std::endl;
fastaFile.print();

std::cout << "\n\nprogram out" << std::endl;

return 0;
}
