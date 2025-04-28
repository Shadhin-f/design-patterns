#pragma once
#include <string>
#include <string_view>
#include <ostream>

using namespace std;
class MenuItem
{
public:
    MenuItem() = default;
    MenuItem(string_view n, string_view d) : name(n), description(d) {}
    string description;
    MenuItem() = default;
    MenuItem(string_view n, )
}