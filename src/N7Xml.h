/*
 *  Copyright (C) 2005-2020 Team Kodi
 *  https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include "client.h"
#include <vector>

struct PVRChannel
{
  int         iUniqueId;
  int         iChannelNumber;
  std::string strChannelName;
  std::string strIconPath;
  std::string strStreamURL;
  
  PVRChannel() 
  {
    iUniqueId      = 0;
    iChannelNumber = 0;
    strChannelName = "";
    strIconPath    = "";
    strStreamURL   = "";    
  }
};

class CCurlFile
{
public:
  CCurlFile(void) {};
  ~CCurlFile(void) {};

  bool Get(const std::string &strURL, std::string &strResult);
};

class N7Xml
{
public:
  N7Xml(void);
  ~N7Xml(void);
  int getChannelsAmount(void);
  PVR_ERROR requestChannelList(ADDON_HANDLE handle, bool bRadio);
  PVR_ERROR GetChannelStreamProperties(const PVR_CHANNEL*, PVR_NAMED_VALUE*, unsigned int*);
  void list_channels(void);
private:
  std::vector<PVRChannel> m_channels;
  bool                    m_connected;
};
