// Author: Luke Bachman (lukebachman@fullerton.edu)
// March 24, 2019
// This is a menu-based program for creating notes. Notes are stored in an array
// of Note objects. The array has a capacity of 100 elements.

#include "notebook.hpp"
#include <iostream>
#include <string>
#include <cctype>

int main() {
  char choice;
  Notebook book;
  int size = 0;
  std::string filename;
  std::cout << "Welcome to TuffyNotes!\n";
  // Keep asking user to create a note or exit
  do {
    std::cout << "[C] Create a note\n";
	std::cout << "[N] Create an encrypted note\n";
    std::cout << "[L] List notes\n";
    std::cout << "[V] View notes\n";
	std::cout << "[S] Save notes\n";
	std::cout << "[O] Load notes\n";
    std::cout << "[E] Exit\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cin.ignore();
    choice = toupper(choice);
    switch (choice) {
      case 'C':
	   book.add(create_note());
        break;
	  case 'N':
	   book.add(create_encrypted_note());
      case 'L':
	   book.list();
        break;
      case 'V':
	   book.view();
        break;
	  case 'S':
	    std::cout << "Please enter filename: ";
		getline(std::cin, filename);
	   book.save(filename);
	 	break;
	  case 'O':
	  	std::cout << "\nPlease enter filename: ";
		getline(std::cin, filename);
	   book.load(filename);
		break;
      case 'E':
        std::cout << "\nThank you for using TuffyNotes!\n";
        break;
      default:
        std::cout << "\nInvalid choice. Please try again.\n\n";
    }
  } while (choice != 'e' && choice != 'E');

  return 0;
}
