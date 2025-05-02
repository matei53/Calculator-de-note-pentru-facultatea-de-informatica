#ifndef OBIECT_H
#define OBIECT_H

#include "SFML/Graphics.hpp"
#include <functional>

struct ClickHandler
{
	std::function<void()> onclick;
};

class Obiect
{
protected:
	sf::Vector2f pozitie;
	sf::Vector2f marime;
	std::shared_ptr<ClickHandler> click_handler;
	std::shared_ptr<sf::Clock> clock;

	unsigned int marime_font;
	sf::RectangleShape forma;
	sf::Text text;
	sf::Color culoare;

public:
	Obiect(const sf::Vector2f&, const sf::Vector2f&, const unsigned int, const std::string&, const sf::Font&, const sf::Color&);
	~Obiect() = default;

	virtual std::shared_ptr<Obiect> clone() const = 0; //constructor "virtual" de copiere

	virtual void update() = 0;
	void render(sf::RenderWindow&) const;
	virtual void align();
	void changeColor(const sf::Color);
	std::pair<sf::Vector2f, sf::Vector2f> getBounds() const;
	bool isClickable() const;
	void setClickHandler(std::shared_ptr<ClickHandler>);
	std::shared_ptr<ClickHandler> getClickHandler();
};

#endif
