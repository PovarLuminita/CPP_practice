#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

/**
	Reads a vector of books from a text file.
	Note: the text file shall contain lines of text in pairs for the book name and authors
	E.g.
		BOOK 1
		AUTHOR 1
		BOOK 2
		AUTHOR 2
		BOOK 3
		AUTHOR 1, AUTHOR 2, AUTHOR 3
	@param file_name The name of the file to read from (must include path).
	@return Vector of books.
*/
std::vector<Book> readBooksFromTextFile(const std::string& file_name)
{
	std::vector<Book> results;
	// TODO: BEGIN read the file -------------------------------------
	CSimpleIniA ini;
	ini.LoadFile(file_name.c_str()); //converteste din string in char

	const char* count_s = ini.GetValue("books", "count", """");

	int count = stoi(count_s);

	int i;
	for (i = 1; i <= count; i++)
	{
		stringstream ss;
		ss << "book" << i;

		string s_name(ss.str()); //copiez ce am in stream

		const char* carte = ini.GetValue(s_name.c_str(), "name", """");
		const char* autori = ini.GetValue(s_name.c_str(), "autori", """");

		//carte de tip book
		Book book1 = Book(carte, autori);
		results.push_back(book1);

	}


	// E.g. Book myBook;
	//		...
	//		results.emplace_back(myBook);

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