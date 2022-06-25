#include "Date.h"

Date::Date()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	day = st.wDay;
	month = st.wMonth;
	year = st.wYear;
}

Date::Date(unsigned short day, unsigned short month, short year)
{
	set_date(day, month, year);
}

void Date::set_date(unsigned short day, unsigned short month, short year)
{
	bool visokosnyi = false;
	if (year % 4 == 0) visokosnyi = true;

	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day < 32)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 0 && day < 31)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	else if (visokosnyi && month == 2 && day > 0 && day < 30)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	else if (!visokosnyi && month == 2 && day > 0 && day < 29)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	else throw std::exception("This is Data no exist!!!");
}

unsigned short Date::get_day()
{
	return day;
}

unsigned short Date::get_month()
{
	return month;
}

short Date::get_year()
{
	return year;
}

bool Date::operator==(const Date& other)
{
	return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date& other)
{
	return year != other.year || month != other.month || day != other.day;
}

bool Date::operator<(const Date& other)
{
	if (year < other.year) return true;
	else if (year > other.year) return false;

	if (month < other.month) return true;
	else if (month > other.month) return false;

	if (day < other.day) return true;
	return false;
}

bool Date::operator>(const Date& other)
{
	if (year > other.year) return true;
	else if (year < other.year) return false;

	if (month > other.month) return true;
	else if (month < other.month) return false;

	if (day > other.day) return true;
	return false;
}

Date& Date::operator=(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
	return *this;
}

int Date::operator-(const Date& other)
{
	if (*this == other) return 0;

	else if (*this > other)
	{
		if (month == other.month && year == other.year) return day - other.day;

		else {
			int sum = day;
			int d = day;
			int m = month;
			int y = year;

			if (m == 1) {
				m = 12;
				y--;
			}
			else m--;

			bool visokosnyi;

			while (m != other.month || y != other.year)
			{
				if (y % 4 == 0) visokosnyi = true;
				else visokosnyi = false;

				if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
					sum += 31;
				else if (m == 4 || m == 6 || m == 9 || m == 11)
					sum += 30;
				else if (visokosnyi && m == 2)
					sum += 29;
				else if (!visokosnyi && m == 2)
					sum += 28;

				if (m == 1) {
					m = 12;
					y--;
				}
				else m--;
			}

			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				sum += 31 - other.day;
			else if (m == 4 || m == 6 || m == 9 || m == 11)
				sum += 30 - other.day;
			else if (visokosnyi && m == 2)
				sum += 29 - other.day;
			else if (!visokosnyi && m == 2)
				sum += 28 - other.day;

			return sum;
		}
	}

	else if (*this < other)
	{
		if (month == other.month && year == other.year) return other.day - day;

		else {
			int sum = other.day;
			int d = other.day;
			int m = other.month;
			int y = other.year;

			if (m == 1) {
				m = 12;
				y--;
			}
			else m--;

			bool visokosnyi;

			while (m != month || y != year)
			{
				if (y % 4 == 0) visokosnyi = true;
				else visokosnyi = false;

				if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
					sum += 31;
				else if (m == 4 || m == 6 || m == 9 || m == 11)
					sum += 30;
				else if (visokosnyi && m == 2)
					sum += 29;
				else if (!visokosnyi && m == 2)
					sum += 28;

				if (m == 1) {
					m = 12;
					y--;
				}
				else m--;
			}

			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				sum += 31 - day;
			else if (m == 4 || m == 6 || m == 9 || m == 11)
				sum += 30 - day;
			else if (visokosnyi && m == 2)
				sum += 29 - day;
			else if (!visokosnyi && m == 2)
				sum += 28 - day;

			return sum;
		}
	}
}

Date Date::operator-(unsigned int days)
{
	if (days == 0) return *this;

	Date clone = *this;
	bool visokosnyi;

	while (days != 0)
	{
		if (clone.year % 4 == 0) visokosnyi = true;
		else visokosnyi = false;

		if ((clone.month == 1 || clone.month - 1 == 1 || clone.month - 1 == 3 || clone.month - 1 == 5 || clone.month - 1 == 7 ||
			clone.month - 1 == 8 || clone.month - 1 == 10 || clone.month - 1 == 12) && clone.day == 1)
		{
			clone.day = 31;
			if (clone.month == 1)
			{
				clone.month = 12;
				clone.year--;
			}
			else clone.month--;
		}

		else if ((clone.month - 1 == 4 || clone.month - 1 == 6 || clone.month - 1 == 9 || clone.month - 1 == 11) && clone.day == 1)
		{
			clone.day = 30;
			clone.month--;
		}

		else if (visokosnyi && clone.month - 1 == 2 && clone.day == 1)
		{
			clone.day = 29;
			clone.month--;
		}

		else if (!visokosnyi && clone.month - 1 == 2 && clone.day == 1)
		{
			clone.day = 28;
			clone.month--;
		}

		else clone.day--;

		days--;
	}

	return clone;
}

Date Date::operator+(unsigned int days)
{
	if (days == 0) return *this;
	
		Date clone = *this;
		bool visokosnyi;
		
		while (days != 0)
		{
			if (clone.year % 4 == 0) visokosnyi = true;
			else visokosnyi = false;

			if ((clone.month == 1 || clone.month == 3 || clone.month == 5 || clone.month == 7 || 
				clone.month == 8 || clone.month == 10 || clone.month == 12) && clone.day == 31)
			{
				clone.day = 1;
				if (clone.month == 12)
				{
					clone.month = 1;
					clone.year++;
				}
				else clone.month++;
			}

			else if ((clone.month == 4 || clone.month == 6 || clone.month == 9 || clone.month == 11) && clone.day == 30)
			{
				clone.day = 1;
				clone.month++;
			}

			else if (visokosnyi && clone.month == 2 && clone.day == 29)
			{
				clone.day = 1;
				clone.month++;
			}

			else if (!visokosnyi && clone.month == 2 && clone.day == 28)
			{
				clone.day = 1;
				clone.month++;
			}

			else clone.day++;

			days--;
		}

		return clone;

}

std::ostream& operator<<(std::ostream& ost, const Date& date)
{
	ost << date.day << "." << date.month << "." << date.year << ".";
	return ost;
}

std::istream& operator>>(std::istream& ist, Date& date)
{
	ist >> date.day >> date.month >> date.year;
	date.set_date(date.day, date.month, date.year);
	return ist;
}
