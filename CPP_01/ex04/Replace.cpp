#include "Replace.hpp"

std::string ft_replace(std::string &Line, const std::string &S1, const std::string &S2)
{
	std::string NewLine; // Will be used to store the new replacement string.
	size_t Pos = 0; // Will be used to keep track of where <S1> occurs in <Line>.
	size_t PrevPos = 0; // Will be used to keep track of where <S1> has ended, to append after each occurence of <S1>.

	if (S1.empty())
	{
		std::cerr << "Error: The first string can not be empty, as this is the string getting replaced." << std::endl;
		return (Line);
	}
	while ((Pos = Line.find(S1, PrevPos)) != std::string::npos) // Sets the Position at the beginning of the first occurence of S1.
	{
		NewLine.append(Line.substr(PrevPos, Pos - PrevPos)); // Append from the previous Position, up until the first occurence of S1 (right before S1 starts).
		NewLine.append(S2); // Append S2, which is now replacing S1.
		PrevPos = Pos + S1.length(); // Previous Position is getting updated to after S1. 
	}
	NewLine.append(Line.substr(PrevPos)); // Append the rest of the string after the last occurrence of S1.
	return (NewLine);
}
