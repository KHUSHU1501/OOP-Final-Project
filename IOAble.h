/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
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

#ifndef SDDS_IOABLE_H__
#define SDDS_IOABLE_H__

#include<iostream>
namespace sdds{
	class IOAble
	{
	public:
		virtual std::ostream& csvWrite(std::ostream&) const = 0;
		virtual std::istream& csvRead(std::istream&)  = 0;
		virtual std::ostream& write(std::ostream&) const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual ~IOAble()
		{
		};
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& A);
	std::istream& operator>>(std::istream& istr, IOAble& A);
}
#endif