clear; close all; clc;

% --- Model the Parameters of the Cart ---------------------------------------

m = 0.0258; % mass of the pendulum arm (71 g for wood, 25.8 g for CF)
m2 = 0.0; % mass of the steel endcap of the pendulum (63.2 g)
M = 0.408; % mass of the cart (408 g)
l = 0.16; % length of pendulum arm (.16m for CF, 0.6096m for Wood)
g = -9.81; % gravity
d = .1; % damping coefficent
I = (1/3) * m * l^2 + m2*l^2; % Moment of inertia for the pendulum
m = m + m2; % set the mass of the arm to the combined mass

% --- Model the Parameters of the Motor -------------------------------------

Jm = 1e-5;        % rotor inertia [kg*m^2]
b  = 1e-5;        % viscous friction [N*m*s/rad]
L  = 0.001;       % motor inductance [H]
R  = 5;           % motor resistance [Ω]
k = 0.075;        % motor constant [N*m/A or V*s/rad]
r = 6.2/1000;     % motor pulley radius [m]

num = [k, k*b];
den = [Jm*L, (Jm*R + b*L), (b*R + k^2)];

G_motor = tf(num, den);

% --- Build the LQR state space --------------------------------------------

% define the denominator
delta = I * (M+m) - (m*l)^2;

% define the linearized control system
A = [0   1          0                0;
     0   0   (m*l)^2*-g/delta        0;
     0   0          0                1;
     0   0   m*l*(M*-g+m*-g)/delta   0];

B = [0; I/delta;0;m*l/delta];

C = [1 0 0 0;0 0 1 0];

% Create the state-space representation
Plant_sys = ss(A, B, C, 0);

% define the Q and R gains, prioritize position centering and keep actuation
% somewhat low (300 mm/s max speed)
Q = diag([65; ...  % position
          1; ...  % velocity
          2000; ... % angle
          10]);    % angular rate

R = 0.005;           % control actuation penalty

K = lqr(Plant_sys,Q,R);

K = [-31.6228	-28.236   131.5243	11.773];

% define the goal position, pointing straight up with no velocity and
% centered on the track
ref = [0;0;pi;0];

% --- ODE 45 Simulation ----------------------------------------------------
tspan = 0:.1:4;
y0 = [0; 0; pi+.1; 0];
[t,y] = ode45(@(t,y)pendcart(y,m,M,l,g,d,-K*(y-ref)),tspan,y0);

for idx = 1:numel(t)
    [~, V(idx,1),u(idx)] = pendcart(y(idx,:),m,M,l,g,d,-K*(y(idx,:)'-ref));
end

% --- Plotting -------------------------------------------------------------

for idx=1:length(t)
    drawpend(y(idx,:),m,M,l);
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
plot(t, u*r)
xlabel('Time (s)');
ylabel('Voltage (V) and Control Torque (Nm)');
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