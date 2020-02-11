#include "../includeFuncionamento/Menu.h"
using namespace Funcionamento;

Menu::Menu()
{
    textura.loadFromFile("imagens/fundo.png");
    imagem.setTexture(textura);
	imagem.setColor(Color(255, 255, 255, 255*3));
	imagem.scale(1,1);
	fonte.loadFromFile("verdanab.ttf");

    menu0.setFont(fonte);
	menu0.setCharacterSize(70);

    menu1.setFont(fonte);
	menu1.setCharacterSize(70);

	menu2.setFont(fonte);
	menu2.setCharacterSize(70);

	menu3.setFont(fonte);
	menu3.setCharacterSize(70);

	menu4.setFont(fonte);
	menu4.setCharacterSize(70);
	setAtivo(true);

}
Menu::~Menu()
{

}
void Menu::setAtivo(bool ativo)
{
    this->ativo = ativo;
}
bool Menu::getAtivo()
{
    return ativo;
}
int Menu::menuPrincipal(RenderWindow* App)
{
    Event evento;

    menu0.setString("Players 1");
	menu0.setPosition({ 400.f, 160.f });
    menu2.setString("Players 2");
	menu2.setPosition({ 400.f, 250.f });
    menu3.setString("Exit");
	menu3.setPosition({ 480.f, 340.f });

    while (ativo)
	{
		while (App->pollEvent(evento))
		{
			if (evento.type == Event::Closed)
			{
				return -2;
			}
			if (evento.type == Event::KeyPressed)
			{
				switch (evento.key.code)
				{
                    case Keyboard::Up:
                        if(menu > 0)
                            menu--;
                        else
                            menu = 2;
                        break;
                    case Keyboard::Down:
                        if(menu < 2)
                            menu++;
                        else
                            menu = 0;
                        break;
                    case Keyboard::Return:
                            return menu;
                        break;
                    default:
                        break;
				}
			}
		}

		imagem.setColor(Color(255, 255, 255, 255*3));
		if (menu == 0)
		{
			menu0.setColor(Color::Red);
			menu2.setColor(Color::Black);
			menu3.setColor(Color::Black);
			menu4.setColor(Color::Black);
		}
		else if(menu == 1)
        {
            menu0.setColor(Color::Black);
            menu2.setColor(Color::Red);
            menu3.setColor(Color::Black);
            menu4.setColor(Color::Black);
        }
        else if(menu == 2)
        {
            menu0.setColor(Color::Black);
            menu2.setColor(Color::Black);
            menu3.setColor(Color::Red);
            menu4.setColor(Color::Black);
        }

		App->clear();
		App->draw(imagem);

        App->draw(menu0);
        App->draw(menu2);
        App->draw(menu3);
		App->display();

    }
	return (-1);
}
int Menu::menuFases(RenderWindow* App)
{
    Event evento;

    menu0.setString("Play");
	menu0.setPosition({ 480.f, 130.f });
    menu2.setString("Floresta");
	menu2.setPosition({ 400.f, 220.f });
    menu3.setString("Labirinto");
	menu3.setPosition({ 400.f, 310.f });
    menu4.setString("Templo");
	menu4.setPosition({ 420.f, 400.f });
	menu1.setString("Chefão");
	menu1.setPosition({ 430.f, 490.f });

    while (ativo)
	{
		while (App->pollEvent(evento))
		{
			if (evento.type == Event::Closed)
			{
				return -2;
			}
			if (evento.type == Event::KeyPressed)
			{
				switch (evento.key.code)
				{
                    case Keyboard::Up:
                        if(menu > 0)
                            menu--;
                        else
                            menu = 4;
                        break;
                    case Keyboard::Down:
                        if(menu < 4)
                            menu++;
                        else
                            menu = 0;
                        break;
                    case Keyboard::Return:
                            return menu;
                        break;
                    default:
                        break;
				}
			}
		}

		imagem.setColor(Color(255, 255, 255, 255*3));
		if (menu == 0)
		{
			menu0.setColor(Color::Red);
			menu2.setColor(Color::Black);
			menu3.setColor(Color::Black);
			menu4.setColor(Color::Black);
            menu1.setColor(Color::Black);
		}
		else if(menu == 1)
        {
            menu0.setColor(Color::Black);
            menu2.setColor(Color::Red);
            menu3.setColor(Color::Black);
            menu4.setColor(Color::Black);
            menu1.setColor(Color::Black);
        }
        else if(menu == 2)
        {
            menu0.setColor(Color::Black);
            menu2.setColor(Color::Black);
            menu3.setColor(Color::Red);
            menu4.setColor(Color::Black);
            menu1.setColor(Color::Black);
        }
        else if(menu == 3)
        {
            menu0.setColor(Color::Black);
            menu2.setColor(Color::Black);
            menu3.setColor(Color::Black);
            menu4.setColor(Color::Red);
            menu1.setColor(Color::Black);
        }
        else if(menu == 4)
        {
            menu0.setColor(Color::Black);
            menu2.setColor(Color::Black);
            menu3.setColor(Color::Black);
            menu4.setColor(Color::Black);
            menu1.setColor(Color::Red);
        }

		App->clear();
		App->draw(imagem);

        App->draw(menu0);
        App->draw(menu2);
        App->draw(menu3);
        App->draw(menu4);
        App->draw(menu1);
		App->display();

    }
	return (-1);

}
