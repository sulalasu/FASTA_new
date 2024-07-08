// contains helper functions
#include <string>
#include <iostream>

#include "Helper.h"

// structor

//PrettyPrint::PrettyPrint() = delete;
PrettyPrint::PrettyPrint(   const std::string& i_highlight, 
                            const std::string& i_message, 
                            char i_lineChar, 
                            int i_totalwidth) 
  : m_message(i_message),
    m_highlight(i_highlight),
    m_lineChar(i_lineChar),
    m_totalwidth(totalWidth(i_totalwidth)),
    m_msgSpacing(spacingMessage()),
    m_highlightSpacing(spacingHighlight())
{}

PrettyPrint::~PrettyPrint() = default;

int PrettyPrint::totalWidth(const int i_totalWidth)
{
    if (m_message.length() > i_totalWidth) 
    {
        return ( m_message.length() + 2 );
    }
    else 
    {
        return (m_totalwidth = i_totalWidth);
    }
}

int PrettyPrint::spacingMessage()
{ 
    return ((m_totalwidth-m_message.length()) / 2);
}

int PrettyPrint::spacingHighlight()
{ 
    return ((m_totalwidth-m_highlight.length()) / 2);
}


// member functions

void PrettyPrint::consoleOut() const
{
    std::cout << "\n" 
    << std::string(m_msgSpacing, ' ')
    << m_message << "\n"
    << std::string(m_totalwidth, m_lineChar)
    << "\n" 
    << std::string(m_highlightSpacing, ' ')
    << m_highlight << "\n"
    << std::string(m_totalwidth, m_lineChar)
    << std::endl;    
}
