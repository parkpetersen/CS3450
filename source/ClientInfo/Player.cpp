#include "Player.hpp"

void Player::playCard(std::unique_ptr<Card> card)
{
  //this->playerHand.playCard(card->getSuit(), card->getValue()); leaving commented for now
}


void Player::insertCardToHand(Card card)
{
	this->playerHand.push_back(card);
}

int Player::getScore()
{
	return this->playerScore;
}

void Player::setScore(int score)
{
	this->playerScore = score;
}

int Player::getBid() const
{
	return this->bid;
}

void Player::setBid(int inputBid)
{
	this->bid = inputBid;
}

int Player::getBags() const
{
	return this->bags;
}

void Player::setBags(int bag)
{
	this->bags = bag;
}

int Player::getTricksWon() const
{
	return this->tricksWon;
}

void Player::incrementTricksWon()
{
	this->tricksWon++;
}

void Player::incrementScore(int i)
{
	playerScore += i;
}

void Player::organizeHand(std::vector<Card>& userHand)
{
	std::sort(userHand.begin(), userHand.end());
}