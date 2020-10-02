//===-- StackPU2TargetMachine.cpp - Define TargetMachine for StackPU2 -----===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the StackPU2 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#include "StackPU2TargetMachine.h"
#include "StackPU2.h"
#include "TargetInfo/StackPU2TargetInfo.h"

#include "llvm/Support/TargetRegistry.h"

namespace llvm {

static const char *StackPU2DataLayout = "e-p:16:8";

static Reloc::Model getEffectiveRelocModel(Optional<Reloc::Model> RM) {
  return RM.hasValue() ? *RM : Reloc::Static;
}

StackPU2TargetMachine::StackPU2TargetMachine(const Target &T, const Triple &TT,
                                             StringRef CPU, StringRef FS,
                                             const TargetOptions &Options,
                                             Optional<Reloc::Model> RM,
                                             Optional<CodeModel::Model> CM,
                                             CodeGenOpt::Level OL, bool JIT)
    : LLVMTargetMachine(T, StackPU2DataLayout, TT, CPU, FS, Options,
                        getEffectiveRelocModel(RM),
                        getEffectiveCodeModel(CM, CodeModel::Small), OL),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeStackPU2Target() {
  // Register the target.
  RegisterTargetMachine<StackPU2TargetMachine> X(getTheStackPU2Target());
}

} // end of namespace llvm