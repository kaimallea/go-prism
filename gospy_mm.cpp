/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Metamod:Source GoSpy Plugin
 * Written by Kai Mallea
 * ======================================================
 *
 */

#include <stdio.h>
#include "gospy_mm.h"

SH_DECL_HOOK3_void(IServerGameDLL, ServerActivate, SH_NOATTRIB, 0, edict_t *, int, int);

GoSpyPlugin g_GoSpyPlugin;
IServerGameDLL *server = NULL;

PLUGIN_EXPOSE(GoSpyPlugin, g_GoSpyPlugin);
bool GoSpyPlugin::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	PLUGIN_SAVEVARS();

	GET_V_IFACE_ANY(GetServerFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);

	SH_ADD_HOOK_STATICFUNC(IServerGameDLL, ServerActivate, server, Hook_ServerActivate, true);

	return true;
}

bool GoSpyPlugin::Unload(char *error, size_t maxlen)
{
	SH_REMOVE_HOOK_STATICFUNC(IServerGameDLL, ServerActivate, server, Hook_ServerActivate, true);

	return true;
}

void Hook_ServerActivate(edict_t *pEdictList, int edictCount, int clientMax)
{
	META_LOG(g_PLAPI, "ServerActivate() called: edictCount = %d, clientMax = %d", edictCount, clientMax);
}

void GoSpyPlugin::AllPluginsLoaded()
{
	/* This is where we'd do stuff that relies on the mod or other plugins 
	 * being initialized (for example, cvars added and events registered).
	 */
}

bool GoSpyPlugin::Pause(char *error, size_t maxlen)
{
	return true;
}

bool GoSpyPlugin::Unpause(char *error, size_t maxlen)
{
	return true;
}

const char *GoSpyPlugin::GetLicense()
{
	return "TBD";
}

const char *GoSpyPlugin::GetVersion()
{
	return "0.0.1";
}

const char *GoSpyPlugin::GetDate()
{
	return __DATE__;
}

const char *GoSpyPlugin::GetLogTag()
{
	return "GOSPY";
}

const char *GoSpyPlugin::GetAuthor()
{
	return "Kai Mallea";
}

const char *GoSpyPlugin::GetDescription()
{
	return "Capture CS:GO gameplay data";
}

const char *GoSpyPlugin::GetName()
{
	return "GoSpy";
}

const char *GoSpyPlugin::GetURL()
{
	return "https://github.com/csgo-data/go-spy";
}
