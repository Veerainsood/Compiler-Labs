module tb_xorgate();

reg w1,w2;

wire c1;
xorgate xor1 ( w1, w2,c1);
initial 
 begin
#5
w1<= 1'b0;
w2<=1'b0;

$monitor("time = %d, w1= %d, w2 = %d , c1 = %d", $time, w1,w2,c1);
#5
w1<= 1'b0;
w2<=1'b1;
$monitor("time = %d, w1= %d, w2 = %d , c1 = %d", $time, w1,w2,c1);
#5
w1<= 1'b1;
w2<=1'b0;
$monitor("time = %d, w1= %d, w2 = %d , c1 = %d", $time, w1,w2,c1);
#5
w1<= 1'b1;
w2<=1'b1;
$monitor("time = %d, w1= %d, w2 = %d , c1 = %d", $time, w1,w2,c1);


end 
endmodule
  