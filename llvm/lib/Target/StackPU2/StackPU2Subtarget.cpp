//===-- StackPU2Subtarget.cpp - StackPU2 Subtarget Information ------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the StackPU2 specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "StackPU2Subtarget.h"

#include "llvm/BinaryFormat/ELF.h"
#include "llvm/Support/TargetRegistry.h"

#include "StackPU2.h"
#include "StackPU2TargetMachine.h"
#include "MCTargetDesc/StackPU2MCTargetDesc.h"

#define DEBUG_TYPE "stackpu2-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "StackPU2GenSubtargetInfo.inc"

namespace llvm {

StackPU2Subtarget::StackPU2Subtarget(const Triple &TT, const std::string &CPU,
                                     const std::string &FS, const TargetMachine &TM)
    : StackPU2GenSubtargetInfo(TT, CPU, /*TuneCPU*/ CPU, FS),
      FeatureDummy(false) {
  // Parse features string.
  ParseSubtargetFeatures(CPU, /*TuneCPU*/ CPU, FS);
}

} // end of namespace llvm