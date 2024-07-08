#pragma once

#include <string>
#include <iostream>


/*
contains a string with the header info
*/
class Header
{
private:
    // member var
    std::string m_header;

public:

    //'structors
    Header();
    Header(const std::string& i_header);
    ~Header() = default;

    //getter:

    void print() const;
    const std::string& getHeader() const;
    bool isEmpty() const;

    //setter:

    void append(const std::string& i_newComment);
    void clear();
};
