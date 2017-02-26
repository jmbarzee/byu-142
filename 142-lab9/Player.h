/*
 * Player.h
 *
 *  Created on: Mar 23, 2015
 *      Author: jacobmb
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

using namespace std;

class Player {
public:

	Player(string name, int wins = 0, int losses = 0, int draws = 0);
	~Player();
	int getRPSThrow();
	double getWinRecord();
	string toString();
	string getName();
	int getWins();
	int getLosses();
	int getDraws();
	void addWin();
	void addLoss();
	void addDraw();
private:
	string name;
	int wins, losses, draws;

};

#endif /* PLAYER_H_ */
