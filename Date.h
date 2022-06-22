#pragma once
#ifndef DATE123

#define DATE123
#include <iostream>
#include <windows.h>

class Date
{
	unsigned short day;
	unsigned short month;
	short year;

public:

	Date();
	Date(unsigned short day, unsigned short month, short year);

	void set_date(unsigned short day, unsigned short month, short year);
	
	unsigned short get_day();
	unsigned short get_month();
	short get_year();

	bool operator==(const Date& other);
	bool operator!=(const Date& other);
	bool operator<(const Date& other);
	bool operator>(const Date& other);
	Date& operator=(const Date& other);
	int operator-(const Date& other);
	Date& operator+(int days);
	friend std::ostream& operator<<(std::ostream& ost, const Date& date);

};

#endif // !DATE123


