/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Metamod:Source GoPrism Plugin
 * Written by Kai Mallea
 * ======================================================
 *
 */

#ifndef PLAYERLIST_H
#define	PLAYERLIST_H

#include <ISmmPlugin.h>
#include <iplayerinfo.h>
#include <vector>

class PlayerList {
public:
	PlayerList();
	virtual ~PlayerList();
public:
	void AddPlayer(IPlayerInfo *p);
	std::vector<IPlayerInfo *>::size_type Length();
private:
	std::vector<IPlayerInfo *> * player_vect;
};

#endif	/* PLAYERLIST_H */

