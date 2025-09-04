clear; close all; clc;

%% --- Pendulum-Cart Parameters -----------------------------------------
m = 0.071;     % pendulum mass [kg]
M = 0.408;     % cart mass [kg]
l = 0.6096;    % pendulum length [m]
g = -9.81;     % gravity [m/s^2]
d = 0.1;       % cart damping coefficient [N·s/m]
I = (1/3) * m * l^2; % pendulum inertia [kg·m^2]

%% --- Motor + Gear Parameters ------------------------------------------
N = 6.25;      % gear ratio (motor_speed / wheel_speed)
rw = 0.03;     % wheel radius [m]

% Motor constants (motor side)
Jm_motor = 1e-5;       % rotor inertia [kg*m^2]
b_motor  = 1e-5;       % viscous friction [N*m*s/rad]
L  = 0.001;            % armature inductance [H]
R  = 2;                % armature resistance [ohm]
kt_motor = 0.01222;    % motor torque constant [N*m/A] (motor shaft)
ke_motor = kt_motor;   % back-EMF constant [V*s/rad]

% Refer motor parameters to wheel/cart output shaft
Jm = Jm_motor * N^2;     % kg*m^2
b  = b_motor * N^2;      % N*m*s/rad
kt = kt_motor * N;       % N*m/A at wheel
ke = ke_motor * N;       % V*s/rad at wheel

% Motor TF from voltage -> torque at wheel
num = [kt, kt*b];
den = [Jm*L, (Jm*R + b*L), (b*R + kt*ke)];

%% --- Linearized Pendulum-Cart (Force Input) ---------------------------
delta = I*(M+m) - (m*l)^2;

A_p = [0      1              0                 0;
       0 -d*(I+m*l^2)/delta  (m^2*g*l^2)/delta  0;
       0      0              0                 1;
       0 -m*l*d/delta        m*g*l*(M+m)/delta  0];

B_p = [0;
       (I+m*l^2)/delta;
       0;
       m*l/delta];

C_p = [1 0 0 0;
       0 0 1 0];

Plant_ss = ss(A_p, B_p, C_p, 0);

%% --- Actuator State-Space (Voltage -> Force) --------------------------
[Am,Bm,Cm,Dm] = tf2ss(num, den); % torque at wheel
Cm_force = Cm / rw;              % convert torque -> force
Dm_force = Dm / rw;

%% --- Augment Motor and Plant ------------------------------------------
% States: [motor_states; plant_states]
A_aug = [Am,                 zeros(size(Am,1), size(A_p,1));
         B_p*Cm_force,       A_p];
B_aug = [Bm;
         B_p*Dm_force];
C_aug = [zeros(size(C_p,1), size(Am,1)), C_p];
D_aug = zeros(size(C_p,1), 1);

Full_sys = ss(A_aug, B_aug, C_aug, D_aug);

%% --- LQR Design --------------------------------------------------------
% Q for [i, omega_wheel, x, x_dot, theta, theta_dot]
Q_aug = diag([0.01, 0.01, 1, 1, 3, 5]);
R_aug = 20;

K_aug = lqr(Full_sys.A, Full_sys.B, Q_aug, R_aug);

%% --- Simulation --------------------------------------------------------
% Reference (all states) [i, omega_w, x, x_dot, theta, theta_dot]
ref = [0; 0; 0; 0; pi; 0];

% Initial condition (slightly perturbed theta)
x0 = [0; 0; 0; 0; pi+0.05; 0];

tspan = 0:0.01:4;
[t, X] = ode45(@(t,X)pendcart(X,m,M,l,g,d,-K_aug*(X-ref)),tspan,x0);

% Extract cart position and pendulum angle for plotting
cart_pos = X(:,3);
theta    = X(:,5);

figure;
subplot(2,1,1);
plot(t, cart_pos);
ylabel('Cart Position (m)');
grid on;

subplot(2,1,2);
plot(t, theta);
ylabel('Pendulum Angle (rad)');
xlabel('Time (s)');
grid on;
