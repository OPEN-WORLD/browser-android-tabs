// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENT_EXO_WAYLAND_CLIENTS_TEST_WAYLAND_CLIENT_TEST_H_
#define COMPONENT_EXO_WAYLAND_CLIENTS_TEST_WAYLAND_CLIENT_TEST_H_

#include <memory>

#include "base/macros.h"
#include "base/memory/scoped_refptr.h"
#include "base/single_thread_task_runner.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace ash {
class AshTestHelper;
}  // namespace ash

namespace base {
class ScopedTempDir;
class WaitableEvent;
}  // namespace base

namespace exo {
namespace wayland {
class Server;
}

class Display;
class WMHelper;

class WaylandClientTest : public testing::Test {
 public:
  WaylandClientTest();
  ~WaylandClientTest() override;

  static void SetUIThreadTaskRunner(
      scoped_refptr<base::SingleThreadTaskRunner> ui_thread_task_runner);

 protected:
  // Overridden from testing::Test:
  void SetUp() override;
  void TearDown() override;

 private:
  class WaylandWatcher;

  void SetUpOnUIThread(base::WaitableEvent* event);
  void TearDownOnUIThread(base::WaitableEvent* event);

  // Below objects can only be accessed from UI thread.
  std::unique_ptr<base::ScopedTempDir> xdg_temp_dir_;
  std::unique_ptr<ash::AshTestHelper> ash_test_helper_;
  std::unique_ptr<WMHelper> wm_helper_;
  std::unique_ptr<Display> display_;
  std::unique_ptr<wayland::Server> wayland_server_;
  std::unique_ptr<WaylandWatcher> wayland_watcher_;

  DISALLOW_COPY_AND_ASSIGN(WaylandClientTest);
};

}  // namespace exo

#endif  // COMPONENT_EXO_WAYLAND_CLIENTS_TEST_WAYLAND_CLIENT_TEST_H_
