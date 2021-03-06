clc
clear all
close all

%-----------------------------------------------------------------%
load cumulative_indegree_distribution5.txt;
load cumulative_indegree_distribution6.txt;
load cumulative_indegree_distribution7.txt;
load cumulative_indegree_distribution8.txt;
load cumulative_indegree_distribution9.txt;
load cumulative_indegree_distribution10.txt;
load cumulative_indegree_distribution11.txt;
load cumulative_indegree_distribution12.txt;
load cumulative_indegree_distribution13.txt;
load cumulative_indegree_distribution14.txt;
load cumulative_indegree_distribution15.txt;
load cumulative_indegree_distribution16.txt;
load cumulative_indegree_distribution17.txt;
load cumulative_indegree_distribution18.txt;
load cumulative_indegree_distribution19.txt;
load cumulative_indegree_distribution20.txt;
new_cumu_ind5 = cumulative_indegree_distribution5(:,2)./(2^20+1);
new_cumu_ind6 = cumulative_indegree_distribution6(:,2)./(2^20+1);
new_cumu_ind7 = cumulative_indegree_distribution7(:,2)./(2^20+1);
new_cumu_ind8 = cumulative_indegree_distribution8(:,2)./(2^20+1);
new_cumu_ind9 = cumulative_indegree_distribution9(:,2)./(2^20+1);
new_cumu_ind10 = cumulative_indegree_distribution10(:,2)./(2^20+1);
new_cumu_ind11 = cumulative_indegree_distribution11(:,2)./(2^20+1);
new_cumu_ind12 = cumulative_indegree_distribution12(:,2)./(2^20+1);
new_cumu_ind13 = cumulative_indegree_distribution13(:,2)./(2^20+1);
new_cumu_ind14 = cumulative_indegree_distribution14(:,2)./(2^20+1);
new_cumu_ind15 = cumulative_indegree_distribution15(:,2)./(2^20+1);
new_cumu_ind16 = cumulative_indegree_distribution16(:,2)./(2^20+1);
new_cumu_ind17 = cumulative_indegree_distribution17(:,2)./(2^20+1);
new_cumu_ind18 = cumulative_indegree_distribution18(:,2)./(2^20+1);
new_cumu_ind19 = cumulative_indegree_distribution19(:,2)./(2^20+1);
new_cumu_ind20 = cumulative_indegree_distribution20(:,2)./(2^20+1);

hold on;
plot(cumulative_indegree_distribution5(:,1)+1,new_cumu_ind5,...
    'MarkerSize',5,'Marker','*','Color',[0 0 0],...
    'DisplayName','n = 5');
plot(cumulative_indegree_distribution6(:,1)+1,new_cumu_ind6,...
    'MarkerSize',5,'Marker','o','Color',[1 0 0],...
    'DisplayName','n = 6');
plot(cumulative_indegree_distribution7(:,1)+1,new_cumu_ind7,...
    'MarkerSize',5,'Marker','v','Color',[0 1 0],...
    'DisplayName','n = 7');
plot(cumulative_indegree_distribution8(:,1)+1,new_cumu_ind8,...
    'MarkerSize',5,'Marker','^','Color',[0 0 1],...
    'DisplayName','n = 8');
plot(cumulative_indegree_distribution9(:,1)+1,new_cumu_ind9,...
    'MarkerSize',5,'Marker','p','Color',[1 0 1],...
    'DisplayName','n = 9');
plot(cumulative_indegree_distribution10(:,1)+1,new_cumu_ind10,...
    'MarkerSize',5,'Marker','h','Color',[0 1 1],...
    'DisplayName','n = 10');
plot(cumulative_indegree_distribution11(:,1)+1,new_cumu_ind11,...
    'MarkerSize',5,'Marker','d','Color',[0.667 0.667 1],...
    'DisplayName','n = 11');
plot(cumulative_indegree_distribution12(:,1)+1,new_cumu_ind12,...
    'MarkerSize',5,'Marker','s','Color',[0.5 0 0],...
    'DisplayName','n = 12');
plot(cumulative_indegree_distribution13(:,1)+1,new_cumu_ind13,...
    'MarkerSize',5,'Marker','*','Color',[0 0 0],...
    'DisplayName','n = 13');
plot(cumulative_indegree_distribution14(:,1)+1,new_cumu_ind14,...
    'MarkerSize',5,'Marker','o','Color',[1 0 0],...
    'DisplayName','n = 14');
plot(cumulative_indegree_distribution15(:,1)+1,new_cumu_ind15,...
    'MarkerSize',5,'Marker','v','Color',[0 1 0],...
    'DisplayName','n = 15');
plot(cumulative_indegree_distribution16(:,1)+1,new_cumu_ind16,...
    'MarkerSize',5,'Marker','^','Color',[0 0 1],...
    'DisplayName','n = 16');
plot(cumulative_indegree_distribution17(:,1)+1,new_cumu_ind17,...
    'MarkerSize',5,'Marker','p','Color',[1 0 1],...
    'DisplayName','n = 17');
plot(cumulative_indegree_distribution18(:,1)+1,new_cumu_ind18,...
    'MarkerSize',5,'Marker','h','Color',[0 1 1],...
    'DisplayName','n = 18');
plot(cumulative_indegree_distribution19(:,1)+1,new_cumu_ind19,...
    'MarkerSize',5,'Marker','d','Color',[0.667 0.667 1],...
    'DisplayName','n = 19');
plot(cumulative_indegree_distribution20(:,1)+1,new_cumu_ind20,...
    'MarkerSize',5,'Marker','s','Color',[0.5 0 0],...
    'DisplayName','n = 20');
legend('n = 5','n = 6','n = 7','n = 8',...
    'n = 9','n = 10','n = 11','n = 12',...
    'n = 13','n = 14','n = 15','n = 16',...
    'n = 17','n = 18','n = 19','n = 20',0);
xlabel('$k+1$','VerticalAlignment','top','Interpreter','latex','FontSize',14);
ylabel('$ratio$','Interpreter','latex','FontSize',14);


hold on;
x = logspace(1.2,2.4);
y = 4*(4*power(x,-2)/(121/32)^2);
loglog(x,y,'b-');

figure1=gcf;

annotation(figure1,'textbox',...
    [0.36495180023229 0.323571831443498 0.213890969019972 0.0771428557804653],...
    'Interpreter','latex',...
    'String','$P(k)= \frac{4}{\mu^2k^2}$',...
    'FontSize',14,...
    'FitBoxToText','off',...
    'EdgeColor',[1 1 1]);

% export_fig('CumulativeInDegreeDistribution_u121_n_5_20.pdf','-transparent');
%-----------------------------------------------------------------%

