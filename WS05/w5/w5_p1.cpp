////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-06-12							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Book.h"
#include "Book.h" // intentional

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; ++i)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	seneca::Book library[7];
	if (argc == 2) {
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
		//       - if the file cannot be open, print a message to standard error console and
		//                exit from application with error code "AppErrors::CannotOpenFile"
		try {
			std::ifstream file(argv[1]);
			if (!file) 
			{
				throw std::runtime_error("Cannot open file");
			}
			std::string strBook{};
			size_t cnt{};
			do {
				std::getline(file, strBook);		// read one line at a time
				if (file && strBook[0] != '#')				// lines that start with "#" are considered comments and should be ignored
				{
					seneca::Book tmpBook(strBook);	// pass it to the Book constructor
					library[cnt] = tmpBook;			// store each book read into the array "library"
					++cnt;
				}
			} while (file);
		}
		catch (const std::runtime_error& e) {
			std::cerr << e.what() << std::endl;		// print a message to standard error console
			std::exit(AppErrors::CannotOpenFile);	// exit from application with error code "AppErrors::CannotOpenFile"
		}
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object

	auto fixPrice = [=](seneca::Book& b) {
		if (b.country() == "US")
		{
			b.price() = b.price() * usdToCadRate;
		}
		else if (b.country() == "UK" && b.year() >= 1990 && b.year() <= 1999)
		{
			b.price() = b.price() * gbpToCadRate;
		}
		return b;
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (size_t i = 0; i < 7; ++i)
	{
		std::cout << library[i];
	}

	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (size_t i = 0; i < 7; ++i)
	{
		fixPrice(library[i]);
	}


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (size_t i = 0; i < 7; ++i)
	{
		std::cout << library[i];
	}

	std::cout << "-----------------------------------------\n";

	return cout;
}
