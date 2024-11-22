module tb_notgate();

reg w1;

wire c1;
notgate myand ( w1,c1);
initial 
 begin
#5
w1<= 1'b0;


$monitor("time = %d, w1= %d, c1 = %d", $time, w1,c1);
#5

w1<=1'b1;
$monitor("time = %d, w1= %d, c1 = %d", $time, w1,c1);


end 
endmodule
  