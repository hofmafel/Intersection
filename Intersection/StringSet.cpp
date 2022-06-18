#include "StringSet.h"


StringSet::StringSet(std::string file)
{
    m_label = file;
    load(file);
}

bool StringSet::contains(const std::string& element) const
{
    return this->set.contains(element);
}


uint64_t StringSet::intersection(const StringSet& set2) const
{
    uint64_t count = 0;
    for (auto const& record : this->set)
        if (set2.contains(record))
            count++;
    return count;
}


uint64_t StringSet::intersection(const StringSet& set2, const StringSet& set3) const
{
    uint64_t count = 0;
    for (auto const& record : this->set)
        if (set2.contains(record) && set3.contains(record))
            count++;
    return count;
}


int StringSet::removeAll(const std::string part)
{
    // TODO: Fügen Sie hier Ihren Implementierungscode ein..
    return 0;
}


void StringSet::add(const std::string element)
{
    this->set.insert(element);
    
}

size_t StringSet::size() const
{
    return this->set.size();
}

std::string StringSet::label()
{
    return this->m_label;
}


void StringSet::load(std::string& file)
{
    std::string record;
    std::ifstream input(file);
    if (input.is_open())
    {
        while (std::getline(input, record))
        {
            this->add(clean(record));
        }
        input.close();
    }
    else throw std::runtime_error("Could not open file:" + file);
}

std::string StringSet::clean(std::string input)
{
   input = input.substr(input.find_first_of(',')+1,input.length()-1);
   std::transform(input.begin(), input.end(), input.begin(),[](unsigned char c) { return std::tolower(c); });
   return input;
}
