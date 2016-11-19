// Project Includes
#include "Card.hpp"

// Standard Includes
#include <map>

Card::Card(Suit s, Value v)
{
	this->suit = s;
	this->value = v;
	this->imagePath = " ";
	if (s == 0)
		this->imagePath = "../../../../CS3450/Resources/cards/" + std::to_string(v) + "h.png";
	else if (s == 1)
		this->imagePath = "../../../../CS3450/Resources/cards/" + std::to_string(v) + "s.png";
	else if (s==2)
		this->imagePath = "../../../../CS3450/Resources/cards/" + std::to_string(v) + "c.png";
	else if (s==3)
		this->imagePath = "../../../../CS3450/Resources/cards/" + std::to_string(v) + "d.png";
}

Suit Card::getSuit()
{
  return this->suit;
}

Value Card::getValue()
{
  return this->value;
}

bool operator<(Card& card, Card& otherCard)
{
  if (card.getSuit() < otherCard.getSuit())
  {
    return true;
  }
  else if (card.getSuit() > otherCard.getSuit())
  {
    return false;
  }
  else
  {
    return card.getValue() < otherCard.getValue();
  }
}

std::string Card::getImagePath()
{
	return this->imagePath;
}