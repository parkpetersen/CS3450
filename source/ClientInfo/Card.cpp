// Project Includes
#include "Card.hpp"

// Standard Includes
#include <map>

Card::Card(Suit s, Value v) : suit(s), value(v)
{
}

Suit Card::getSuit() const
{
  return this->suit;
}

Value Card::getValue() const
{
  return this->value;
}

bool operator<(const Card& card, const Card& otherCard)
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