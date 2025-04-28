#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Iterator Interface
class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual string next() = 0;
    virtual ~Iterator() {}
};

// Aggregate Interface
class NameCollection
{
public:
    virtual Iterator *createIterator() = 0;
    virtual void addName(const string &name) = 0;
    virtual ~NameCollection() {}
};

// Concrete Collection
class NameList : public NameCollection
{
private:
    vector<string> names;

    // Concrete Iterator
    class NameIterator : public Iterator
    {
    private:
        const vector<string> &names;
        size_t index;

    public:
        NameIterator(const vector<string> &n) : names(n), index(0) {}

        bool hasNext() override
        {
            return index < names.size();
        }

        string next() override
        {
            return hasNext() ? names[index++] : "";
        }
    };

public:
    void addName(const string &name) override
    {
        names.push_back(name);
    }

    Iterator *createIterator() override
    {
        return new NameIterator(names);
    }
};

int main()
{
    NameList myNames;
    myNames.addName("Alice");
    myNames.addName("Bob");
    myNames.addName("Charlie");

    Iterator *it = myNames.createIterator();

    cout << "Names in the list:" << endl;
    while (it->hasNext())
    {
        cout << "- " << it->next() << endl;
    }

    delete it; // Clean up memory
    return 0;
}
