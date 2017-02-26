/*
 * Player.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: jacobmb
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "Player.h"

using namespace std;

Player::Player(string name, int wins, int losses, int draws) {
	this->name = name;
	this->wins = wins;
	this->losses = losses;
	this->draws = draws;
}
Player::~Player() {}
int Player::getRPSThrow() {
	return rand() % 3;
}
double Player::getWinRecord() {
	if((wins + losses + draws) == 0) {
		return 0;
	}
	return wins / (wins + losses + draws);
}
string Player::toString() {
	stringstream ss;
	ss << "Name: " << getName() << '\n';
	ss << "Wins: " << getWins() << '\n';
	ss << "Losses: " << getLosses() << '\n';
	ss << "Draws: " << getDraws() << '\n';
	ss << "Win Record: " << getWinRecord() << '\n';
	return ss.str();
}

string Player::getName() {
	return name;
}
int Player::getWins() {
	return wins;
}
int Player::getLosses() {
	return losses;
}
int Player::getDraws() {
	return draws;
}
void Player::addWin() {
	this->wins++;
}
void Player::addLoss() {
	this->losses++;
}
void Player::addDraw() {
	this->draws++;
}
