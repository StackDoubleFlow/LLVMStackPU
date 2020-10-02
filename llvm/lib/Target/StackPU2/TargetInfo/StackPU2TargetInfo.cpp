//===-- StackPU2.cpp - StackPU2 Target Implementation ---------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "TargetInfo/StackPU2TargetInfo.h"
#include "llvm/Support/TargetRegistry.h"
namespace llvm {
Target &getTheStackPU2Target() {
  static Target TheStackPU2Target;
  return TheStackPU2Target;
}
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeStackPU2TargetInfo() {
  llvm::RegisterTarget<llvm::Triple::stackpu2> X(llvm::getTheStackPU2Target(), "stackpu2",
                                            "StackDoubleFlow Processing Unit 2", "StackPU2");
}

