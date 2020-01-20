/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_EXTENSIONS_BROWSER_WEB3_PROVIDER_EXTENSION_REGISTRY_H_
#define BRAVE_EXTENSIONS_BROWSER_WEB3_PROVIDER_EXTENSION_REGISTRY_H_

#include "base/observer_list.h"
#include "components/keyed_service/core/keyed_service.h"

namespace content {
class BrowserContext;
}  // namespace content

namespace extensions {

class Web3ProviderExtensionObserver;

class Web3ProviderExtensionRegistry : public KeyedService {
 public:
  explicit Web3ProviderExtensionRegistry(content::BrowserContext* browser_context);
  ~Web3ProviderExtensionRegistry() override;

  // Returns the instance for the given |browser_context|.
  static Web3ProviderExtensionRegistry* Get(content::BrowserContext* browser_context);
  content::BrowserContext* browser_context() const { return browser_context_; }

  void AddObserver(Web3ProviderExtensionObserver* observer);
  void RemoveObserver(Web3ProviderExtensionObserver* observer);

  void TriggerOnWeb3ProviderChanged(const std::string& extension_id);

 protected:
  base::ObserverList<Web3ProviderExtensionObserver>::Unchecked observers_;
  content::BrowserContext* const browser_context_;
  DISALLOW_COPY_AND_ASSIGN(Web3ProviderExtensionRegistry);
};

}  // namespace extensions

#endif  // BRAVE_EXTENSIONS_BROWSER_WEB3_PROVIDER_EXTENSION_REGISTRY_H_
