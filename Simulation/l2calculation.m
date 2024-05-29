%Tau1 L2 calculations

tau1_0to20           = InputsFromScope.signals.values(1:20000,1);
tau1_0to20_Square    = tau1_0to20 .* tau1_0to20;

sum_tau1_0to20_Square = 0;

for c = 1:length(tau1_0to20_Square)
   sum_tau1_0to20_Square = sum_tau1_0to20_Square+tau1_0to20_Square(c);
end

L2_unstable_tau1 = sqrt(sum_tau1_0to20_Square)


tau1_70to80 = InputsFromScope.signals.values(70001:80000,1);
tau1_70to80_Square   = tau1_70to80.*tau1_70to80;

sum_tau1_70to80_Square = 0;

for c = 1:length(tau1_70to80_Square)
   sum_tau1_70to80_Square = sum_tau1_70to80_Square+tau1_70to80_Square(c);
end

L2_stable_tau1 = sqrt(sum_tau1_70to80_Square)


%Tau2 L2 calculations

tau2_0to20           = InputsFromScope.signals.values(1:20000,2);
tau2_0to20_Square    = tau2_0to20 .* tau2_0to20;

sum_tau2_0to20_Square = 0;

for c = 1:length(tau2_0to20_Square)
   sum_tau2_0to20_Square = sum_tau2_0to20_Square+tau2_0to20_Square(c);
end

L2_unstable_tau2 = sqrt(sum_tau2_0to20_Square)


tau2_70to80 = InputsFromScope.signals.values(70001:80000,2);
tau2_70to80_Square   = tau2_70to80.*tau2_70to80;

sum_tau2_70to80_Square = 0;

for c = 1:length(tau2_70to80_Square)
   sum_tau2_70to80_Square = sum_tau2_70to80_Square+tau2_70to80_Square(c);
end

L2_stable_tau2 = sqrt(sum_tau2_70to80_Square)