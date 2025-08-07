s = tf('s');

J = 1e-4;   
b = 1e-3;
L = 1e-3;
R = 9.8;
k = 24/55.5;

numerator = k*(J*s + b);
denominator = (J*s + b)*(L*s + R) + k^2;

T_over_V = numerator / denominator;

step(T_over_V)   % Step response of torque to input voltage
