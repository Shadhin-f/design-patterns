#include <iostream>
using namespace std;

class Window
{
public:
    virtual void draw() = 0;
    virtual ~Window() = default;
};

class SimpleWindow : public Window
{
public:
    void draw() override
    {
        cout << "SimpleWindow" << endl;
    }
};

class WindowDecorator : public Window
{
public:
    WindowDecorator(Window *window) : window_(window) {}
    void draw() override
    {
        window_->draw();
    }

protected:
    Window *window_;
};

class ScrollbarWindow : public WindowDecorator
{
public:
    ScrollbarWindow(Window *window) : WindowDecorator(window) {}

    void draw() override
    {
        WindowDecorator::draw();
        drawScrollbar();
    }

private:
    void drawScrollbar()
    {
        cout << "Scrollbar" << endl;
    }
};

class ColorWindow : public WindowDecorator
{
public:
    ColorWindow(Window *window) : WindowDecorator(window) {}

    void draw() override
    {
        WindowDecorator::draw();
        drawColor();
    }

private:
    void drawColor()
    {
        cout << "Colorful Window" << endl;
    }
};

int main()
{
    // cout << "Concrete Component" << endl;
    Window *simpleWindow = new SimpleWindow();
    // simpleWindow->draw();
    // cout << "\nDecorator or Wrapper Object\n";
    // Window *simpleWindow2 = new SimpleWindow();
    Window *scrollbarWindow = new ScrollbarWindow(simpleWindow);
    // scrollbarWindow->draw();
    // Window *simpleWindow3 = new SimpleWindow();
    cout << "\nDecorator or Wrapper Object 2nd time\n";
    Window *colorWindow = new ColorWindow(scrollbarWindow);
    colorWindow->draw();
}
