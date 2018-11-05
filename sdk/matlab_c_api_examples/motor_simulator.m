% run from sdk/c directory

loadlibrary('libc_api', 'include/motor_c.h')
libfunctions libc_api
p = calllib('libc_api', 'create_motor_simulator')

% construct a Message to send
m.type = 1;
m.length = 12;
c.type = uint16(1);
d.i_d = single(0);
d.i_q = single(1.5);
c.data = [d.i_d, d.i_q];
m.data = [c.type, c.data];
message = libstruct('Message', m);

calllib('libc_api', 'send_message', p, message);

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
clear p m message
unloadlibrary('libc_api')