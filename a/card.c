#include <stdio.h>
#include <stdlib.h>

void validatecard(long card);
int digits(long card);
void invalid(void);
long sumbytwo(long card, int number);
long sumbyone(long card, int number);
void brand(long card);

int main(int argc, char *argv[])
{
	if ( argc == 2 )
	{
		printf("Validating card %s\n", argv[1]);
		long cardnumber = atol(argv[1]);
		validatecard(cardnumber);
	}
	else
	{
		printf("Usage:\n%s <card_number>\n", argv[0]);
	}
}

void validatecard(long card)
{
	// printf("Parameter: %li\n", card);
	// printf("Digits: %li\n", digits(card));
	int cardlength = digits(card);
	long tot = sumbytwo(card, cardlength) + sumbyone(card, cardlength);
	if (tot % 10 == 0)
	{
		// printf("May be valid\n");
		brand(card);
	}
	else
	{
		invalid();
	}
}

int digits(long card)
{
	int number = 0;
	for (int i = 1; card >= 1; i++)
	{
		card /= 10;
		number = i;
	}
	if ( number == 13 || number == 16 || number == 15)
	{
		return number;
	}
	else
	{
		invalid();
	}
}

void invalid(void)
{
	printf("INVALID\n");
	exit(1);
}

long sumbytwo(long card, int number)
{
	long res = 0;
	for (long i = 10, j = 0; j < number / 2; i * 100, j++)
	{
		long par = (card / i % 10) * 2;
		if (par > 9)
		{
			par = par % 10 + 1;
		}
		res += par;
	}
	return res;
}

long sumbyone(long card, int number)
{
	long res = 0;
	for (long i = 10, j = 0; j < number / 2; i * 100, j++)
	{
		res += card / i % 10;
	}
	return res;
}

void brand(long card)
{
	if (card >= 5100000000000000 && card <= 5599999999999999)
	{
		printf("MASTERCARD\n");
		exit(0);
	}
	else if ((card >= 340000000000000 && card <= 349999999999999) || (card >= 370000000000000 && card <= 379999999999999))
	{
		printf("AMEX\n");
		exit(0);
	} else if ((card >= 4000000000000 && card <= 4999999999999) || (card >= 4000000000000000 && card <= 4999999999999999))
	{
		printf("VISA\n");
		exit(0);
	}
	else
	{
		invalid();
	}
}
