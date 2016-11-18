#include "Player.hpp"

//void Player::playCard(std::unique_ptr<Card> card)
//{
//  this->playerHand.playCard(card->getSuit(), card->getValue());
//}


void Player::insertCardToHand(Card card)
{
	this->playerHand.push_back(card);
}
