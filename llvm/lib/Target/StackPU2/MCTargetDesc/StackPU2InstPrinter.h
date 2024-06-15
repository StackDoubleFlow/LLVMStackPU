//===- StackPU2InstPrinter.h - Convert StackPU2 MCInst to assembly syntax -===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This class prints a StackPU2 MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STACKPU2_INST_PRINTER_H
#define LLVM_STACKPU2_INST_PRINTER_H

#include "llvm/MC/MCInstPrinter.h"

#include "MCTargetDesc/StackPU2MCTargetDesc.h"

namespace llvm {

/// Prints StackPU2 instructions to a textual stream.
class StackPU2InstPrinter : public MCInstPrinter {
public:
  StackPU2InstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                 const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}
  
  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &O) override;

private:
  static const char *getRegisterName(unsigned RegNo);
  
  void printOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);

  // Autogenerated by TableGen.
  void printInstruction(const MCInst *MI, uint64_t Address, raw_ostream &O);
  bool printAliasInstr(const MCInst *MI, uint64_t Address, raw_ostream &O);
  void printCustomAliasOperand(const MCInst *MI, uint64_t Address,
                              unsigned OpIdx, unsigned PrintMethodIdx,
                              raw_ostream &O);
};

} // end namespace llvm

#endif // LLVM_STACKPU2_INST_PRINTER_H