load DL_binary16.txt;
load DL_binary32.txt;
load DL_binary64.txt;

hold on;
plot(DL_binary16(:,1),DL_binary16(:,2),...
    'MarkerSize',5,'Marker','*','Color',[0 0 0],...
    'DisplayName','binary16');
plot(DL_binary32(:,1),DL_binary32(:,2),...
    'MarkerSize',5,'Marker','o','Color',[1 0 0],...
    'DisplayName','binary32');
plot(DL_binary64(:,1),DL_binary64(:,2),...
    'MarkerSize',5,'Marker','v','Color',[0 1 0],...
    'DisplayName','binary64');

legend('binary16','binary32','binary64',0);
xlabel('$L$','Margin',2,'FontAngle','italic','FontSize',14,...
    'FontName','Times New Roman','interpreter', 'Latex');
ylabel('frequency','Margin',2,'FontAngle','italic','FontSize',14,...
    'FontName','Times New Roman');

% export_fig('DL_binary.pdf','-transparent');

% xtick = get(gca,'XTick');
% str = cellstr(num2str(xtick(:),'%d'));
% format_ticks(gca,str);