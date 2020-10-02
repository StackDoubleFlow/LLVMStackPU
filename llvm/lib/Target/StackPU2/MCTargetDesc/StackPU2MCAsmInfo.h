//===-- StackPU2MCAsmInfo.h - StackPU2 asm properties -----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the StackPU2MCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STACKPU2_ASM_INFO_H
#define LLVM_STACKPU2_ASM_INFO_H

#include "llvm/MC/MCAsmInfo.h"

namespace llvm {

class Triple;

/// Specifies the format of StackPU2 assembly files.
class StackPU2MCAsmInfo : public MCAsmInfo {
public:
  explicit StackPU2MCAsmInfo(const Triple &TT, const MCTargetOptions &Options);
};

} // end namespace llvm

#endif // LLVM_STACKPU2_ASM_INFO_H