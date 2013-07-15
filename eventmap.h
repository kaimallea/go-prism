/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Metamod:Source GoPrism Plugin
 * Written by Kai Mallea
 * ======================================================
 *
 */

#ifndef _INCLUDE_EVENTMAP_H_
#define _INCLUDE_EVENTMAP_H_

#include <map>
#include <string>

class GoPrismPlugin;

typedef void (GoPrismPlugin::*callback_func_t)(IGameEvent *event);
typedef std::map<std::string, callback_func_t> event_map_t;

#endif // _INCLUDE_EVENTMAP_H_
