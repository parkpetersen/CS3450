// Project Includes
#include "Hand.hpp"

// Standard Includes
#include <algorithm>
#include <memory>

void Hand::organizeHand(std::vector<Card>& userHand)
{
  //std::sort(userHand.begin(), userHand.end());
}

bool Hand::isEmpty()
{
  return this->userHand.empty();
}

Card Hand::playCard(Suit s, Value v)
{
  auto it = userHand.begin();
  for (auto&& c : this->userHand)
  {
    if (c.getSuit() == s && c.getValue() == v)
    {
      Card returnedCard = c;
      userHand.erase(it);
      return returnedCard;
    }
    ++it;
  }
}