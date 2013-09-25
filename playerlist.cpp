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
	delete [] player_vect;
}

void PlayerList::AddPlayer(IPlayerInfo *p) {
	player_vect->push_back(p);
}

std::vector<IPlayerInfo *>::size_type PlayerList::Length() {
	return player_vect->size();
}
