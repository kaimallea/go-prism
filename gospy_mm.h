/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Metamod:Source GoSpy Plugin
 * Written by Kai Mallea
 * ======================================================
 *
 */

#ifndef _INCLUDE_METAMOD_SOURCE_GOSPY_PLUGIN_H_
#define _INCLUDE_METAMOD_SOURCE_GOSPY_PLUGIN_H_

#include <ISmmPlugin.h>
#include <igameevents.h>
#include <iplayerinfo.h>

#if defined WIN32 && !defined snprintf
#define snprintf _snprintf
#endif

class GoSpyPlugin : public ISmmPlugin
{
public:
	bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late);
	bool Unload(char *error, size_t maxlen);
	bool Pause(char *error, size_t maxlen);
	bool Unpause(char *error, size_t maxlen);
	void AllPluginsLoaded();
public:
	void Hook_ServerActivate(edict_t *pEdictList, int edictCount, int clientMax);
public:
	const char *GetAuthor();
	const char *GetName();
	const char *GetDescription();
	const char *GetURL();
	const char *GetLicense();
	const char *GetVersion();
	const char *GetDate();
	const char *GetLogTag();
};

extern GoSpyPlugin g_GoSpyPlugin;

PLUGIN_GLOBALVARS();

#endif //_INCLUDE_METAMOD_SOURCE_GOSPY_PLUGIN_H_
