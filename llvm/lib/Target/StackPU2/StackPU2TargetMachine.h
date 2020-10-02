//=-- StackPU2TargetMachine.h - Define TargetMachine for StackPU2 -*- C++ -*-=//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the STACKPU2 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STACKPU2_TARGET_MACHINE_H
#define LLVM_STACKPU2_TARGET_MACHINE_H

#include "StackPU2Subtarget.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

/// A generic StackPU2 implementation.
class StackPU2TargetMachine : public LLVMTargetMachine {
  StackPU2Subtarget Subtarget;
public:
  StackPU2TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                        StringRef FS, const TargetOptions &Options,
                        Optional<Reloc::Model> RM,
                        Optional<CodeModel::Model> CM,
                        CodeGenOpt::Level OL, bool JIT);

};

}

#endif // LLVM_STACKPU2_TARGET_MACHINE_H