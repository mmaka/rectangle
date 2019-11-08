#include<iostream>
#include<functional>
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

int main()
{
  [out = std::ref(std::cout << "Hello ")](){ out.get() << "World\n";}();
}
