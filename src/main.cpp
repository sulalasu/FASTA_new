#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "Fasta.h"
#include "FastaFile.h"
#include "Header.h"
#include "Helper.h"
#include "Nucleotide.h"
#include "Sequence.h"

// macros to use for quick printing while programming
#define msgLOG(message, x) std::cout << message << ":  " << x << std::endl;
#define LOG(x) std::cout << x << std::endl;
#define NtLOG() std::cout << pNt->getNt() << std::endl;


//========================================================================  
//                    ---- M A I N ---- 
//========================================================================  

int main(int argc, char* argv[])
{
    // only for debuggin:
    // argc = 3;
    // argv[1] = "../input.fasta";
    // argv[2] = "../output_3.fasta";


    //check for number of command line arguments
    if (argc != 3)
    {
        std::cout << "ERROR: Please supply exactly two arguments: Input Filename and Output filename" << std::endl;
        return 1;
    }

    //initialize pointers to the Nucleotides and fastaFile as global variables:
    Adenine* pAdenine = new Adenine();
    Cytosine* pCytosine = new Cytosine();
    Guanine* pGuanine = new Guanine();
    Thymine* pThymine = new Thymine();

    FastaFile fastaFile;

    PrettyPrint openingMsg(argv[1], "Trying to open file named", ' ');
    openingMsg.consoleOut();

    // open and read file
    std::ifstream inputFile(argv[1]);

    if (inputFile.is_open())
    {
        std::string line;
        std::string sequenceString;
        std::string headerString;

        while (getline(inputFile, line)) 
        {
            //this IF in front, so last line gets read as well
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
                    pSequence->parseStringToSequence(sequenceString, pAdenine, pGuanine, pCytosine, pThymine);
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

    else 
    {
        std::cout << "Couldnt open file '" << argv[1] << "'." << std::endl; 
        return 1;
    }


    // print histogram to console
    PrettyPrint msgHistogram("Histograms:");
    msgHistogram.consoleOut();
    fastaFile.drawHistogram();

    // print resulting FastaFile Object to console (what will be written to Output File)
    PrettyPrint msgResult("Result of reading File:");
    msgResult.consoleOut();
    fastaFile.print();

    // Writing to Output File
    PrettyPrint msgOutputfile(argv[2], "Writing to: ", ' ');
    msgOutputfile.consoleOut();
    fastaFile.write(argv[2]);

    // Message for success
    PrettyPrint msgEnd("Program finished successfully", "", ' ');
    msgEnd.consoleOut();

    delete pGuanine;
    delete pThymine;
    delete pAdenine;
    delete pCytosine;

    return 0;
}
