module xor_nand;
reg a1;
reg b1;

wire c1;
wire c2;
wire c3;
wire c4;



nandgate ar( .x(a1), .y(b1), .z(c1));
nandgate ar1( .x(a1), .y(c1), .z(c2));
nandgate ar2( .x(b1), .y(c1), .z(c3));
nandgate ar3( .x(c2), .y(c3), .z(c4));

initial begin
a1 = 1'b0; b1 = 1'b0; #20;
a1 = 1'b0; b1 = 1'b1; #20;
a1 = 1'b1; b1 = 1'b0; #20;
a1 = 1'b1; b1 = 1'b1; 

end 
endmodule

