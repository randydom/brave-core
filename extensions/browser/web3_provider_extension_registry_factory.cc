/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/extensions/browser/web3_provider_extension_registry_factory.h"

#include "brave/extensions/browser/web3_provider_extension_registry.h"
#include "components/keyed_service/content/browser_context_dependency_manager.h"
#include "extensions/browser/extensions_browser_client.h"

using content::BrowserContext;

namespace extensions {

// static
Web3ProviderExtensionRegistry* Web3ProviderExtensionRegistryFactory::GetForBrowserContext(
    BrowserContext* context) {
  return static_cast<Web3ProviderExtensionRegistry*>(
      GetInstance()->GetServiceForBrowserContext(context, true));
}

// static
Web3ProviderExtensionRegistryFactory* Web3ProviderExtensionRegistryFactory::GetInstance() {
  return base::Singleton<Web3ProviderExtensionRegistryFactory>::get();
}

Web3ProviderExtensionRegistryFactory::Web3ProviderExtensionRegistryFactory()
    : BrowserContextKeyedServiceFactory(
          "Web3ProviderExtensionRegistry",
          BrowserContextDependencyManager::GetInstance()) {
  // No dependencies on other services.
}

Web3ProviderExtensionRegistryFactory::~Web3ProviderExtensionRegistryFactory() {}

KeyedService* Web3ProviderExtensionRegistryFactory::BuildServiceInstanceFor(
    content::BrowserContext* context) const {
  return new Web3ProviderExtensionRegistry(context);
}

BrowserContext* Web3ProviderExtensionRegistryFactory::GetBrowserContextToUse(
    BrowserContext* context) const {
  // Redirected in incognito.
  auto* extension_browser_client = ExtensionsBrowserClient::Get();
  DCHECK(extension_browser_client);
  return extension_browser_client->GetOriginalContext(context);
}

}  // namespace extensions

