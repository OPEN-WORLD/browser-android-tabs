// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_SERVICES_PATCH_PUBLIC_CPP_PATCH_H_
#define COMPONENTS_SERVICES_PATCH_PUBLIC_CPP_PATCH_H_

#include <string>

#include "base/callback_forward.h"

namespace base {
class FilePath;
}

namespace service_manager {
class Connector;
}

namespace patch {

// Patches |input_abs_path| with |patch_abs_path| using the |operation|
// algorithm and place the output in |output_abs_path|.
using PatchCallback = base::OnceCallback<void(int result)>;
void Patch(service_manager::Connector* connector,
           const std::string& operation,
           const base::FilePath& input_abs_path,
           const base::FilePath& patch_abs_path,
           const base::FilePath& output_abs_path,
           PatchCallback callback);

}  // namespace patch

#endif  // COMPONENTS_SERVICES_PATCH_PUBLIC_CPP_PATCH_H_
