
figure(1);
subplot(2,6,1);
te1 = 20000;
err1 = ErrorsFromScope.signals(2).values(:,1);
plot(ErrorsFromScope.time(1:te1), err1(1:te1));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$e_1(t)$[deg]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;
subplot(2,6,[2,6]);
plot(ErrorsFromScope.time(te1+1:end), err1(te1+1:end));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;

subplot(2,6,7);
err2 = ErrorsFromScope.signals(2).values(:,2);
te2 = 20000;
plot(ErrorsFromScope.time(1:te2), err2(1:te2)); 
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$e_2(t)$[deg]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;
subplot(2,6,[8 9 10 11 12]);
plot(ErrorsFromScope.time(te2+1:end), err2(te2+1:end));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;
%saveas(gcf,'errors10deg','epsc')
%saveas(gcf,'errors5deg','epsc')
%saveas(gcf,'errors3deg','epsc')



figure(2);
plot(ParamsFromScope.time, ParamsFromScope.signals.values);
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("Parameter Updates",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;
%saveas(gcf,'param10deg','epsc')
%saveas(gcf,'param5deg','epsc')
%saveas(gcf,'param3deg','epsc')



figure(3);
subplot(2,7,1);
te3 = 4000;
tau1 = InputsFromScope.signals.values(:,1);
plot(InputsFromScope.time(1:te3), tau1(1:te3));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$\tau_1(t)$[Nt.m]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;
subplot(2,7,[2 3 4 5 6 7]);
plot(InputsFromScope.time(te3+1:end), tau1(te3+1:end));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;

subplot(2,7,8);
tau2 = InputsFromScope.signals.values(:,2);
plot(InputsFromScope.time(1:te3), tau2(1:te3));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$\tau_2(t)$[Nt.m]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;
subplot(2,7,[9 10 11 12 13 14]);
plot(InputsFromScope.time(te3+1:end), tau2(te3+1:end));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;
%saveas(gcf,'tau10deg','epsc')
%saveas(gcf,'tau5deg','epsc')
%saveas(gcf,'tau3deg','epsc')



figure(4);
subplot 211
plot(qdesFromScope.time, qdesFromScope.signals.values(:,1));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$q_{d1}(t)$",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;

subplot 212
plot(qdesFromScope.time, qdesFromScope.signals.values(:,2));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$q_{d2}(t)$",'interpreter','latex');
set(l,'FontSize',17);
grid on;
grid minor;
%saveas(gcf,'qd10deg','epsc')
%saveas(gcf,'qd5deg','epsc')
%saveas(gcf,'qd3deg','epsc')

