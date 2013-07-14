/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Metamod:Source GoPrism Plugin
 * Written by Kai Mallea
 * ======================================================
 *
 */

#include <stdio.h>
#include "goprism_mm.h"

SH_DECL_HOOK3_void(IServerGameDLL, ServerActivate, SH_NOATTRIB, 0, edict_t *, int, int);
SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent *, bool);

GoPrismPlugin g_GoPrismPlugin;
IVEngineServer *engine = NULL;
IGameEventManager2 *gameevents = NULL;
IServerGameDLL *server = NULL;
IPlayerInfoManager *playerinfomanager = NULL;



CGlobalVars *gpGlobals = NULL;

PLUGIN_EXPOSE(GoPrismPlugin, g_GoPrismPlugin);
bool GoPrismPlugin::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	PLUGIN_SAVEVARS();

	GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer, INTERFACEVERSION_VENGINESERVER);
	GET_V_IFACE_CURRENT(GetEngineFactory, gameevents, IGameEventManager2, INTERFACEVERSION_GAMEEVENTSMANAGER2);
	GET_V_IFACE_ANY(GetServerFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
	GET_V_IFACE_ANY(GetServerFactory, playerinfomanager, IPlayerInfoManager, INTERFACEVERSION_PLAYERINFOMANAGER);

	gpGlobals = ismm->GetCGlobals();

	META_LOG(g_PLAPI, "Starting plugin.");

	SH_ADD_HOOK_MEMFUNC(IServerGameDLL, ServerActivate, server, this, &GoPrismPlugin::Hook_ServerActivate, true);

	return true;
}

bool GoPrismPlugin::Unload(char *error, size_t maxlen)
{
	SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, ServerActivate, server, this, &GoPrismPlugin::Hook_ServerActivate, true);

	return true;
}

void GoPrismPlugin::Hook_ServerActivate(edict_t *pEdictList, int edictCount, int clientMax)
{
	META_LOG(g_PLAPI, "ServerActivate() called: edictCount = %d, clientMax = %d", edictCount, clientMax);
}

void GoPrismPlugin::AllPluginsLoaded()
{
	/* This is where we'd do stuff that relies on the mod or other plugins 
	 * being initialized (for example, cvars added and events registered).
	 */
}

bool GoPrismPlugin::Pause(char *error, size_t maxlen)
{
	return true;
}

bool GoPrismPlugin::Unpause(char *error, size_t maxlen)
{
	return true;
}

const char *GoPrismPlugin::GetLicense()
{
	return "TBD";
}

const char *GoPrismPlugin::GetVersion()
{
	return "0.0.1";
}

const char *GoPrismPlugin::GetDate()
{
	return __DATE__;
}

const char *GoPrismPlugin::GetLogTag()
{
	return "GOPRISM";
}

const char *GoPrismPlugin::GetAuthor()
{
	return "Kai Mallea";
}

const char *GoPrismPlugin::GetDescription()
{
	return "Capture CS:GO gameplay data";
}

const char *GoPrismPlugin::GetName()
{
	return "GoPrism";
}

const char *GoPrismPlugin::GetURL()
{
	return "https://github.com/csgo-data/go-prism";
}