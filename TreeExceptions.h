#include <exception>
#include <string>

using namespace std;

class EmptyTreeException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The tree is empty. Items cannot be found or removed from an empty tree";
    }
};

class ItemNotFoundException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The item you are looking for could not be found in the list";
    }
};

class DuplicateItemException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The item you are inserting already exists";
    }
};