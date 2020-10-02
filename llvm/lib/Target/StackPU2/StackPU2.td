//===-- StackPU2.td - Describe the StackPU2 Target Machine -*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// This is the top level entry point for the StackPU2 target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces which we are implementing
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Register File Description
//===----------------------------------------------------------------------===//

include "StackPU2RegisterInfo.td"

//===----------------------------------------------------------------------===//
// Instruction Descriptions
//===----------------------------------------------------------------------===//

include "StackPU2InstrInfo.td"

def StackPU2InstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// Subtarget Features
//===----------------------------------------------------------------------===//

def DummyFeature : SubtargetFeature<"dummy", "FeatureDummy", "true", "Enable dummy feature">;

//===----------------------------------------------------------------------===//
// Processors Supported
//===----------------------------------------------------------------------===//

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"stackpu2",  [DummyFeature]>;

//===----------------------------------------------------------------------===//
// Define the StackPU2 target.
//===----------------------------------------------------------------------===//

def StackPU2 : Target {
    let InstructionSet = StackPU2InstrInfo;
}