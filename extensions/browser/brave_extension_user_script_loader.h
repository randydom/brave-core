/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "extensions/browser/extension_user_script_loader.h"
#include "brave/extensions/browser/web3_provider_extension_observer.h"

namespace extensions {

class BraveExtensionUserScriptLoader : public ExtensionUserScriptLoader,
      public Web3ProviderExtensionObserver {
 public:
  BraveExtensionUserScriptLoader(content::BrowserContext* browser_context,
      const HostID& host_id, bool listen_for_extension_system_loaded);

 protected:
  void OnWeb3ProviderChanged(const std::string& extension_id) override;
};

}  // namespace extensions
