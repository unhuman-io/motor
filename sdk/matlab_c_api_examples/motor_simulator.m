% run from sdk/c directory

loadlibrary('libc_api', 'include/motor_c.h')
libfunctions libc_api
p = calllib('libc_api', 'create_motor_simulator')
calllib('libc_api', 'get_message', p)
pause(3)
calllib('libc_api', 'destroy_motor', p)
clear p
unloadlibrary('libc_api')