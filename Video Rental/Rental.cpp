#pragma once
#include "Movie.cpp";

class Rental
{
public:
	Rental(Movie movie, int days_rented)
		: movie(movie),
		daysRented(days_rented)
	{
	}

	int getDays()
	{
		return daysRented;
	}

	int getAmount()
	{
		double thisAmount = 0;

		if (movie.getPriceCode() == Movie::REGULAR)
		{
			if (getDays() <= 2) {
				thisAmount = 2;
			}
			else
			{
				thisAmount = getDays() * CHILDRENS_DISCOUNT_AMOUNT;
			}
		}
		else if (movie.getPriceCode() == Movie::NEW_RELEASE)
		{
			thisAmount = getDays() * NEW_RELEASE_AMOUNT;
		}
		else if (movie.getPriceCode() == Movie::CHILDRENS)
		{
			if (getDays() > 3)
				thisAmount = getDays() * 1.5;
			else
			{
				thisAmount = 1.5;
			}
		}

		return thisAmount;
	}

	Movie getMovie()
	{
		return movie;
	}

private:
	double CHILDRENS_AMOUNT = 2;
	double CHILDRENS_DISCOUNT_AMOUNT = 1.5;

	double NEW_RELEASE_AMOUNT = 3;

	double REGULAR_AMOUNT = 1.5;

	Movie movie;
	int daysRented;
};