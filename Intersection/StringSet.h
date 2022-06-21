#pragma once

#include<iostream>
#include <unordered_set>
#include <fstream>
#include <string>
#include <algorithm>

class StringSet
{
public:
	StringSet(std::string file);
	bool contains(const std::string& element) const;
	uint64_t intersection(const StringSet& set2) const;
	uint64_t intersection(const StringSet& set2, const StringSet& set3) const;
	uint64_t uniqueElements(const StringSet& set2, const StringSet& set3) const;
	int removeAll(const std::string part);
	void add(const std::string element);
	size_t size() const;
	std::string label();
private:
	std::string m_label;
	void load(std::string & file);
	std::string clean(std::string input);
	std::unordered_set<std::string> set;
};

