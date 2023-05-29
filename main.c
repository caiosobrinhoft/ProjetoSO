#include "kernel.h"
#include "menu.h"

int main(){

    mainMenu();
    kernelFunctions func;
    process_t *proc;
    segment *seg;
    sysCall(func, proc, seg);
}