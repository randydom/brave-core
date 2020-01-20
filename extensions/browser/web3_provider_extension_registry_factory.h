/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_EXTENSIONS_BROWSER_WEB3_PROVIDER_EXTENSION_REGISTRY_FACTORY_
#define BRAVE_EXTENSIONS_BROWSER_WEB3_PROVIDER_EXTENSION_REGISTRY_FACTORY_

#include <string>

#include "base/compiler_specific.h"
#include "base/macros.h"
#include "base/memory/singleton.h"
#include "components/keyed_service/content/browser_context_keyed_service_factory.h"

namespace extensions {

class Web3ProviderExtensionRegistry;

class Web3ProviderExtensionRegistryFactory :
    public BrowserContextKeyedServiceFactory {

 public:
  static Web3ProviderExtensionRegistry* GetForBrowserContext(
      content::BrowserContext* context);
  static Web3ProviderExtensionRegistryFactory* GetInstance();

 private:
  friend struct base::DefaultSingletonTraits<Web3ProviderExtensionRegistryFactory>;

  Web3ProviderExtensionRegistryFactory();
  ~Web3ProviderExtensionRegistryFactory() override;

  // BrowserContextKeyedServiceFactory implementation:
  KeyedService* BuildServiceInstanceFor(
      content::BrowserContext* context) const override;
  content::BrowserContext* GetBrowserContextToUse(
      content::BrowserContext* context) const override;

  DISALLOW_COPY_AND_ASSIGN(Web3ProviderExtensionRegistryFactory);
};

}  // namespace extensions

#endif  // BRAVE_EXTENSIONS_BROWSER_WEB3_PROVIDER_EXTENSION_REGISTRY_FACTORY_
