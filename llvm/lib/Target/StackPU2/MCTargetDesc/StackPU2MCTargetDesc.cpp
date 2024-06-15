
//===-- StackPU2MCTargetDesc.cpp - StackPU2 Target Descriptions ---------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file provides StackPU2 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#include "StackPU2InstPrinter.h"
#include "StackPU2MCTargetDesc.h"
#include "StackPU2MCAsmInfo.h"
#include "TargetInfo/StackPU2TargetInfo.h"

#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_MC_DESC
#include "StackPU2GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "StackPU2GenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "StackPU2GenRegisterInfo.inc"

using namespace llvm;

MCInstrInfo *llvm::createStackPU2MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitStackPU2MCInstrInfo(X);

  return X;
}

static MCRegisterInfo *createStackPU2MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitStackPU2MCRegisterInfo(X, 0);

  return X;
}

static MCInstPrinter *createStackPU2MCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  if (SyntaxVariant == 0) {
    return new StackPU2InstPrinter(MAI, MII, MRI);
  }

  return nullptr;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeStackPU2TargetMC() {
  // Register the MC asm info.
  RegisterMCAsmInfo<StackPU2MCAsmInfo> X(getTheStackPU2Target());

  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(getTheStackPU2Target(), createStackPU2MCInstrInfo);
  
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(getTheStackPU2Target(), createStackPU2MCRegisterInfo);

  // Register the MCInstPrinter.
  TargetRegistry::RegisterMCInstPrinter(getTheStackPU2Target(),
                                        createStackPU2MCInstPrinter);

}