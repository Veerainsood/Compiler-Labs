module xor_nor;
reg a1;
reg b1;

wire c1;
wire c2;
wire c3;
wire c4;
wire c5;



norgate ar( .x(a1), .y(a1), .z(c1));
norgate ar1( .x(b1), .y(b1), .z(c2));
norgate ar2( .x(c1), .y(c2), .z(c3));
norgate ar3( .x(a1), .y(b1), .z(c4));
norgate ar4( .x(c3), .y(c4), .z(c5));

initial begin
a1 = 1'b0; b1 = 1'b0; #20;
a1 = 1'b0; b1 = 1'b1; #20;
a1 = 1'b1; b1 = 1'b0; #20;
a1 = 1'b1; b1 = 1'b1; 

end 
endmodule 