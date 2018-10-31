% run from sdk/c directory

loadlibrary('libc_api', 'include/motor_c.h')
libfunctions libc_api
p = calllib('libc_api', 'create_motor')
calllib('libc_api', 'get_message', p)
calllib('libc_api', 'destroy_motor', p)
clear p
unloadlibrary('libc_api')