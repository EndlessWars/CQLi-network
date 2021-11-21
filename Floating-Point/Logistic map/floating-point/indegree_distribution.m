load 7indegree_distribution.txt;
load 8indegree_distribution.txt;
load 10indegree_distribution.txt;
load 11indegree_distribution.txt;
load 12indegree_distribution.txt;
load 13indegree_distribution.txt;
load 15indegree_distribution.txt;
load 16indegree_distribution.txt;
load 17indegree_distribution.txt;
load 18indegree_distribution.txt;
load 19indegree_distribution.txt;
load 20indegree_distribution.txt;

hold on;
plot(X7indegree_distribution(:,1)+1,X7indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','*','Color',[0 0 0],...
    'DisplayName','n = 7');
plot(X8indegree_distribution(:,1)+1,X8indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','o','Color',[1 0 0],...
    'DisplayName','n = 8');
plot(X10indegree_distribution(:,1)+1,X10indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','v','Color',[0 1 0],...
    'DisplayName','n = 10');
plot(X11indegree_distribution(:,1)+1,X11indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','^','Color',[0 0 1],...
    'DisplayName','n = 11');
plot(X12indegree_distribution(:,1)+1,X12indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','p','Color',[1 0 1],...
    'DisplayName','n = 12');
plot(X13indegree_distribution(:,1)+1,X13indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','h','Color',[0 1 1],...
    'DisplayName','n = 13');
plot(X15indegree_distribution(:,1)+1,X15indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','d','Color',[0.667 0.667 1],...
    'DisplayName','n = 15');
plot(X16indegree_distribution(:,1)+1,X16indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','s','Color',[0.5 0 0],...
    'DisplayName','n = 16');
plot(X17indegree_distribution(:,1)+1,X17indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','*','Color',[0 0 0],...
    'DisplayName','n = 17');
plot(X18indegree_distribution(:,1)+1,X18indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','o','Color',[1 0 0],...
    'DisplayName','n = 18');
plot(X19indegree_distribution(:,1)+1,X19indegree_distribution(:,2)./170755,...
    'MarkerSize',5,'Marker','v','Color',[0 1 0],...
    'DisplayName','n = 19');
plot(X20indegree_distribution(:,1)+1,X20indegree_distribution(:,2)./170754,...
    'MarkerSize',5,'Marker','^','Color',[0 0 1],...
    'DisplayName','n = 20');
legend('n = 7','n = 8','n = 10','n = 11',...
    'n = 12','n = 13','n = 15','n = 16',...
    'n = 17','n = 18','n = 19','n = 20',0);
xlabel('$k+1$','Margin',2,'FontAngle','italic','FontSize',14,...
    'FontName','Times New Roman','interpreter', 'Latex');
ylabel('ratio','Margin',2,'FontAngle','italic','FontSize',14,...
    'FontName','Times New Roman');

% export_fig('InDegreeDistribution_FloatingPoint.pdf','-transparent');