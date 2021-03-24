#ifndef SDDS_PATIENT_H__
#define SDDS_PATIENT_H__

#include "IOAble.h"
#include "Time.h"
#include "Ticket.h"
namespace sdds
{
	class Patient: public IOAble
	{
		char* m_name;
		int m_OHIP;
		Ticket m_ticket;
		bool m_IO;

	public:
		Patient(int ticket = 0, bool IO = false);
		virtual ~Patient();
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool toSet);
		bool operator ==(char toCompare) const;
		bool operator ==(const Patient& toCompare) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		std::ostream& csvWrite(std::ostream&) const;
		std::istream& csvRead(std::istream&);
		std::ostream& write(std::ostream&) const;
		std::istream& read(std::istream&);
		// prevention of copy and assignment
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
	};
}
#endif // !SDDS_PATIENT_H__