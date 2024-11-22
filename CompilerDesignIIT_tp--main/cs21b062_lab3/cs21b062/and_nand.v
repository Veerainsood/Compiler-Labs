module and_nand;
reg a1;
reg b1;

wire c1;
wire c2;


nandgate ar( .x(a1), .y(b1), .z(c1));
nandgate ar1( .x(c1), .y(c1), .z(c2));

initial begin
a1 = 1'b0; b1 = 1'b0; #20;
a1 = 1'b0; b1 = 1'b1; #20;
a1 = 1'b1; b1 = 1'b0; #20;
a1 = 1'b1; b1 = 1'b1; 

end 
endmodule


