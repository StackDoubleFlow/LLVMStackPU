//==-- StackPU2InstrInfo.td - StackPU2 Instruction Formats --*- tablegen -*-==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===-----------------------------------------------------------------------===//
//
// StackPU2 Instruction Format Definitions.
//
//===-----------------------------------------------------------------------===//

class StackPU2Inst<dag outs, dag ins, string asmstr, list<dag> pattern> : Instruction 
{
    field bits<16> Inst;

    let Namespace = "StackPU2";

    let Size = 4;

    bits<4> Opcode = 0;

    // Top 4 bits are the 'opcode' field
    let Inst{15-12} = Opcode;

    let OutOperandList = outs;
    let InOperandList = ins;

    let AsmString = asmstr;
    let Pattern = pattern;
}

//===----------------------------------------------------------------------===//
// Format A instruction class in StackPU2 : <|opcode|dr|sr1|sr2|>
//===----------------------------------------------------------------------===//

class FA<bits<4> op, dag outs, dag ins, string asmstr, list<dag> pattern> : StackPU2Inst<outs, ins, asmstr, pattern> {
    bits<4> dr;
    bits<4> sr1;
    bits<4> sr2;

    let Opcode = op;

    let Inst{11-8} = dr;
    let Inst{7-4} = sr1;
    let Inst{3-0} = sr2;
}

//===----------------------------------------------------------------------===//
// Format B instruction class in StackPU2 : <|opcode|dr|imm|>
//===----------------------------------------------------------------------===//

class FB<bits<4> op, dag outs, dag ins, string asmstr, list<dag> pattern> : StackPU2Inst<outs, ins, asmstr, pattern> {
    bits<4> dr;
    bits<8> imm;

    let Opcode = op;

    let Inst{11-8} = dr;
    let Inst{7-0} = imm;
}