module quest6_b;


reg a1;
reg b1;



wire w1;
wire w2;
wire w3;


andgate ar( .z(w1), .y(b1),.x(a1));
orgate ar1( .z(w2), .x(w1), .y(a1));

andgate ar2(.z(w3),.x(a1), .y(b1))
;
initial begin
a1 = 1'b0; b1 = 1'b0; #20;
a1 = 1'b0; b1 = 1'b1; #20;
a1 = 1'b1; b1 = 1'b0; #20;
a1 = 1'b1; b1 = 1'b1; 

end 
endmodule 