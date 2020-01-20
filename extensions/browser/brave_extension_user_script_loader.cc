/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/extensions/browser/brave_extension_user_script_loader.h"
#include "brave/common/extensions/extension_constants.h"

namespace extensions {

BraveExtensionUserScriptLoader::BraveExtensionUserScriptLoader(
        content::BrowserContext* browser_context,
        const HostID& host_id, bool listen_for_extension_system_loaded) :
    ExtensionUserScriptLoader(browser_context, host_id,
        listen_for_extension_system_loaded) {
}

void BraveExtensionUserScriptLoader::OnWeb3ProviderChanged(const std::string& extension_id) {
  if (extension_id == metamask_extension_id) {
    LOG(ERROR) << "======MetaMask extension id selected";
  } else if (extension_id == ethereum_remote_client_extension_id) {
    LOG(ERROR) << "======Brave Crypto Wallets extension id selected";
  }
}

}  // namespace extensions
