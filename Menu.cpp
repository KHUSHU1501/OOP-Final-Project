/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"

void sdds::Menu::display() const
{
	std::cout << m_text << std::endl << "0- Exit" << std::endl;
}

sdds::Menu::Menu(const char* MenuContent, int NoOfSelections)
{
	m_text = nullptr;
	m_noOfSel = 0;
	m_text = new char[strlen(MenuContent) + 1];
	strcpy(m_text, MenuContent);
	m_noOfSel = NoOfSelections;
}

sdds::Menu::~Menu()
{
	delete[] m_text;
}

int& sdds::Menu::operator>>(int& Selection)
{
	display();
	Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");
	return Selection;
}

sdds::Menu::Menu(const Menu& cpy)
{
	m_text = nullptr;
	m_noOfSel = 0;
	m_text = new char[strlen(cpy.m_text) + 1];
	strcpy(m_text, cpy.m_text);
	m_noOfSel = cpy.m_noOfSel;
}
