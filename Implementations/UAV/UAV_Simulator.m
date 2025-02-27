% Initialize variables
angle_change_start_time = 1;
initial_angle = 0;
final_angle = 1;
epsilon = 0.01;
Kp = 30.7142;
Ki = 2.480;
Kd = 1.10844;

simOut = sim('UAV');

% Determine control system performance
info = simOut.yout;

% Rise time
riseTime = info(info(:, 2) >= final_angle, :);
riseTime = riseTime(1,1) - angle_change_start_time;

% Settling time
settlingTime = NaN;
for i = 1:size(info, 1)
    if abs(info(i, 2) - final_angle) < (epsilon * final_angle)
        if isnan(settlingTime)
            settlingTime = info(i, 1);
        end
    else
        settlingTime = NaN;
    end
end

% Overshoot
overshoot = (max(info(:, 2)) - final_angle) / final_angle;

% Steady state error
steadyStateError = abs(info(end, 2) - final_angle) / final_angle;

% Ergebnisse auslesen
plot(simOut.yout(:, 2));
annotation('textbox', [0.15, 0.7, 0.4, 0.2], 'String', ...
    { ...
        ['Rise Time: ' num2str(riseTime) 's'], ...
        ['Settling Time: ' num2str(settlingTime) 's'], ...
        ['Maximum Overshoot: ' num2str(overshoot*100) '%'], ...
        ['Steady State Error: ' num2str(steadyStateError*100) '%']
    }, 'FontSize', 8, 'FitBoxToText', 'on');
