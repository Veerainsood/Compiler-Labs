module tb_quest2();

reg w1,w2;

wire c1;
wire c2;
wire c3;
and_nor myand_nor (.x( w1), .y(w2),.z(c1));
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
  