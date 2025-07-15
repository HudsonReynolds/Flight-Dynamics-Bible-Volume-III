function drawpend(state,m,M,L)
x = state(1);
th = state(3);

% dimensions
W = .045;  % cart width
H = .04;   % cart height
mr = .02;  % mass radius

% positions
y = H/2*1.05; % cart vertical position
pendx = x + L*sin(th);
pendy = y - L*cos(th);

plot([-.3 .3],[0 0],'k','LineWidth',2), hold on
rectangle('Position',[x-W/2,y-H/2,W,H],'Curvature',.1,'FaceColor',[.5 0.5 1],'LineWidth',1.5); % Draw cart
plot([x pendx],[y pendy],'k','LineWidth',2); % Draw pendulum
rectangle('Position',[pendx-mr/2,pendy-mr/2,mr,mr],'Curvature',1,'FaceColor',[1 0.1 .1],'LineWidth',1.5);

axis([-.3 .3 -.2 .3]);
axis equal
%set(gcf,'Position',[100 100 1000 400])
drawnow, hold off