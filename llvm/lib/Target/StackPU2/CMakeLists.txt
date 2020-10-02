set(LLVM_TARGET_DEFINITIONS StackPU2.td)

tablegen(LLVM StackPU2GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM StackPU2GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM StackPU2GenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM StackPU2GenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(StackPU2CommonTableGen)

add_llvm_target(StackPU2CodeGen
  StackPU2TargetMachine.cpp
  StackPU2Subtarget.cpp
  StackPU2TargetObjectFile.cpp
  StackPU2AsmPrinter.cpp
  StackPU2MCInstLower.cpp
  )

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)