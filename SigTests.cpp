/** This is to research the behavior of IEEE754 Floating Pointer
  * exceptions under various conditions. This is the result:
  * (1) When floating point traps are not enabled - fedisableexcept() -
  *     the program can safely continue, and flags can be checked to 
  *     determine any errors. This is the default, and this is used
  *     by the CppUTest plugin, in order to report arithmetic errors.
  * (2) When floating point traps are enabled - feenableexcept() -
  *     the program will crash with SIGFPE. This can be used for
  *     debugging. However, the program cannot be safely continued
  *     (e.g. by a signal handler). A signal handler could print out
  *     additional information, but would ultimately have to abort
  *     program execution.
  * (3) With floating point traps enabled, it is possible to simply
  *     ignore the signal and to just check the flags, e.g. with:
  *     signal(SIGFPE, SIG_IGN). The reason is that this amounts to
  *     the same as specifying an empty handler; program execution
  *     will continue, but it is not save and the program is bound
  *     to crash rather sooner than later.
  *
  *  Crashes are evident in this example program by the last line not
  *  printing, when it should have printed.
  */
#include <signal.h>
#include <cfenv>
#include <iostream>

using std::cout;

//#define SIGNAL_SHOULD_BE_HANDLED_BY_HANDLER
//#define SIGNAL_SHOULD_BE_IGNORED

#ifdef SIGNAL_SHOULD_BE_HANDLED_BY_HANDLER
static void sig_handler(int) 
{
    cout << "This prints when SIGFPE is handled.\n";
    cout.flush();
}
#endif

int main() {
    std::feclearexcept(FE_ALL_EXCEPT);
    feenableexcept (FE_ALL_EXCEPT);
    
#if defined(SIGNAL_SHOULD_BE_HANDLED_BY_HANDLER)
    signal(SIGFPE, sig_handler);
#elif defined (SIGNAL_SHOULD_BE_IGNORED)
    signal(SIGFPE, SIG_IGN);
#endif
    
    float a = 1, b = 0;
    a = a/b;

    cout << "This prints when SIGFPE is ignored or handled.\n";

	return 0;
}
