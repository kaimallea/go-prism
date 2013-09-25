/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Metamod:Source GoPrism Plugin
 * Written by Kai Mallea
 * ======================================================
 *
 */
#include "playerlist.h"

PlayerList::PlayerList() {
	player_vect = new std::vector<IPlayerInfo *>;
}

PlayerList::~PlayerList() {
	std::vector<IPlayerInfo *>::iterator it;
	for (it = player_vect->begin(); it != player_vect->end(); it++)
		delete *it;
}

void PlayerList::AddPlayer(IPlayerInfo *p) {
	player_vect->push_back(p);
}

std::vector<IPlayerInfo *>::size_type PlayerList::Length() {
	return player_vect->size();
}
