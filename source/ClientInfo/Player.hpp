#ifndef PLAYER_HPP
#define PLAYER_HPP

// Project Includes
//#include "Hand.hpp"
#include <vector>
#include "Card.hpp"
#include <string>
// Standard Includes
#include <memory>

class Player
{
private:
  

public:
  std::vector<Card> playerHand;
  //void playCard(std::unique_ptr<Card>);
  void insertCardToHand(Card card);
};

#endif