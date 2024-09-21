
//Assignment 3 - Library Book Manager 

#include <iostream>
#include <conio.h>

using namespace std;

struct LibraryBook
{
	string title;
	string author;
	int yearPublished;
	int numPages;
};

void PrintBook(int i, const LibraryBook& book)
{
	cout << (i + 1) << ". " << book.title << "\n";
}

int main()
{
	//List of the books
	const int Num_Books = 4;
	LibraryBook libraryBooks[Num_Books] = 
	{
		{"The Hobbit", "JRR Tolkien", 1937, 310 },
		{"War and Peace", "Leo Tolstoy", 1869, 1225 },
		{"The Wheel of Time", "Robert Jordan", 1990, 814 },
		{"The Covenant of Water", "Abraham Verghese", 2024, 400 },
	};

	//Display the books
	for (int i = 0; i < Num_Books; i++)
	{
		cout << (i + 1) << ". " << libraryBooks[i].title << "\n"
		<< "Author: " << libraryBooks[i].author << "\n"
		<< "Year Published: " << libraryBooks[i].yearPublished << "\n"
		<< "Number of pages: " << libraryBooks[i].numPages << "\n\n";
	}
	
	//get the user input 
	int bookId; 
	bool validInput = false;

	while (!validInput)
	{	
		cout << "Enter the ID of the book you would like to update (1-4): ";
		cin >> bookId;

		if (bookId < 1 || bookId > Num_Books)
		{
			cout << "Invalid book ID. Please try again" << "\n";
		}
		else
		{
			validInput = true;
		}
	}

	//Allow the user to update the book 
	if (bookId > 0 && bookId <= Num_Books)
	{
		PrintBook(bookId - 1, libraryBooks[bookId - 1]);

		string updateAuthor;
		int updateYear;
		int updatePages;

		//New author enter by user
		cout << "Enter the Author (" << libraryBooks[bookId - 1].author << "): ";
		cin >> updateAuthor;
		if (updateAuthor.empty())
		{
			updateAuthor = libraryBooks[bookId - 1].author;
		}
		
		//New year enter by user 
		cout << "Enter the Year Published (" << libraryBooks[bookId - 1].yearPublished << "): ";
		cin >> updateYear;
		if (updateYear <= 0)
		{
			updateYear = libraryBooks[bookId - 1].yearPublished;
		}

		//New pages enter by user 
		cout << "Enter the Number of Pages (" << libraryBooks[bookId - 1].numPages << "): ";
		cin >> updatePages;
		if (updatePages <= 0)
		{
			updatePages = libraryBooks[bookId - 1].numPages;
		}

		//Saving the changes made by the user 
		char save;
		cout << "Save these changes? (Y/N): ";
		cin >> save;

		cout << endl;

		if (save == 'Y' || save == 'y')
		{
			libraryBooks[bookId - 1].author = updateAuthor;
			libraryBooks[bookId - 1].yearPublished = updateYear;
			libraryBooks[bookId - 1].numPages = updatePages;

			//If yes - display the updated information
			cout << bookId << ". " << libraryBooks[bookId - 1].title << "\n"
				<< "Author: " << updateAuthor << "\n"
				<< "Year Published: " << updateYear << "\n"
				<< "Number of Pages: " << updatePages << "\n";
		}
		else if (save == 'N' || save == 'n')
		{
			cout << "Changes will not be saved.";
		}
	}

	(void)_getch();
	return 0;
}