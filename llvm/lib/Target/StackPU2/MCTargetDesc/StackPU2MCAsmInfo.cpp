//===-- StackPU2MCAsmInfo.cpp - StackPU2 asm properties -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the StackPU2MCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "StackPU2MCAsmInfo.h"

#include "llvm/ADT/Triple.h"

namespace llvm {

StackPU2MCAsmInfo::StackPU2MCAsmInfo(const Triple &TT, const MCTargetOptions &Options) {
  CodePointerSize = 2;
  CalleeSaveStackSlotSize = 2;
  CommentString = ";";
  PrivateGlobalPrefix = ".L";
  PrivateLabelPrefix = ".L";
  UsesELFSectionDirectiveForBSS = true;
  SupportsDebugInformation = true;
}

} // end of namespace llvm