//Class XXX
// ; am Ende

#pragma once

#include <string>

class PrettyPrint
{
private:
    std::string m_message;
    std::string m_highlight;
    char m_lineChar;
    int m_totalwidth;
    int m_msgSpacing;
    int m_highlightSpacing;

    int totalWidth(const int i_totalWidth);
    int spacingMessage();
    int spacingHighlight();

public:
    // structor
    PrettyPrint() = delete;
    PrettyPrint(const std::string& i_highlight, 
                const std::string& i_message = "", 
                char i_lineChar = '=', 
                int i_totalwidth = 60); 
    ~PrettyPrint();
    void consoleOut() const;
};