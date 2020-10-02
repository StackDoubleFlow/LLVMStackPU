//===-- StackPU2.h - Top-level interface for StackPU2 Target ----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in the LLVM
// AVR back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_STACKPU2_STACKPU2_H
#define LLVM_LIB_TARGET_STACKPU2_STACKPU2_H

#include "MCTargetDesc/StackPU2MCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
    class STACKPU2TargetMachine;
    
} // end namespace llvm

#endif