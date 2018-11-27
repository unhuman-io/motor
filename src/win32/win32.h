#define gmtime_r(x,y) gmtime_s(y,x)

#define INIT_TERMINAL { HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); \
                        DWORD old_mode; \
                        GetConsoleMode(hStdout, &old_mode); \
                        SetConsoleMode(hStdout, old_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING); }