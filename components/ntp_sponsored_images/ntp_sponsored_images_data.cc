/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/ntp_sponsored_images/ntp_sponsored_images_data.h"

#include "base/logging.h"
#include "brave/components/ntp_sponsored_images/ntp_sponsored_images_internal_data.h"

NTPSponsoredImagesData::NTPSponsoredImagesData() = default;

NTPSponsoredImagesData::NTPSponsoredImagesData(
    const NTPSponsoredImagesInternalData& internal_data) {
  logo_alt_text = internal_data.logo_alt_text;
  logo_destination_url = internal_data.logo_destination_url;
  logo_company_name = internal_data.logo_company_name;
  wallpaper_image_count = internal_data.wallpaper_image_files.size();
}

NTPSponsoredImagesData& NTPSponsoredImagesData::operator=(
    const NTPSponsoredImagesData& data) {
  logo_alt_text = data.logo_alt_text;
  logo_destination_url = data.logo_destination_url;
  logo_company_name = data.logo_company_name;
  wallpaper_image_count = data.wallpaper_image_count;
  return *this;
}

NTPSponsoredImagesData::NTPSponsoredImagesData(
    NTPSponsoredImagesData&& data) = default;

NTPSponsoredImagesData::NTPSponsoredImagesData(
    const NTPSponsoredImagesData& data) = default;
NTPSponsoredImagesData::~NTPSponsoredImagesData() = default;