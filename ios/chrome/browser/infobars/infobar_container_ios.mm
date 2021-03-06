// Copyright 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ios/chrome/browser/infobars/infobar_container_ios.h"

#include "ios/chrome/browser/infobars/infobar.h"
#import "ios/chrome/browser/ui/infobars/infobar_container_consumer.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

InfoBarContainerIOS::InfoBarContainerIOS(id<InfobarContainerConsumer> consumer)
    : InfoBarContainer(nullptr), consumer_(consumer) {}

InfoBarContainerIOS::~InfoBarContainerIOS() {
  RemoveAllInfoBarsForDestruction();
}

void InfoBarContainerIOS::PlatformSpecificAddInfoBar(infobars::InfoBar* infobar,
                                                     size_t position) {
  InfoBarIOS* infobar_ios = static_cast<InfoBarIOS*>(infobar);
  [consumer_ addInfoBarWithDelegate:infobar_ios->InfobarUIDelegate()
                           position:position];
}

void InfoBarContainerIOS::PlatformSpecificRemoveInfoBar(
    infobars::InfoBar* infobar) {
  InfoBarIOS* infobar_ios = static_cast<InfoBarIOS*>(infobar);
  infobar_ios->RemoveView();
}

void InfoBarContainerIOS::PlatformSpecificInfoBarStateChanged(
    bool is_animating) {
  [consumer_ setUserInteractionEnabled:!is_animating];
}
