//===-- StackPU2RegisterInfo.td - StackPU2 Register defs ---*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the StackPU2 register file
//===----------------------------------------------------------------------===//

// 8-bit General purpose register definition.
class StackPU2Reg<bits<16> Enc, string n> : Register<n> {
  let HWEncoding = Enc;
  
  let Namespace = "StackPU2";
}

//===----------------------------------------------------------------------===//
// General Purpose Registers
//===----------------------------------------------------------------------===//

def R0  : StackPU2Reg<0,  "r0">,  DwarfRegNum<[0]>;
def R1  : StackPU2Reg<1,  "r1">,  DwarfRegNum<[1]>;
def R2  : StackPU2Reg<2,  "r2">,  DwarfRegNum<[2]>;
def R3  : StackPU2Reg<3,  "r3">,  DwarfRegNum<[3]>;
def R4  : StackPU2Reg<4,  "r4">,  DwarfRegNum<[4]>;
def R5  : StackPU2Reg<5,  "r5">,  DwarfRegNum<[5]>;
def R6  : StackPU2Reg<6,  "r6">,  DwarfRegNum<[6]>;
def R7  : StackPU2Reg<7,  "r7">,  DwarfRegNum<[7]>;
def R8  : StackPU2Reg<8,  "r8">,  DwarfRegNum<[8]>;
def R9  : StackPU2Reg<9,  "r9">,  DwarfRegNum<[9]>;
def R10 : StackPU2Reg<10, "r10">, DwarfRegNum<[10]>;
def R11 : StackPU2Reg<11, "r11">, DwarfRegNum<[11]>;
def R12 : StackPU2Reg<12, "r12">, DwarfRegNum<[12]>;
def R13 : StackPU2Reg<13, "r13">, DwarfRegNum<[13]>;
def R14 : StackPU2Reg<14, "r14">, DwarfRegNum<[14]>;
def R15 : StackPU2Reg<15, "r15">, DwarfRegNum<[15]>;

def GPR : RegisterClass<"StackPU2", [i8], 8, (
    add R0, R1, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15
)>;

//===----------------------------------------------------------------------===//
// Special Registers
//===----------------------------------------------------------------------===//

def S0 : StackPU2Reg<0, "s0">, DwarfRegNum<[16]>;
def S1 : StackPU2Reg<1, "s1">, DwarfRegNum<[17]>;
def S2 : StackPU2Reg<2, "s2">, DwarfRegNum<[18]>;
def S3 : StackPU2Reg<3, "s3">, DwarfRegNum<[19]>;
def S4 : StackPU2Reg<4, "s4">, DwarfRegNum<[20]>;
def S5 : StackPU2Reg<5, "s5">, DwarfRegNum<[21]>;
def S6 : StackPU2Reg<5, "s5">, DwarfRegNum<[22]>;

def SR : RegisterClass<"StackPU2", [i8], 8, (
    add S0, S1, S2, S3, S4, S5, S6
)>;