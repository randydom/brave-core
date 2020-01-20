/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/extensions/browser/web3_provider_extension_registry.h"

#include "brave/extensions/browser/web3_provider_extension_observer.h"
#include "brave/extensions/browser/web3_provider_extension_registry_factory.h"

namespace extensions {

Web3ProviderExtensionRegistry::Web3ProviderExtensionRegistry(
        content::BrowserContext* browser_context) :
    browser_context_(browser_context) {
}
Web3ProviderExtensionRegistry::~Web3ProviderExtensionRegistry() {
}

// static
Web3ProviderExtensionRegistry* Web3ProviderExtensionRegistry::Get(
    content::BrowserContext* context) {
  return Web3ProviderExtensionRegistryFactory::GetForBrowserContext(context);
}

void Web3ProviderExtensionRegistry::AddObserver(
    Web3ProviderExtensionObserver* observer) {
  observers_.AddObserver(observer);
}

void Web3ProviderExtensionRegistry::RemoveObserver(
    Web3ProviderExtensionObserver* observer) {
  observers_.RemoveObserver(observer);
}

void Web3ProviderExtensionRegistry::TriggerOnWeb3ProviderChanged(
    const std::string& extension_id) {
  for (auto& observer : observers_)
    observer.OnWeb3ProviderChanged(extension_id);
}

}  // namespace extensions
