//===-- StackPU2AsmPrinter.cpp - StackPU2 LLVM assembly writer ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to GAS-format StackPU2 assembly language.
//
//===----------------------------------------------------------------------===//

#include "StackPU2.h"
#include "StackPU2MCInstLower.h"
#include "TargetInfo/StackPU2TargetInfo.h"

#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"
#include "llvm/Support/TargetRegistry.h"

namespace llvm {

/// A StackPU2 assembly code printer.
class StackPU2AsmPrinter : public AsmPrinter {
public:
  StackPU2AsmPrinter(TargetMachine &TM,
                std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)), MRI(*TM.getMCRegisterInfo()) { }
  
  StringRef getPassName() const override { return "StackPU2 Assembly Printer"; }

  void emitInstruction(const MachineInstr *MI) override;
private:
  const MCRegisterInfo &MRI;
};

void StackPU2AsmPrinter::emitInstruction(const MachineInstr *MI) {
  StackPU2MCInstLower MCInstLowering(OutContext, *this);

  MCInst I;
  MCInstLowering.lowerInstruction(*MI, I);
  EmitToStreamer(*OutStreamer, I);
}

} // end of namespace llvm

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeStackPU2AsmPrinter() {
  llvm::RegisterAsmPrinter<llvm::StackPU2AsmPrinter> X(llvm::getTheStackPU2Target());
}
