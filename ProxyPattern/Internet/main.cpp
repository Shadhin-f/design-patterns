#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// Subject interface
class Internet
{
public:
    virtual void connectTo(const string &serverHost) const = 0;
    virtual ~Internet() = default;
};
// real subject
class RealInternet : public Internet
{
public:
    virtual void connectTo(const string &serverHost) const override
    {
        cout << "Connecting to " << serverHost << endl;
    }
};
// proxy
class ProxyInternet : public Internet
{
private:
    RealInternet *realInternet;
    static vector<string> bannedSites;

public:
    ProxyInternet() : realInternet(new RealInternet()) {}
    void connectTo(const string &serverHost) const override
    {
        string lowerServerHost = serverHost;
        transform(lowerServerHost.begin(), lowerServerHost.end(), lowerServerHost.begin(), ::tolower);
        if (find(bannedSites.begin(), bannedSites.end(), lowerServerHost) != bannedSites.end())
        {
            throw runtime_error("Access denied to " + serverHost);
        }
    }
};

vector<string> ProxyInternet::bannedSites = {"abc.com", "xyz.com", "banned.com"};

template <typename T>
void attemptConnection(T &internet, const string &site)
{
    try
    {
        internet.connectTo(site);
        cout << "Successfully connected to " << site << "!" << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    ProxyInternet internet;
    attemptConnection(internet, "hurrah.com");
    attemptConnection(internet, "abc.com");
}