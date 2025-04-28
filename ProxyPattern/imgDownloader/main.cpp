#include <iostream>
using namespace std;

// Interface

class Image
{
public:
    virtual void display() const = 0;
    virtual ~Image() = default;
};

// Actual or real subject
class RealImage : public Image
{
private:
    string fileName;
    void load() const
    {
        cout << "loading iage: " << fileName << endl;
    }

public:
    RealImage(const string &filename) : fileName(filename)
    {
        load();
    }
    void display() const override
    {
        cout << "Displaying image: " << fileName << endl;
    }
};
// proxy subject
class ProxyImage : public Image
{
public:
    string fileName;
    mutable RealImage *realImage;

public:
    ProxyImage(const string &fileName) : fileName(fileName), realImage(nullptr) {}
    ~ProxyImage()
    {
        delete realImage;
    }
    void display() const override
    {
        if (realImage == nullptr)
        {
            realImage = new RealImage(fileName);
        }
        realImage->display();
    }
};

int main()
{
    ProxyImage proxy("dogs.png");
    proxy.display();
    return 0;
}