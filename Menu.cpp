#include "Menu.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Blue);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(450,360));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Red);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(450,500));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    Texture background;
    background.loadFromFile("1.jpg");
    Sprite back;
    back.setTexture(background);
    window.draw(back);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::Red);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Blue);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::Red);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Blue);
	}
}

