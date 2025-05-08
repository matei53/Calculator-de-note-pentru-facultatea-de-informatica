#ifndef ERORI_H
#define ERORI_H

#include "SFML/Graphics.hpp"

class InvalidFilePathError : public std::exception
{
	const char* mesaj;

public:
	InvalidFilePathError(const char* msg) : mesaj{ msg } { }
	const char* what() const
	{
		return mesaj;
	}
};

class InvalidInputError : public std::exception
{
	const char* mesaj;
	sf::Color culoare;

public:
	InvalidInputError(const char* msg, sf::Color clr) : mesaj{ msg }, culoare{ clr } {}
	const char* what() const
	{
		return mesaj;
	}
	sf::Color getColor() const
	{
		return culoare;
	}
};

class InvalidFileContentError : public std::exception
{
	const char* mesaj;
	unsigned int linie;

public:
	InvalidFileContentError(const char* msg, const unsigned int line) : mesaj{ msg }, linie{ line } {}
	const char* what() const
	{
		return mesaj;
	}
	unsigned int getLine() const
	{
		return linie;
	}
};

#endif