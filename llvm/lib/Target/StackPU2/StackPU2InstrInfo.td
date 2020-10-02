//===-- StackPU2InstrInfo.td - StackPU2 Instruction defs -- *- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the StackPU2 instructions in TableGen format.
//
//===----------------------------------------------------------------------===//

include "StackPU2InstrFormats.td"

class ALU_rr<bits<4> opcode, string opcodestr, SDNode OpNode>
    : FA<1, (outs GPR:$dr), (ins GPR:$sr1, GPR:$sr2), !strconcat(opcodestr, "\t$dr, $sr1, $sr2"), [(set GPR:$dr, (OpNode GPR:$sr1, GPR:$sr2))]>;

def ADD : ALU_rr<1, "add", add>;