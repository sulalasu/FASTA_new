#include <string>
#include <iostream>

#include "Header.h"

//std::string m_header;


//'structors

Header::Header() : m_header() {}
Header::Header(const std::string& i_header) : m_header(i_header) {}

//getter:

void Header::print() const
{
    std::cout << m_header << std::endl;
}

const std::string& Header::getHeader() const
{
    return m_header;
}

bool Header::isEmpty() const
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

void Header::append(const std::string& i_newComment)
{
    m_header = m_header + i_newComment;
}

void Header::clear()
{
    m_header = "";
}

