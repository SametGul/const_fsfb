
figure('Renderer', 'painters', 'Position', [10 10 900 300]);
plot(ErrorsFromScope.time, ErrorsFromScope.signals(2).values(:,1));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$e_1(t)$[deg]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
%grid minor;
%saveas(gcf,'error1_10deg','epsc')
%saveas(gcf,'error1_5deg','epsc')
%saveas(gcf,'error1_3deg','epsc')

figure('Renderer', 'painters', 'Position', [10 10 900 300]);
plot(ErrorsFromScope.time, ErrorsFromScope.signals(2).values(:,2)); 
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$e_2(t)$[deg]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
%grid minor;
%saveas(gcf,'error2_10deg','epsc')
%saveas(gcf,'error2_5deg','epsc')
%saveas(gcf,'error2_3deg','epsc')



figure(3);
plot(ParamsFromScope.time, ParamsFromScope.signals.values);
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("Parameter Updates",'interpreter','latex');
set(l,'FontSize',17);
grid on;
%grid minor;
%saveas(gcf,'param10deg','epsc')
%saveas(gcf,'param5deg','epsc')
%saveas(gcf,'param3deg','epsc')



figure(4);
subplot 211;
plot(InputsFromScope.time, InputsFromScope.signals.values(:,1));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$\tau_1(t)$[Nt.m]",'interpreter','latex');
set(l,'FontSize',17);
grid on;
%grid minor;

subplot 212;
plot(InputsFromScope.time, InputsFromScope.signals.values(:,2));
l = xlabel("Time[sec]",'interpreter','latex');
set(l,'FontSize',17);
l = ylabel("$\tau_2(t)$[Nt.m]",'interpreter','latex');
set(l,'FontSize',17);
ylim([-5 5])
grid on;
%grid minor;
%saveas(gcf,'tau10deg','epsc')
%saveas(gcf,'tau5deg','epsc')
%saveas(gcf,'tau3deg','epsc')
