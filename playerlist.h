/* 
 * File:   playerlist.h
 * Author: km
 *
 * Created on July 21, 2013, 5:48 PM
 */

#ifndef PLAYERLIST_H
#define	PLAYERLIST_H

#include <vector>

class Player;

class PlayerList {
public:
	PlayerList();
	virtual ~PlayerList();
public:
	void AddPlayer(Player *p);
	std::vector<Player *>::size_type Length();
private:
	std::vector<Player *> * player_vect;
};

#endif	/* PLAYERLIST_H */

