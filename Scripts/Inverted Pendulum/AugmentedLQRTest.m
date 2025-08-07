%% Physical constants
M = 0.5;        % kg (cart mass)
m = 0.1;        % kg (pendulum mass)
L = 0.16;        % m (pendulum length to COM)
g = -9.81;       % m/s^2
I = m*L^2/3;      % kg*m^2 (pendulum inertia)

% Motor parameters (example: replace with measured values)
R = 9.6;        % Ohm
L_m = 0.005;    % H
k_t = 0.43;     % Nm/A (torque constant)
k_e = 0.43;     % V*s/rad (back EMF constant)
G = 18.8;       % gear ratio
r_eff = 6/1000; % m (effective wheel radius)

%% Derived quantities
delta = I*(M + m) - (m*L)^2;
alpha = (k_t * G) / r_eff;                   % F = alpha * i
gamma = (k_e * G) / (L_m * r_eff);           % back EMF influence on di/dt

%% Original system matrices
A = [0   1          0                0;
     0   0   (m*L)^2*-g/delta        0;
     0   0          0                1;
     0   0   m*L*(M*-g+m*-g)/delta   0];


B = [ 0;
      I/delta;
      0;
      m*L/delta ];

%% Augment for motor current i
A_aug = [A              B * alpha;
         0, -gamma, 0, 0,   -R/L_m];

B_aug = [zeros(4,1); 1/L_m];

%% Define LQR cost (tune as needed)
Q = diag([100, 1, 100, 1, 0.1]);   % states: x, dx, theta, dtheta, i
R_lqr = 0.01;                      % voltage penalty

%% Compute LQR gain
K = lqr(A_aug, B_aug, Q, R_lqr);

%% Display gain
disp('LQR gain (for V input):');
disp(K);
