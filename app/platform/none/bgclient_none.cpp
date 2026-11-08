/*
 * Gatefold NX · bgclient.cpp
 * The IPC calls to the background player. The PC preview has no sysmodule: there, connect()
 * simply fails and Gatefold plays on its own, as it does on a console without the sysmodule.
 */
#include "bgclient.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

bool BgClient::connect() { return false; }
void BgClient::disconnect() {}
bool BgClient::poll(double) { return false; }
double BgClient::position(double) const { return 0; }
bool BgClient::setQueue(const BgQueue&) { return false; }
void BgClient::setAutomixModel(int, const std::string&) {}
bool BgClient::getQueue(BgQueue&) { return false; }
void BgClient::playAt(int, bool, double) {}
void BgClient::toggle(double) {}
void BgClient::pause(double) {}
void BgClient::stop() {}
void BgClient::next() {}
void BgClient::prev() {}
void BgClient::checkArtwork() {}
void BgClient::seek(double, double) {}
void BgClient::setVolume(float) {}
void BgClient::setStopAfter(bool) {}
void BgClient::setLevelMode(int) {}
void BgClient::setSleep(float) {}
void BgClient::setCrossfade(float, bool) {}
bool BgClient::eq(GfbgEq&) { return false; }
void BgClient::setEq(const GfbgEq&) {}
bool BgClient::pcm(float*, int) { return false; }
bool BgClient::config(BgConfig&) { return false; }
void BgClient::setConfig(const BgConfig&) {}
void BgClient::browseHome() {}
void BgClient::browseLibrary() {}
void BgClient::browseSearch(const std::string&) {}
void BgClient::browseOpen(uint64_t, uint32_t) {}
void BgClient::browseBack(uint64_t) {}
void BgClient::browsePlay(uint64_t, uint32_t) {}
bool BgClient::pollBrowse(BgBrowsePage& out) { out = browsePage_; return false; }
void BgClient::playTrack(int, const std::string&, const std::string&) {}
bool BgClient::fetchLibraryPlaylists(std::vector<std::pair<std::string, std::string>>&) { return false; }
bool BgClient::fetchCollectionTracks(uint32_t, std::vector<BgBrowseItem>&) { return false; }
bool BgClient::fetchPlaylistTracks(const std::string&, std::vector<BgBrowseItem>&) { return false; }
