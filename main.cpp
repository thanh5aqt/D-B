#include "SFML/Graphics.hpp"
#include "Menu.hpp"
#include "Gameboard.hpp"
#include <bits/stdc++.h>

using namespace sf;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
struct POSITION{
    int x, y;
};
int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 724), "DOTS AND BOXES");
    Texture background;
    background.loadFromFile("1.jpg");
    Sprite back;
    back.setTexture(background);

    Texture x_image;
    x_image.loadFromFile("x.png");
    Sprite x_sprite(x_image);

    Texture o_image;
    o_image.loadFromFile("o.png");
    Sprite o_sprite(o_image);
    int y = 330;
    int x = 270;
    POSITION dot[5][6];
    for(int i = 0; i < 5; ++i){
        x = 270;
        for(int j = 0; j < 6; ++j){
            dot[i][j].x = x;
            dot[i][j].y = y;
            x += 80;
        }
        y += 80;
    }

    y = 333;
    x = 276;
    POSITION line_h[5][5];
    for(int i = 0; i < 5; ++i){
        x = 276;
        for(int j = 0; j < 5; ++j){
            line_h[i][j].x = x;
            line_h[i][j].y = y;
            x += 80;
        }
        y += 80;
    }
    bool b_line_h[5][5] = {0};

    y = 336;
    x = 272;
    POSITION line_v[4][6];
    for(int i = 0; i < 4; ++i){
        x = 272;
        for(int j = 0; j < 6; ++j){
            line_v[i][j].x = x;
            line_v[i][j].y = y;
            x += 80;
        }
        y += 80;
    }
    bool b_line_v[4][6] = {0};

    y = 332;
    x = 272;
    POSITION box[4][5];
    for(int i = 0; i < 4; ++i){
        x = 272;
        for(int j = 0; j < 5; ++j){
            box[i][j].x = x;
            box[i][j].y = y;
            x += 80;
        }
        y += 80;
    }
    bool b_box[4][5] = {0};
    bool isPlayer1Turn = true;
    int box_turn[4][5] = {0};
    int count1 = 0, count2 = 0;
    int m = -1, n = -1;
    int m2 = -1, n2 = -1;
    Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
            case sf::Event::MouseMoved:
			    if(event.mouseMove.x>=450&&event.mouseMove.x<=5300)
                    {
                        if(event.mouseMove.y>=360&&event.mouseMove.y<=380)
                            menu.MoveUp();
                        if(event.mouseMove.y>=500&&event.mouseMove.y<=520)
                            menu.MoveDown();
                    }
                break;
            case sf::Event::MouseButtonPressed:
			    if(event.mouseButton.x>=450&&event.mouseButton.x<=5300)
                    {
                        if(event.mouseButton.y>=360&&event.mouseButton.y<=380)
                            {
                                while (window.isOpen()){
                                    Event event;
                                    while (window.pollEvent(event)){
                                        if (event.type == Event::Closed){
                                            window.close();
                                        }

                                        window.clear();
                                        window.draw(back);
                                        bool hasEvent = false;

                                        if (event.type == Event::MouseMoved){
                                            //Drawing horizontal lines
                                            if (event.mouseMove.y >= 323 && event.mouseMove.y <= 343){
                                                if (event.mouseMove.x >= 286 && event.mouseMove.x <= 340){
                                                    m = 0;
                                                    n = 0;
                                                }
                                                else if (event.mouseMove.x >= 366 && event.mouseMove.x <= 420){
                                                    m = 0;
                                                    n = 1;
                                                }
                                                else if (event.mouseMove.x >= 446 && event.mouseMove.x <= 500){
                                                    m = 0;
                                                    n = 2;
                                                }
                                                else if (event.mouseMove.x >= 526 && event.mouseMove.x <= 580){
                                                    m = 0;
                                                    n = 3;
                                                }
                                                else if (event.mouseMove.x >= 606 && event.mouseMove.x <= 660){
                                                    m = 0;
                                                    n = 4;
                                                }
                                            }

                                            else if (event.mouseMove.y >= 403 && event.mouseMove.y <= 423){
                                                if (event.mouseMove.x >= 286 && event.mouseMove.x <= 340){
                                                    m = 1;
                                                    n = 0;
                                                }
                                                else if (event.mouseMove.x >= 366 && event.mouseMove.x <= 420){
                                                    m = 1;
                                                    n = 1;
                                                }
                                                else if (event.mouseMove.x >= 446 && event.mouseMove.x <= 500){
                                                    m = 1;
                                                    n = 2;
                                                }
                                                else if (event.mouseMove.x >= 526 && event.mouseMove.x <= 580){
                                                    m = 1;
                                                    n = 3;
                                                }
                                                else if (event.mouseMove.x >= 606 && event.mouseMove.x <= 660){
                                                    m = 1;
                                                    n = 4;
                                                }
                                            }

                                            else if (event.mouseMove.y >= 483 && event.mouseMove.y <= 503){
                                                if (event.mouseMove.x >= 286 && event.mouseMove.x <= 340){
                                                    m = 2;
                                                    n = 0;
                                                }
                                                else if (event.mouseMove.x >= 366 && event.mouseMove.x <= 420){
                                                    m = 2;
                                                    n = 1;
                                                }
                                                else if (event.mouseMove.x >= 446 && event.mouseMove.x <= 500){
                                                    m = 2;
                                                    n = 2;
                                                }
                                                else if (event.mouseMove.x >= 526 && event.mouseMove.x <= 580){
                                                    m = 2;
                                                    n = 3;
                                                }
                                                else if (event.mouseMove.x >= 606 && event.mouseMove.x <= 660){
                                                    m = 2;
                                                    n = 4;
                                                }
                                            }

                                            else if (event.mouseMove.y >= 563 && event.mouseMove.y <= 583){
                                                if (event.mouseMove.x >= 286 && event.mouseMove.x <= 340){
                                                    m = 3;
                                                    n = 0;
                                                }
                                                else if (event.mouseMove.x >= 366 && event.mouseMove.x <= 420){
                                                    m = 3;
                                                    n = 1;
                                                }
                                                else if (event.mouseMove.x >= 446 && event.mouseMove.x <= 500){
                                                    m = 3;
                                                    n = 2;
                                                }
                                                else if (event.mouseMove.x >= 526 && event.mouseMove.x <= 580){
                                                    m = 3;
                                                    n = 3;
                                                }
                                                else if (event.mouseMove.x >= 606 && event.mouseMove.x <= 660){
                                                    m = 3;
                                                    n = 4;
                                                }
                                            }

                                            else if (event.mouseMove.y >= 643 && event.mouseMove.y <= 663){
                                                if (event.mouseMove.x >= 286 && event.mouseMove.x <= 340){
                                                    m = 4;
                                                    n = 0;
                                                }
                                                else if (event.mouseMove.x >= 366 && event.mouseMove.x <= 420){
                                                    m = 4;
                                                    n = 1;
                                                }
                                                else if (event.mouseMove.x >= 446 && event.mouseMove.x <= 500){
                                                    m = 4;
                                                    n = 2;
                                                }
                                                else if (event.mouseMove.x >= 526 && event.mouseMove.x <= 580){
                                                    m = 4;
                                                    n = 3;
                                                }
                                                else if (event.mouseMove.x >= 606 && event.mouseMove.x <= 660){
                                                    m = 4;
                                                    n = 4;
                                                }
                                            }

                                            else{
                                                m = -1;
                                                n = -1;
                                            }

                                            //Drawing vertical lines
                                            if (event.mouseMove.x >= 262 && event.mouseMove.x <= 282){
                                                if (event.mouseMove.y >= 346 && event.mouseMove.y <= 400){
                                                    m2 = 0;
                                                    n2 = 0;
                                                }
                                                else if (event.mouseMove.y >= 426 && event.mouseMove.y <= 480){
                                                    m2 = 1;
                                                    n2 = 0;
                                                }
                                                else if (event.mouseMove.y >= 506 && event.mouseMove.y <= 560){
                                                    m2 = 2;
                                                    n2 = 0;
                                                }
                                                else if (event.mouseMove.y >= 589 && event.mouseMove.y <= 640){
                                                    m2 = 3;
                                                    n2 = 0;
                                                }
                                            }

                                            else if (event.mouseMove.x >= 342 && event.mouseMove.x <= 362){
                                                if (event.mouseMove.y >= 346 && event.mouseMove.y <= 400){
                                                    m2 = 0;
                                                    n2 = 1;
                                                }
                                                else if (event.mouseMove.y >= 426 && event.mouseMove.y <= 480){
                                                    m2 = 1;
                                                    n2 = 1;
                                                }
                                                else if (event.mouseMove.y >= 506 && event.mouseMove.y <= 560){
                                                    m2 = 2;
                                                    n2 = 1;
                                                }
                                                else if (event.mouseMove.y >= 589 && event.mouseMove.y <= 640){
                                                    m2 = 3;
                                                    n2 = 1;
                                                }
                                            }

                                            else if (event.mouseMove.x >= 422 && event.mouseMove.x <= 442){
                                                if (event.mouseMove.y >= 346 && event.mouseMove.y <= 400){
                                                    m2 = 0;
                                                    n2 = 2;
                                                }
                                                else if (event.mouseMove.y >= 426 && event.mouseMove.y <= 480){
                                                    m2 = 1;
                                                    n2 = 2;
                                                }
                                                else if (event.mouseMove.y >= 506 && event.mouseMove.y <= 560){
                                                    m2 = 2;
                                                    n2 = 2;
                                                }
                                                else if (event.mouseMove.y >= 589 && event.mouseMove.y <= 640){
                                                    m2 = 3;
                                                    n2 = 2;
                                                }
                                            }

                                            else if (event.mouseMove.x >= 502 && event.mouseMove.x <= 522){
                                                if (event.mouseMove.y >= 346 && event.mouseMove.y <= 400){
                                                    m2 = 0;
                                                    n2 = 3;
                                                }
                                                else if (event.mouseMove.y >= 426 && event.mouseMove.y <= 480){
                                                    m2 = 1;
                                                    n2 = 3;
                                                }
                                                else if (event.mouseMove.y >= 506 && event.mouseMove.y <= 560){
                                                    m2 = 2;
                                                    n2 = 3;
                                                }
                                                else if (event.mouseMove.y >= 589 && event.mouseMove.y <= 640){
                                                    m2 = 3;
                                                    n2 = 3;
                                                }
                                            }

                                            else if (event.mouseMove.x >= 582 && event.mouseMove.x <= 602){
                                                if (event.mouseMove.y >= 346 && event.mouseMove.y <= 400){
                                                    m2 = 0;
                                                    n2 = 4;
                                                }
                                                else if (event.mouseMove.y >= 426 && event.mouseMove.y <= 480){
                                                    m2 = 1;
                                                    n2 = 4;
                                                }
                                                else if (event.mouseMove.y >= 506 && event.mouseMove.y <= 560){
                                                    m2 = 2;
                                                    n2 = 4;
                                                }
                                                else if (event.mouseMove.y >= 589 && event.mouseMove.y <= 640){
                                                    m2 = 3;
                                                    n2 = 4;
                                                }
                                            }

                                            else if (event.mouseMove.x >= 662 && event.mouseMove.x <= 682){
                                                if (event.mouseMove.y >= 346 && event.mouseMove.y <= 400){
                                                    m2 = 0;
                                                    n2 = 5;
                                                }
                                                else if (event.mouseMove.y >= 426 && event.mouseMove.y <= 480){
                                                    m2 = 1;
                                                    n2 = 5;
                                                }
                                                else if (event.mouseMove.y >= 506 && event.mouseMove.y <= 560){
                                                    m2 = 2;
                                                    n2 = 5;
                                                }
                                                else if (event.mouseMove.y >= 589 && event.mouseMove.y <= 640){
                                                    m2 = 3;
                                                    n2 = 5;
                                                }
                                            }

                                            else{
                                                m2 = -1;
                                                n2 = -1;
                                            }
                                        }

                                        if (event.type == Event::MouseButtonPressed){
                                            if (event.mouseButton.button == Mouse::Left){
                                                hasEvent = true;
                                                //Drawing horizontal lines
                                                if (event.mouseButton.y >= 323 && event.mouseButton.y <= 343){
                                                    if (event.mouseButton.x >= 286 && event.mouseButton.x <= 340 && b_line_h[0][0] != true){
                                                        b_line_h[0][0] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 366 && event.mouseButton.x <= 420 && b_line_h[0][1] != true){
                                                        b_line_h[0][1] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 446 && event.mouseButton.x <= 500 && b_line_h[0][2] != true){
                                                        b_line_h[0][2] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 526 && event.mouseButton.x <= 580 && b_line_h[0][3] != true){
                                                        b_line_h[0][3] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 606 && event.mouseButton.x <= 660 && b_line_h[0][4] != true){
                                                        b_line_h[0][4] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                if (event.mouseButton.y >= 403 && event.mouseButton.y <= 423){
                                                    if (event.mouseButton.x >= 286 && event.mouseButton.x <= 340 && b_line_h[1][0] != true){
                                                        b_line_h[1][0] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 366 && event.mouseButton.x <= 420 && b_line_h[1][1] != true){
                                                        b_line_h[1][1] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 446 && event.mouseButton.x <= 500 && b_line_h[1][2] != true){
                                                        b_line_h[1][2] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 526 && event.mouseButton.x <= 580 && b_line_h[1][3] != true){
                                                        b_line_h[1][3] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 606 && event.mouseButton.x <= 660 && b_line_h[1][4] != true){
                                                        b_line_h[1][4] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                if (event.mouseButton.y >= 483 && event.mouseButton.y <= 503){
                                                    if (event.mouseButton.x >= 286 && event.mouseButton.x <= 340 && b_line_h[2][0] != true){
                                                        b_line_h[2][0] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 366 && event.mouseButton.x <= 420 && b_line_h[2][1] != true){
                                                        b_line_h[2][1] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 446 && event.mouseButton.x <= 500 && b_line_h[2][2] != true){
                                                        b_line_h[2][2] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 526 && event.mouseButton.x <= 580 && b_line_h[2][3] != true){
                                                        b_line_h[2][3] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 606 && event.mouseButton.x <= 660 && b_line_h[2][4] != true){
                                                        b_line_h[2][4] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                if (event.mouseButton.y >= 563 && event.mouseButton.y <= 583){
                                                    if (event.mouseButton.x >= 286 && event.mouseButton.x <= 340 && b_line_h[3][0] != true){
                                                        b_line_h[3][0] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 366 && event.mouseButton.x <= 420 && b_line_h[3][1] != true){
                                                        b_line_h[3][1] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 446 && event.mouseButton.x <= 500 && b_line_h[3][2] != true){
                                                        b_line_h[3][2] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 526 && event.mouseButton.x <= 580 && b_line_h[3][3] != true){
                                                        b_line_h[3][3] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 606 && event.mouseButton.x <= 660 && b_line_h[3][4] != true){
                                                        b_line_h[3][4] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                if (event.mouseButton.y >= 643 && event.mouseButton.y <= 663){
                                                    if (event.mouseButton.x >= 286 && event.mouseButton.x <= 340 && b_line_h[4][0] != true){
                                                        b_line_h[4][0] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 366 && event.mouseButton.x <= 420 && b_line_h[4][1] != true){
                                                        b_line_h[4][1] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 446 && event.mouseButton.x <= 500 && b_line_h[4][2] != true){
                                                        b_line_h[4][2] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 526 && event.mouseButton.x <= 580 && b_line_h[4][3] != true){
                                                        b_line_h[4][3] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.x >= 606 && event.mouseButton.x <= 660 && b_line_h[4][4] != true){
                                                        b_line_h[4][4] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                //Drawing vertical lines
                                                if (event.mouseButton.x >= 262 && event.mouseButton.x <= 282){
                                                    if (event.mouseButton.y >= 346 && event.mouseButton.y <= 400 && b_line_v[0][0] != true){
                                                        b_line_v[0][0] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 426 && event.mouseButton.y <= 480 && b_line_v[1][0] != true){
                                                        b_line_v[1][0] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 506 && event.mouseButton.y <= 560 && b_line_v[2][0] != true){
                                                        b_line_v[2][0] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 589 && event.mouseButton.y <= 640 && b_line_v[3][0] != true){
                                                        b_line_v[3][0] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                if (event.mouseButton.x >= 342 && event.mouseButton.x <= 362){
                                                    if (event.mouseButton.y >= 346 && event.mouseButton.y <= 400 && b_line_v[0][1] != true){
                                                        b_line_v[0][1] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 426 && event.mouseButton.y <= 480 && b_line_v[1][1] != true){
                                                        b_line_v[1][1] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 506 && event.mouseButton.y <= 560 && b_line_v[2][1] != true){
                                                        b_line_v[2][1] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 589 && event.mouseButton.y <= 640 && b_line_v[3][1] != true){
                                                        b_line_v[3][1] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                if (event.mouseButton.x >= 422 && event.mouseButton.x <= 442){
                                                    if (event.mouseButton.y >= 346 && event.mouseButton.y <= 400 && b_line_v[0][2] != true){
                                                        b_line_v[0][2] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 426 && event.mouseButton.y <= 480 && b_line_v[1][2] != true){
                                                        b_line_v[1][2] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 506 && event.mouseButton.y <= 560 && b_line_v[2][2] != true){
                                                        b_line_v[2][2] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 589 && event.mouseButton.y <= 640 && b_line_v[3][2] != true){
                                                        b_line_v[3][2] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                if (event.mouseButton.x >= 502 && event.mouseButton.x <= 522){
                                                    if (event.mouseButton.y >= 346 && event.mouseButton.y <= 400 && b_line_v[0][3] != true){
                                                        b_line_v[0][3] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 426 && event.mouseButton.y <= 480 && b_line_v[1][3] != true){
                                                        b_line_v[1][3] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 506 && event.mouseButton.y <= 560 && b_line_v[2][3] != true){
                                                        b_line_v[2][3] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 589 && event.mouseButton.y <= 640 && b_line_v[3][3] != true){
                                                        b_line_v[3][3] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                if (event.mouseButton.x >= 582 && event.mouseButton.x <= 602){
                                                    if (event.mouseButton.y >= 346 && event.mouseButton.y <= 400 && b_line_v[0][4] != true){
                                                        b_line_v[0][4] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 426 && event.mouseButton.y <= 480 && b_line_v[1][4] != true){
                                                        b_line_v[1][4] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 506 && event.mouseButton.y <= 560 && b_line_v[2][4] != true){
                                                        b_line_v[2][4] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 589 && event.mouseButton.y <= 640 && b_line_v[3][4] != true){
                                                        b_line_v[3][4] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }

                                                if (event.mouseButton.x >= 662 && event.mouseButton.x <= 682){
                                                    if (event.mouseButton.y >= 346 && event.mouseButton.y <= 400 && b_line_v[0][5] != true){
                                                        b_line_v[0][5] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 426 && event.mouseButton.y <= 480 && b_line_v[1][5] != true){
                                                        b_line_v[1][5] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 506 && event.mouseButton.y <= 560 && b_line_v[2][5] != true){
                                                        b_line_v[2][5] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                    else if (event.mouseButton.y >= 589 && event.mouseButton.y <= 640 && b_line_v[3][5] != true){
                                                        b_line_v[3][5] = true;
                                                        isPlayer1Turn = !isPlayer1Turn;
                                                    }
                                                }
                                            }
                                        }

                                        for(int i = 0; i < 5; ++i){
                                            for(int j = 0; j < 6; ++j){
                                                window.draw(drawCircle(dot[i][j].x, dot[i][j].y));
                                            }
                                        }

                                        if (m != -1 && n != -1){
                                            window.draw(drawLineHorizontal(line_h[m][n].x, line_h[m][n].y, 1));

                                        }

                                        if (m2 != -1 && n2 != -1){
                                            window.draw(drawLineVertical(line_v[m2][n2].x, line_v[m2][n2].y, 1));

                                        }

                                        for(int i = 0; i < 5; ++i){
                                            for(int j = 0; j < 5; ++j){
                                                if (b_line_h[i][j]){
                                                    window.draw(drawLineHorizontal(line_h[i][j].x, line_h[i][j].y, 0));
                                                }
                                            }
                                        }

                                        for(int i = 0; i < 4; ++i){
                                            for(int j = 0; j < 6; ++j){
                                                if (b_line_v[i][j]){
                                                    window.draw(drawLineVertical(line_v[i][j].x, line_v[i][j].y, 0));
                                                }
                                            }
                                        }
                                        bool flag = false;
                                        if (hasEvent){
                                            for(int i = 0; i < 4; ++i){
                                                for(int j = 0; j < 5; ++j){
                                                    if (b_line_h[i][j] + b_line_h[i + 1][j] + b_line_v[i][j] + b_line_v[i][j + 1] == 4){
                                                        if(box_turn[i][j] == 0){
                                                            if (!flag){
                                                                isPlayer1Turn = !isPlayer1Turn;
                                                            }
                                                            if(isPlayer1Turn){
                                                                box_turn[i][j] = 1;
                                                                ++count1;
                                                            }
                                                            else{
                                                                box_turn[i][j] = 2;
                                                                ++count2;
                                                            }
                                                            b_box[i][j] = true;
                                                            flag = true;
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        for(int i = 0; i < 4; ++i){
                                            for(int j = 0; j < 5; ++j){
                                                if (b_box[i][j]){
                                                    if(box_turn[i][j] == 1){
                                                        x_sprite.setPosition(box[i][j].x, box[i][j].y);
                                                        window.draw(x_sprite);
                                                    }
                                                    else if (box_turn[i][j] == 2){
                                                        o_sprite.setPosition(box[i][j].x, box[i][j].y);
                                                        window.draw(o_sprite);
                                                    }
                                                }
                                            }
                                        }

                                        Font font;
                                        font.loadFromFile("arial.ttf");

                                        Text player1;
                                        player1.setFont(font);
                                        player1.setString("Player 1:");
                                        player1.setColor(Color::Red);
                                        player1.setCharacterSize(35);
                                        player1.setPosition(860, 280);
                                        window.draw(player1);

                                        stringstream sscore1;
                                        sscore1 << count1;
                                        string str1;
                                        if (count1 < 10){
                                            str1 = '0' + sscore1.str();
                                        }
                                        else{
                                            str1 = sscore1.str();
                                        }
                                        Text score1;
                                        score1.setFont(font);
                                        score1.setString(str1);
                                        score1.setColor(Color::Red);
                                        score1.setCharacterSize(35);
                                        score1.setPosition(905, 340);
                                        window.draw(score1);

                                        Text player2;
                                        player2.setFont(font);
                                        player2.setString("Player 2:");
                                        player2.setColor(Color::Blue);
                                        player2.setCharacterSize(35);
                                        player2.setPosition(860, 480);
                                        window.draw(player2);

                                        stringstream sscore2;
                                        sscore2 << count2;
                                        string str2;
                                        if (count2 < 10){
                                            str2 = '0' + sscore2.str();
                                        }
                                        else{
                                            str2 = sscore2.str();
                                        }
                                        Text score2;
                                        score2.setFont(font);
                                        score2.setString(str2);
                                        score2.setColor(Color::Blue);
                                        score2.setCharacterSize(35);
                                        score2.setPosition(905, 540);
                                        window.draw(score2);

                                        bool endflag = false;
                                        if (count1 + count2 == 20){
                                            endflag = true;

                                            Text gameover;
                                            gameover.setFont(font);
                                            gameover.setString("GAME OVER");
                                            gameover.setColor(Color::Black);
                                            gameover.setCharacterSize(100);
                                            gameover.setPosition(207, 0);
                                            window.draw(gameover);

                                            Text winner;
                                            winner.setFont(font);
                                            winner.setString("WINNER");
                                            winner.setCharacterSize(40);
                                            if (count2 > count1){
                                                winner.setColor(Color::Blue);
                                                winner.setPosition(845, 430);
                                                window.draw(winner);
                                            }
                                            else if (count2 < count1){
                                                winner.setColor(Color::Red);
                                                winner.setPosition(845, 230);
                                                window.draw(winner);
                                            }
                                            else{
                                                Text draw1, draw2;
                                                draw1.setFont(font);
                                                draw1.setString("DRAW");
                                                draw1.setCharacterSize(40);
                                                draw1.setColor(Color::Blue);
                                                draw1.setPosition(865, 430);
                                                window.draw(draw1);

                                                draw2.setFont(font);
                                                draw2.setString("DRAW");
                                                draw2.setCharacterSize(40);
                                                draw2.setColor(Color::Red);
                                                draw2.setPosition(865, 230);
                                                window.draw(draw2);
                                            }
                                        }

                                        if (!endflag){
                                            CircleShape arrow1(15, 3);
                                            arrow1.setFillColor(Color::Red);
                                            arrow1.setRotation(90);
                                            arrow1.setPosition(853, 286);
                                            if (isPlayer1Turn){
                                                window.draw(arrow1);
                                            }

                                            CircleShape arrow2(15, 3);
                                            arrow2.setFillColor(Color::Blue);
                                            arrow2.setRotation(90);
                                            arrow2.setPosition(853, 486);
                                            if (!isPlayer1Turn){
                                                window.draw(arrow2);
                                            }
                                        }

                                        window.display();
                                    }
                                }
                            }
                        if(event.mouseButton.y>=500&&event.mouseButton.y<=520)
                            window.close();
                    }
                break;

			case sf::Event::Closed:
				window.close();

				break;

			}

		}

        menu.draw(window);
        window.display();
	}
}

