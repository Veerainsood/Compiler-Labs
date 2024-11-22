module not_nand;
reg a1;


wire c1;



nandgate ar( .x(a1), .y(a1), .z(c1));


initial begin
a1 = 1'b0; #10
a1 = 1'b1; 

end 
endmodule
