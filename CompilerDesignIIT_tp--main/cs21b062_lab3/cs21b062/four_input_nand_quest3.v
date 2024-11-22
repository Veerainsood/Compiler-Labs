module four_input_nand_quest3;

reg a1;
 reg b1;
reg c1;
reg d1;
wire w5;


wire w1;
wire w2;
wire w3;
wire w4;


nand(w1 , b1, a1);

nand(w2, d1, c1);

nand(w3, w1, w1);

nand (w4 , w2, w2);

nand (w5 , w4, w3);

initial begin 
a1 = 1'b0; b1 =1'b0; c1= 1'b0; d1 = 1'b0; #20
a1 = 1'b0; b1 =1'b0; c1= 1'b0; d1 = 1'b1; #20
a1 = 1'b0; b1 =1'b0; c1= 1'b1; d1 = 1'b0; #20
a1 = 1'b0; b1 =1'b0; c1= 1'b1; d1 = 1'b1; #20
a1 = 1'b0; b1 =1'b1; c1= 1'b0; d1 = 1'b0; #20
a1 = 1'b0; b1 =1'b1; c1= 1'b0; d1 = 1'b1; #20
a1 = 1'b0; b1 =1'b1; c1= 1'b1; d1 = 1'b0; #20
a1 = 1'b0; b1 =1'b1; c1= 1'b1; d1 = 1'b1; #20
a1 = 1'b1; b1 =1'b0; c1= 1'b0; d1 = 1'b0; #20
a1 = 1'b1; b1 =1'b0; c1= 1'b0; d1 = 1'b1; #20
a1 = 1'b1; b1 =1'b0; c1= 1'b1; d1 = 1'b0; #20
a1 = 1'b1; b1 =1'b0; c1= 1'b1; d1 = 1'b1; #20
a1 = 1'b1; b1 =1'b1; c1= 1'b0; d1 = 1'b0; #20
a1 = 1'b1; b1 =1'b1; c1= 1'b0; d1 = 1'b1; #20
a1 = 1'b1; b1 =1'b1; c1= 1'b1; d1 = 1'b0; #20
a1 = 1'b1; b1 =1'b1; c1= 1'b1; d1 = 1'b1; 

end 
endmodule 
