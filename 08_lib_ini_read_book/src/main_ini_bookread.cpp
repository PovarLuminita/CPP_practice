// Includes

// C++ system headers
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// 3rd party libs headers
#include <SimpleIni.h>


using namespace std;
/**
	Define a simple book.
*/
class Book
{
public:
	std::string name;
	std::string authors;

	Book(string nume, string autor) //constructor
	{
		name = nume;
		authors = autor;
	}

	void print()
	{
		std::cout << this->name << std::endl;
		std::cout << "\t(by " << this->authors << ")" << std::endl;
	}
};


std::vector<Book> readBooksFromIniFile(const std::string& file_name)
{
	std::vector<Book> results;
	// TODO: BEGIN read the file -------------------------------------

	CSimpleIniA ini;
	ini.LoadFile(file_name.c_str()); //converteste din string in char

	// Get the number of books
	const char* count_str = ini.GetValue("books", "count", ""); 
	int count = std::stoi(count_str);                                                

	for(int i = 1; i <= count; i++)
	{
		stringstream ss;
		ss << "book" << i;
		std::string section_name(ss.str());

		const char* carte = ini.GetValue(section_name.c_str(), "name", "");
		const char* autor = ini.GetValue(section_name.c_str(), "author", "");

		Book book = Book(carte, autor);
	}


	// TODO: END read file and add to results vector ------------------
	return results;
}

int main()
{
	// Read a collection of books from an INI file.
	// Using the SimpleINI C++ Lib: https://github.com/brofield/simpleini

	// Read the data
	std::string input_data(".. / .. / data / ermahgerd_berks.ini");
	std::cout << "Reading the data from " << input_data << std::endl;
	std::vector<Book> books_from_file = readBooksFromIniFile(input_data);

	// Print the data
	std::cout << "Here are all the books found in the data file..." << std::endl;
	for (auto book : books_from_file)
	{
		book.print();
	}

	return 0;
}