#pragma once

#include "IPlug_include_in_plug_hdr.h"
#include "ISender.h"

const int kNumPresets = 1;


enum EParams
{
  kGain = 0,
  kNumParams
};

enum ECtrlTags { kCtrlTagMeter = 0, kNumCtrlTags };

using namespace iplug;
using namespace igraphics;

class MyNewPlugin final : public Plugin
{
public:
  MyNewPlugin(const InstanceInfo& info);
  void OnIdle() override;

#if IPLUG_DSP // http://bit.ly/2S64BDd
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
#endif

private:
	IPeakSender<2> mMeterSender = {};
};
