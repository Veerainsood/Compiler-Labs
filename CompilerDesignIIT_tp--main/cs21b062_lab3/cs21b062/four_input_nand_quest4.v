module four_input_nand_quest4;


reg a1;
reg b1;
reg c1;
reg d1;

wire w1;
wire w2;
wire w3;
wire w4;
wire w5;

nandgate ar(.x(a1) , .y(b1), .z(w1));

nandgate ar1(.x(c1) , .y(d1), .z(w2));

nandgate ar2(.x(w1) , .y(w1), .z(w3));

nandgate ar3(.x(w2) , .y(w2), .z(w4));

nandgate ar4(.x(w3) , .y(w4), .z(w5));

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

