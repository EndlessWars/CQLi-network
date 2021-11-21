load 8bit_precision_value_index_odd_add.txt;
load 7bit_precision_value_index_odd_add.txt;
load 8bit_precision_value_index_even.txt;
load 7bit_precision_value_index_even.txt;

diff_odd = abs(X8bit_precision_value_index_odd_add(:,2)-2*...
    X7bit_precision_value_index_odd_add(:,2));
diff_even = X8bit_precision_value_index_even(:,2)-2*...
    X7bit_precision_value_index_even(:,2);

up_bound = zeros(128,1);
f_n = zeros(128,1);
dec_f = zeros(128,1);
fid = fopen('upper_bound_add.txt','w','native');
for i = 0:127
    f_n(i+1) = (121/32)*(i/128)*(1-i/128);
    dec_f(i+1) = f_n(i+1)*128-floor(f_n(i+1)*128);
    if dec_f(i+1)>=0.25 && dec_f(i+1)<0.75
        up_bound(i+1) = abs(round((121/128)*(4-(1+4*i)/64)))+2;
    else
        up_bound(i+1) = abs(round((121/128)*(4-(1+4*i)/64)))+1;
    end
    fprintf(fid,'%i %i \r\n',i,up_bound(i+1));
end
fclose(fid);

hold on;
plot([0:127],diff_odd,...
    'MarkerSize',5,'Marker','s','Color',[0 0 1],...
    'DisplayName','|F_{n+1}(2i+1)-2F_{n}(i)|');
plot([0:128],diff_even,...
    'MarkerSize',5,'Marker','d','Color',[1 0 1],...
    'DisplayName','F_{n+1}(2i)-2F_{n}(i)');
plot([0:127],up_bound,...
    'MarkerSize',5,'Marker','o','Color',[1 0 0],...
    'DisplayName','upper bound');

legend('|F_{n+1}(2i+1)-2F_{n}(i)|','F_{n+1}(2i)-2F_{n}(i)','upper bound',0);
% index = legend('|F_{n+1}(2i+1)-2F_{n}(i)|','F_{n+1}(2i)-2F_{n}(i)','upper bound',0);
% set(index,'FontAngle','italic','TextColor',[.3,.2,.1]);
xlabel('$i$','Margin',2,'FontAngle','italic','FontSize',14,...
    'FontName','Times New Roman','interpreter', 'Latex');
% ylabel('$upper bound$','Margin',2,'FontAngle','italic','FontSize',14,...
%     'FontName','Times New Roman','interpreter', 'Latex');

% export_fig('upper_bound_add.pdf','-transparent');
