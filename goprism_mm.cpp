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
event_map_t FireEventMap;

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

	SH_ADD_HOOK(IServerGameDLL, ServerActivate, server, SH_MEMBER(this, &GoPrismPlugin::Hook_ServerActivate), true);
	SH_ADD_HOOK(IGameEventManager2, FireEvent, gameevents, SH_MEMBER(this, &GoPrismPlugin::Hook_FireEvent), false);

    FireEventMap["player_death"] = &GoPrismPlugin::OnPlayerDeath;

	return true;
}

bool GoPrismPlugin::Unload(char *error, size_t maxlen)
{
	SH_REMOVE_HOOK(IServerGameDLL, ServerActivate, server, SH_MEMBER(this, &GoPrismPlugin::Hook_ServerActivate), true);
	SH_REMOVE_HOOK(IGameEventManager2, FireEvent, gameevents, SH_MEMBER(this, &GoPrismPlugin::Hook_FireEvent), false);

	return true;
}

void GoPrismPlugin::Hook_ServerActivate(edict_t *pEdictList, int edictCount, int clientMax)
{
	META_LOG(g_PLAPI, "ServerActivate() called: edictCount = %d, clientMax = %d", edictCount, clientMax);
}

bool GoPrismPlugin::Hook_FireEvent(IGameEvent *event, bool bDontBroadcast)
{
    std::string ename = event->GetName();
	if (event && FireEventMap.count(ename)) {
	    (g_GoPrismPlugin.*FireEventMap[ename])(event);
	}

	RETURN_META_VALUE(MRES_IGNORED, true);
}

void GoPrismPlugin::OnPlayerDeath(IGameEvent *event)
{
    META_CONPRINTF("player_death fired: victim = %d, attacker = %d\n", event->GetInt("userid"), event->GetInt("attacker"));
}

void GoPrismPlugin::OnBombBeginPlant(IGameEvent *event) {}

void GoPrismPlugin::OnBombPlanted(IGameEvent *event) {}

void GoPrismPlugin::OnBombDefused(IGameEvent *event) {}

void GoPrismPlugin::OnBombExploded(IGameEvent *event) {}

void GoPrismPlugin::OnBombBeginDefuse(IGameEvent *event) {}

void GoPrismPlugin::OnBombAbortDefuse(IGameEvent *event) {}

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
