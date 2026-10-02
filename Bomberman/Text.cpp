#include "Text.h"
#include <cctype>

std::string Text::toUpperCase(const std::string& text)
{
	std::string upperText;
	for (char c : text)
	{
		upperText += std::toupper(static_cast<unsigned char>(c));
	}
	return upperText;
}
