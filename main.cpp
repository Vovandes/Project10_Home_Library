#include "HomeLibrary.hpp"

int main() {

	HomeLibrary h;
	HomeLibrary::Book b1{ "Game of trones", "S Martin", 2001 };
	HomeLibrary::Book b2{ "Concurrency with Modern C++", "Rainer Grimm", 2020 };
	HomeLibrary::Book b3{ "C++ Tasks", "#SimpleCode", 2016 };
	HomeLibrary::Book b4{ "C++ Crash Course", "Josh Lospinoso", 2019 };
	HomeLibrary::Book b5{ "MODERN OPERATING SYSTEMS", "Andrew S. Tanenbaum", 2015 };

	h.Add_Book(b1);
	h.Add_Book(b2);
	h.Add_Book(b3);
	h.Add_Book(b4);
	h.Add_Book(b5);

	std::string find{ "C++ Tasks" };

	h.Find_by_name(find);

	h.PrintLibrary();
	//h.Find_by_name(find);

	size_t index;
	std::cout << "Enter index for delete[]: ";
	std::cin >> index;

	h.Delete_Book(index);
	h.PrintLibrary();

	//std::cout << std::endl;

	return EXIT_SUCCESS;
}