#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <random>
#include <functional>

/*
	10. Описать класс «домашняя библиотека». Предусмотреть возможность работы с произвольным числом книг,
	поиска книги по какому-либо признаку (например, по автору или по году издания), добавления книг в библиотеку,
	удаления книг из нее, сортировки книг по разным полям.
*/

class HomeLibrary {
public:
	struct Book {
		Book(std::string&& n, std::string&& a, size_t year)
			: m_id{ 0 }
			, m_name{ std::move(n) }
			, m_author{ std::move(a) }
			, m_year{ year } {}
		size_t m_id{};
		std::string m_name;
		std::string m_author;
		size_t m_year;
	};
	HomeLibrary() = default;

	void Add_Book(Book& book);
	void Delete_Book(size_t index);

	void Find_by(const std::function<bool(const Book&)> predicate);

	void Find_by_name(const std::string_view& name);
	void Find_by_author(const std::string_view& author);
	void Find_by_year(const size_t year);

	void Sort_by_ID();
	void Sort_by_name();
	void Sort_by_author();
	void Sort_by_year();

	void PrintLibrary() const;

	const std::vector<Book>& get_Library() const { return library_; }

	friend std::ostream& operator<<(std::ostream& os, const HomeLibrary::Book& obj);
private:
	std::vector<Book> library_;
	std::vector<size_t> id_;
	size_t random();
};

inline bool operator ==(const HomeLibrary::Book& book1, const HomeLibrary::Book& book2) {
	return (book1.m_name == book2.m_name && book1.m_author == book2.m_author && book1.m_year == book2.m_year);
}
