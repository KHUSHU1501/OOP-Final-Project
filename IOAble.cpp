/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Khushwant Singh Rao
Revision History
-----------------------------------------------------------
Date      Reason
2021/03/20  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "IOAble.h"

std::ostream& sdds::operator<<(std::ostream& ostr, const IOAble& A)
{
    A.write(ostr);
    return ostr;
}

std::istream& sdds::operator>>(std::istream& istr, IOAble& A)
{
    return A.read(istr);
}


