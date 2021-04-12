#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Polygon.h"
#include "Map.h"
#include "MyWindow.h"
#include <iostream>
#include "Prog_Manager.h"

using namespace sf;
using namespace std;

int main()
{
    if (__argc == 1) exit(1);

    setlocale(LC_ALL, "Russian");
    Prog_Manager my_prog(__argv[1]);
    return 0;
}

