//===-- StackPU2MCTargetDesc.h - StackPU2 Target Descriptions ---*- C++ -*-===//
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

#ifndef LLVM_STACKPU2_MCTARGET_DESC_H
#define LLVM_STACKPU2_MCTARGET_DESC_H

namespace llvm {
class Target;

}

#define GET_REGINFO_ENUM
#include "StackPU2GenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "StackPU2GenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "StackPU2GenSubtargetInfo.inc"

#endif // LLVM_StackPU2_MCTARGET_DESC_H