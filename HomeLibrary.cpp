#include "HomeLibrary.hpp"

void HomeLibrary::Add_Book(Book& book) {
	if (std::find(library_.cbegin(), library_.cend(), book) != library_.cend()) {
		book.~Book();
		std::cout << "This book is in your library" << std::endl;
		return;
	}
	do {
		book.m_id = random();
	} while (std::find(id_.cbegin(), id_.cend(), book.m_id) != id_.cend());
	id_.emplace_back(book.m_id);
	library_.emplace_back(std::move(book));
}

void HomeLibrary::Delete_Book(size_t index) {
	if (auto iter = library_.cbegin() + index; iter != library_.end()) {
		library_.erase(iter);
	}
	else {
		std::cout << "Incorrect index!" << std::endl;
	}
}

void HomeLibrary::Find_by(const std::function<bool(const HomeLibrary::Book&)> predicate) {
	for (auto iter = library_.cbegin(); iter != library_.cend(); ++iter) {
		if (predicate(*iter)) {
			std::cout << *iter << std::endl;
		}
	}
}

void HomeLibrary::Find_by_name(const std::string_view& name) {
	Find_by([&name](const HomeLibrary::Book& a) { return a.m_name == name; });
}

void HomeLibrary::Find_by_author(const std::string_view& author) {
	Find_by([&author](const HomeLibrary::Book& a) { return a.m_author == author; });
}

void HomeLibrary::Find_by_year(const size_t year) {
	Find_by([year](const HomeLibrary::Book& a) { return a.m_year == year; });
}

void HomeLibrary::Sort_by_ID() {
	std::sort(library_.begin(), library_.end(),
		[](const HomeLibrary::Book& bk1, const HomeLibrary::Book& bk2) {return bk1.m_id < bk2.m_id; });
}

void HomeLibrary::Sort_by_name() {
	std::sort(library_.begin(), library_.end(),
		[](const HomeLibrary::Book& bk1, const HomeLibrary::Book& bk2) {return bk1.m_name < bk2.m_name; });
}

void HomeLibrary::Sort_by_author() {
	std::sort(library_.begin(), library_.end(),
		[](const HomeLibrary::Book& bk1, const HomeLibrary::Book& bk2) {return bk1.m_author < bk2.m_author; });
}

void HomeLibrary::Sort_by_year() {
	std::sort(library_.begin(), library_.end(),
		[](const HomeLibrary::Book& bk1, const HomeLibrary::Book& bk2) {return bk1.m_year < bk2.m_year; });
}

void HomeLibrary::PrintLibrary() const {
	size_t count{ 0 };
	std::cout << "Author:\t\t\tName:\t\t\tYear:\n";
	for (const auto& elem : library_) {
		std::cout << count++ << "   " << elem << std::endl;
	}
}

size_t HomeLibrary::random() {
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<size_t> dist(1, 1000);

	return dist(gen);
}

std::ostream& operator<<(std::ostream& os, const HomeLibrary::Book& obj) {
	obj.m_author.size() > 20 ? os << obj.m_author << "\t" : os << obj.m_author << "\t\t";
	obj.m_name.size() > 20 ? os << obj.m_name << "\t" : os << obj.m_name << "\t\t";
	os << obj.m_year;
	return os;
}
