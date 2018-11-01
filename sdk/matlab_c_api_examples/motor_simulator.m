% run from sdk/c directory

loadlibrary('libc_api', 'include/motor_c.h')
libfunctions libc_api
p = calllib('libc_api', 'create_motor_simulator')
figure(1)
position = zeros(100,1);
h = plot(position);
for i=1:1000
    position = circshift(position, -1);
    position(end) = calllib('libc_api', 'get_message', p);
    pause(0.001)
    set(h, 'ydata', position);
%   drawnow
end
calllib('libc_api', 'destroy_motor', p)
clear p
unloadlibrary('libc_api')