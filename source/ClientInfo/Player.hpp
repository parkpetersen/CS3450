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
	int playerScore = 0;

public:
	void incrementScore(int i);
  std::vector<Card> playerHand;
  void playCard(std::unique_ptr<Card>);
  void insertCardToHand(Card card);
  int getScore();
};

#endif