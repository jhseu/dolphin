// Copyright 2017 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <thread>

#include <QObject>

#include "Common/Flag.h"

class HotkeyScheduler : public QObject
{
  Q_OBJECT
public:
  explicit HotkeyScheduler();
  ~HotkeyScheduler();

  void Start();
  void Stop();
signals:
  void Open();
  void EjectDisc();
  void ChangeDisc();

  void ExitHotkey();
  void FullScreenHotkey();
  void StopHotkey();
  void ResetHotkey();
  void TogglePauseHotkey();
  void ScreenShotHotkey();
  void RefreshGameListHotkey();
  void SetStateSlotHotkey(int slot);
  void StateLoadSlotHotkey();
  void StateSaveSlotHotkey();
  void StateLoadSlot(int state);
  void StateSaveSlot(int state);
  void StateLoadLastSaved(int state);
  void StateSaveOldest();
  void StateLoadUndo();
  void StateSaveUndo();
  void StartRecording();
  void ExportRecording();
  void ToggleReadOnlyMode();
  void ConnectWiiRemote(int id);

  void Step();
  void StepOver();
  void StepOut();
  void Skip();

  void ShowPC();
  void SetPC();

  void ToggleBreakpoint();
  void AddBreakpoint();

private:
  void Run();
  void CheckDebuggingHotkeys();

  Common::Flag m_stop_requested;
  std::thread m_thread;
};
