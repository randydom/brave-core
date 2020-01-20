/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_EXTENSIONS_BROWSER_WEB3_PROVIDER_EXTENSION_OBSERVER_H_
#define BRAVE_EXTENSIONS_BROWSER_WEB3_PROVIDER_EXTENSION_OBSERVER_H_

#include <string>

namespace extensions {

class Web3ProviderExtensionObserver {
 public:
  virtual ~Web3ProviderExtensionObserver() {}

  // Called after an extension is loaded. The extension will exclusively exist
  // in the enabled_extensions set of ExtensionRegistry.
  virtual void OnWeb3ProviderChanged(const std::string& extension_id) = 0;
};

}  // namespace extension

#endif  // BRAVE_EXTENSIONS_BROWSER_WEB3_PROVIDER_EXTENSION_OBSERVER_H_
