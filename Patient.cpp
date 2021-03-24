#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Patient.h"
#include "utils.h"

#include "Ticket.h"
sdds::Patient::Patient(int ticket, bool IO):m_ticket(ticket)
{
	m_name = nullptr;
	m_OHIP = 0;
	m_IO = IO;
}

sdds::Patient::~Patient()
{
	delete[] m_name;
}

bool sdds::Patient::fileIO() const
{
	return m_IO;
}

void sdds::Patient::fileIO(bool toSet)
{
	m_IO = toSet;
}

bool sdds::Patient::operator==(const char toCompare) const
{
	if (toCompare == type()) return true;
	else return false;
}

bool sdds::Patient::operator==(const Patient& toCompare) const
{
	if (fileIO() == toCompare.fileIO()) return true;
	else return false;
}

void sdds::Patient::setArrivalTime()
{
	m_ticket.resetTime();
}

sdds::Patient::operator Time() const
{
	return (Time)m_ticket;
}

int sdds::Patient::number() const
{
	return m_ticket.number();
}

std::ostream& sdds::Patient::csvWrite(std::ostream& os) const
{
	os << type() << "," << m_name << "," << m_OHIP << ",";
	m_ticket.csvWrite(os);
	return os;
}

std::istream& sdds::Patient::csvRead(std::istream& is)
{
	std::string str;
	getline(is, str, ',');
	delete[] m_name;
	m_name = new char[strlen(str.c_str()) + 1];
	strcpy(m_name, str.c_str());
	is >> m_OHIP;
	is.ignore();
	m_ticket.csvRead(is);
	return is;
}

std::ostream& sdds::Patient::write(std::ostream& os) const
{
	os << m_ticket << std::endl;
	if (strlen(m_name) > 25)
	{
		for (int i = 0; i < 25; i++)
		{
			os << m_name[i];
		}
	}
	else os << m_name;
	os << ", OHIP: " << m_OHIP;
	return os;
}

std::istream& sdds::Patient::read(std::istream& is)
{
	std::cout << "Name: ";
	std::string str;
	getline(is, str);
	delete[] m_name;
	m_name = new char[strlen(str.c_str()) + 1];
	strcpy(m_name, str.c_str());
	std::cout << "OHIP: ";
	m_OHIP = getInt(100000000, 999999999, "" , "Invalid OHIP Number, ");
	return is;
}