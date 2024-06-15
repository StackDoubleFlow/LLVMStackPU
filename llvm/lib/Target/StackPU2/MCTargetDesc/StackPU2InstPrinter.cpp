//==- StackPU2InstPrinter.cpp - Convert StackPU2 MCInst to assembly syntax -==//

//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This class prints an StackPU2 MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#include "StackPU2InstPrinter.h"

#include "MCTargetDesc/StackPU2MCTargetDesc.h"

#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrDesc.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"

#include <cstring>

#define DEBUG_TYPE "stackpu2-printer"

namespace llvm {

// Include the auto-generated portion of the assembly writer.
#define PRINT_ALIAS_INSTR
#include "StackPU2GenAsmWriter.inc"

void StackPU2InstPrinter::printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
               const MCSubtargetInfo &STI, raw_ostream &O) {
  unsigned Opcode = MI->getOpcode();

  switch (Opcode) {
  default:
    if (!printAliasInstr(MI, Address, O))
      printInstruction(MI, Address, O);

    printAnnotation(O, Annot);
    break;
  }
}

void StackPU2InstPrinter::printOperand(const MCInst *MI, unsigned OpNo,
                                       raw_ostream &O) {
  
}

} // end of namespace llvm