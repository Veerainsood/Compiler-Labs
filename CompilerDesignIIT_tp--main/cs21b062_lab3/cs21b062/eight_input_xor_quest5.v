module eight_input_xor_quest5;

reg a1;
 reg b1;
reg c1;
reg d1;
reg a2;
 reg b2;
reg c2;
reg d2;




wire w5;


wire w1;
wire w2;
wire w3;
wire w4;
wire w6;
wire w7;



xor ar(w1 , b1, a1);

xor ar1(w2, c1, d1);

xor ar2 (w3, a2, b2);
xor ar3(w4, c2, d2);
xor ar4 (w5, w1, w2);
xor ar5 (w6, w3, w4);
xor ar6 (w7, w5, w6);



initial begin 
a1 = 1'b0; b1 =1'b0; c1= 1'b0; d1 = 1'b0; #20
 a2 = 1'b0; b2 =1'b0; c2= 1'b0; d2 = 1'b0;#20 
a1 = 1'b0; b1 =1'b0; c1= 1'b0; d1 = 1'b1; #20
  a2 = 1'b0; b2 =1'b0; c2= 1'b0; d2 = 1'b1; #20
a1 = 1'b0; b1 =1'b0; c1= 1'b1; d1 = 1'b0; #20   
a2 = 1'b0; b2 =1'b0; c2= 1'b1; d2 = 1'b0;


end 
endmodule 