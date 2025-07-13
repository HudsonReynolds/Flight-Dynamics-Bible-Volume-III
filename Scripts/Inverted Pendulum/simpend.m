clear all, close all, clc

m = 1;
M = 5;
L = 2;
g = -10;
d = 1;

K = [-2.4,-8.75,158,65];
%K = [-1,-2.8,100,60];

ref = [1;0;pi;0];

tspan = 0:.1:10;
y0 = [0; -1; pi; 1];
[t,y] = ode45(@(t,y)pendcart(y,m,M,L,g,d,-K*(y-ref)),tspan,y0);

for k=1:length(t)
    drawpend(y(k,:),m,M,L);
end
