clear; close all; clc;

m = 0.08; % mass of the pendulum arm (80 g for wood, 28g for CF)
M = 0.408; % mass of the cart (408 g)
L = .9144; % length of pendulum arm (.16m for CF, 0.9144m for Wood)
g = -9.81; % gravity
d = .1; % damping coefficent
I = (1/3) * m * L^2; % Moment of inertia for the pendulum

% define the denominator
delta = I * (M+m) - (m*L)^2;

% define the linearized control system
A = [0   1          0                0;
     0   0   (m*L)^2*-g/delta        0;
     0   0          0                1;
     0   0   m*L*(M*-g+m*-g)/delta   0];

B = [0; I/delta;0;m*L/delta];

C = [1 0 0 0;0 0 1 0];


% Create the state-space representation
sys = ss(A, B, C, 0);

sysd = c2d(sys, 0.01)

% define the Q and R gains, prioritize position centering and keep actuation
% somewhat low (300 mm/s max speed)
Q = diag([1;1;3;5]);
R = 20;

K = lqr(sys,Q,R);

Kd = dlqr(sysd.A, sysd.B, Q,R);

% define the goal position, pointing straight up with no velocity and
% centered on the track
ref = [0;0;pi;0];

% simulate in ODE45:
tspan = 0:.1:4;
y0 = [0; 0; pi+.05; 0];
[t,y] = ode45(@(t,y)pendcart(y,m,M,L,g,d,-Kd*(y-ref)),tspan,y0);

for k = 1:numel(t)
    [~, V(k,1),u(k)] = pendcart(y(k,:),m,M,L,g,d,-K*(y(k,:)'-ref));
end

% draw a pretty picture
for k=1:length(t)
    drawpend(y(k,:),m,M,L);
end

% Plot the position and velocity over time:
figure(2)
subplot(2,1,1)
plot(t, y(:,1)); % Plot the cart position (x)
xlabel('Time (s)');
ylabel('Position [m]');
title('Cart Position over Time');
grid on;

subplot(2,1,2)
plot(t, y(:,2)*1000);
xlabel('Time (s)');
ylabel('Velocity [mm/s]');
title('Cart Velocity over Time');
grid on;


figure(3)
% Plot the motor voltage and control input over time:
plot(t, V);
hold on
plot(t, u)
xlabel('Time (s)');
ylabel('Voltage (V) and Control Input (N)');
title('Voltage over Time');
legend('Voltage', 'Control Input')
grid on;

figure(4)
% Plot the angle and angular rate over time:
subplot(2,1,1);
plot(t, y(:,3)); % Plot the angle (theta)
xlabel('Time (s)');
ylabel('Angle (rad)');
title('Pendulum Angle over Time');
grid on;
subplot(2,1,2)
plot(t, y(:,4)); % Plot the angular rate (theta dot)
xlabel('Time (s)');
ylabel('Angular Rate (rad/s)');
title('Pendulum Angular Rate over Time');
grid on;