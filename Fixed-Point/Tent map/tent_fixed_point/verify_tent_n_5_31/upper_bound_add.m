load 6bit_precision_value_index_odd_add.txt;
load 5bit_precision_value_index_odd_add.txt;
load 6bit_precision_value_index_even.txt;
load 5bit_precision_value_index_even.txt;

diff_odd = abs(X6bit_precision_value_index_odd_add(:,2)-2*...
    X5bit_precision_value_index_odd_add(:,2));
diff_even = X6bit_precision_value_index_even(:,2)-2*...
    X5bit_precision_value_index_even(:,2);

up_bound = zeros(32,1);
f_n = zeros(32,1);
dec_f = zeros(32,1);
fid = fopen('upper_bound_add.txt','w','native');
for i = 0:31
    f_n(i+1) = (31/32)*(1-2*abs((i/32)-0.5));
    dec_f(i+1) = f_n(i+1)*32-floor(f_n(i+1)*32);
    if dec_f(i+1)>=0.25 && dec_f(i+1)<0.75
        up_bound(i+1) = abs(round(31/16))+2;
    else
        up_bound(i+1) = abs(round(31/16))+1;
    end
    fprintf(fid,'%i %i \r\n',i,up_bound(i+1));
end
fclose(fid);

hold on;
plot([0:32],diff_even,...
    'MarkerSize',5,'Marker','d','Color',[1 0 1],...
    'DisplayName','F_{n+1}(2i)-2F_{n}(i)');
plot([0:31],up_bound,...
    'MarkerSize',5,'Marker','o','Color',[1 0 0],...
    'DisplayName','upper bound');
plot([0:31],diff_odd,...
    'MarkerSize',5,'Marker','s','Color',[0 0 1],...
    'DisplayName','|F_{n+1}(2i+1)-2F_{n}(i)|');

legend('F_{n+1}(2i)-2F_{n}(i)','upper bound','|F_{n+1}(2i+1)-2F_{n}(i)|',0);
% index = legend('F_{n+1}(2i)-2F_{n}(i)','upper bound','|F_{n+1}(2i+1)-2F_{n}(i)|',0);
% set(index,'FontAngle','italic','TextColor',[.3,.2,.1]);
xlabel('$i$','Margin',2,'FontAngle','italic','FontSize',14,...
    'FontName','Times New Roman','interpreter', 'Latex');
% ylabel('$upper bound$','Margin',2,'FontAngle','italic','FontSize',14,...
%     'FontName','Times New Roman','interpreter', 'Latex');

% export_fig('upper_bound_add_tent.pdf','-transparent');
