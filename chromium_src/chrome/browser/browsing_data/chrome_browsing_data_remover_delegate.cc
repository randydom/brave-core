/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "components/content_settings/core/browser/content_settings_info.h"
#include "components/content_settings/core/browser/website_settings_info.h"

#define SKIP_BRAVE_SHIELDS_SETTINGS(info) \
  if (info->website_settings_info()->type() == CONTENT_SETTINGS_TYPE_JAVASCRIPT) \
    continue; \
  if (info->website_settings_info()->type() == CONTENT_SETTINGS_TYPE_PLUGINS) \
    continue;

#include "../../../../../chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc"

#undef SKIP_BRAVE_SHIELDS_SETTINGS
