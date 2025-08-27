#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& oth) : AForm(oth), target(oth.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &oth)
{
	if (this != &oth)
		target = oth.target;
	std::cout << "ShrubberyCreationForm copy assignment called!" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return target;
}

void ShrubberyCreationForm::executeFormAction(void) const
{
	std::string filename = this->target; // Stores target in filename.
	filename.append("_shrubbery"); // Creates a filename in format <target>_shrubbery.
	std::ofstream outfile(filename.c_str()); // Converts filename to const char* format, and opens the file.

	if (!outfile)
		throw std::runtime_error("Error opening file!");

	outfile << "      /\\\n"; // Writes to the outfile.
	outfile << "     /**\\\n";
	outfile << "    /****\\\n";
	outfile << "   /******\\\n";
	outfile << "  /********\\\n";
	outfile << " /**********\\\n";
	outfile << "/************\\\n";
	outfile << "      ||\n";
	outfile << "      ||\n";

	outfile.close(); // Closes the outfile.
}
